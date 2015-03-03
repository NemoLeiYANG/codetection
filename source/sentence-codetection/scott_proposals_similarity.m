function [boxes_w_fscore, gscore] = ...
    scott_proposals_similarity(top_k, ssize, frames, positions,alpha,beta)
%inputs: top_k, box_size same as Haonan's code
%        frames: h*w*3*num_frames matrix of images
%        positions: num_frames*3 matrix of [x y theta]
%        alpha: scalar weight for proposal score
%        beta: scalar weight for single-frame distance score
%outputs: boxes_w_fscore: top_k*5*num_frames, each row of top_k*5 is (x1,y1,x2,y2,f) 
%                       (f is weighted sum of different proposal scores,
%                       like Hanoan's prop score, my gaussian distance,
%                       others... (maybe distance from center of frame,
%                       optical flow (???), Jeff's pb/region contour(???)
%         gscore: top_k*top_k*(num_frames-1), similarity between proposals in
%                   adjacent frames (similarity score is weighted sum of
%                   different similarity measures, like Haonan's simi,
%                   others...
%                   gscore(10,15,1): the similarity between the 10th box in 
%                                  the first frame and the 15th box in the
%                                  second frame, the higher the better

% add paths
%addpath(pwd);
addpath(genpath('piotr-toolbox'));
addpath(genpath('vlfeat/toolbox'));
addpath(genpath('forests_edges_boxes'));
run('vlfeat/toolbox/vl_setup');

% enable parfor
pools = matlabpool('size');
cpus = feature('numCores');
if pools ~= (cpus - 1)
    if pools > 0
        matlabpool('close');
    end
    matlabpool('open', cpus - 1);
end

%experiment parameters--shouldn't change
gaussparam = [.25,0]; %setting sigma=.25,mu=0
cam_offset = [-0.03 0.16 -0.2]; %estimated measurement, in m
boundary = [-3 3.05 -2.62 3.93]; %[x1 x2 y1 y2] in m
%camera calibration data
cam_k = [7.2434508362823397e+02 0.0 3.1232994017160644e+02;...
        0.0 7.2412307134397406e+02 2.0310961045807585e+02;...
        0.0 0.0 1.0]; %not sure of units here

% compute
[h, w, d, T] = size(frames);
bboxes = zeros(top_k, 5, T);
simi = -inf(top_k, top_k, T-1); %zeros(top_k, top_k, T-1);
temp_boxes{T} = [];  %cell array for holding boxes used in calculations

%tic;
for t = 1:T
    img = frames(:,:,:,t);
    pose = positions(t,:);
    
    %unary score(s)
    bbs = edgeBoxesOut(img, top_k, 5);
    new_boxes = zeros(top_k, 7);
    nb_idx = 1;
    for i = 1:top_k
        bc_point = [(bbs(i,1)+(bbs(i,3)/2)) (bbs(i,2)+bbs(i,4))];
        %assume box is on ground (height = 0)
        loc = pixel_and_height_to_world(bc_point, 0, cam_k, pose, cam_offset);
        if ((~isnan(loc(1))) &&... %reject boxes out of bounds
            (loc(1) >= boundary(1)) &&...
            (loc(1) <= boundary(2)) &&...
            (loc(2) >= boundary(3)) &&...
            (loc(2) <= boundary(4)))
            new_boxes(nb_idx,:) = [bbs(i,1:4),loc(1),loc(2),bbs(i,5)];
            nb_idx = nb_idx + 1;
        end
    end %for i
    num_nboxes = nb_idx-1;
    new_boxes = new_boxes(1:num_nboxes,:);
    
    %could compute world width of box here easily...not sure how to compute
    %height
    
    
    %redo score of each box based on gaussian with distance between boxes
    newscores = zeros(num_nboxes,1);
    X = new_boxes(:,5:6);
    D = pdist2(X,X,'euclidean'); %defaults to squared euclidean distance--good enough?
        %%using pure euclidean distance appears to give better results...
    for i = 1:num_nboxes
        for j = 1:num_nboxes
            if (j ~= i)
                newscores(i) = newscores(i) + gaussmf(D(i,j),gaussparam);
            end %if
        end %for j
    end %for i
    % newscores = newscores/(num_nboxes-1); %scale to number of boxes compared against
    % %%%NOT SURE THIS HELPS AT ALL
    newscores = newscores/top_k; %try scaling to total number of boxes at start
    new_boxes2 = [new_boxes newscores]; %Now each row is [x y w h xloc yloc propscore myscore]
    temp_box = zeros(num_nboxes,7);
    temp_box(:,1:6) = new_boxes(:,1:6);
    temp_box(:,7) = new_boxes2(:,7)*alpha + new_boxes2(:,8)*beta;
        %temp_box is [x y w h xloc yloc combinedscore]
    temp_boxes{t} = temp_box;
    
%     %converting from [x y w h] to [x1 y1 x2 y2]
%     bbs(:,3) = bbs(:,3) + bbs(:,1) - 1;
%     bbs(:,4) = bbs(:,4) + bbs(:,2) - 1;
%     
%     %storing in final output variable -- MAYBE MOVE THIS LATER????
%     bboxes(:,:,t) = bbs;

    %temp_bboxes = zeros(top_k,5);
    %temp_bboxes = ones(top_k,5);
    temp_bboxes = zeros(num_nboxes,5);
    %converting from [x y w h] to [x1 y1 x2 y2]
    temp_bboxes(:,1:2) = temp_box(:,1:2);
    temp_bboxes(:,3) = temp_box(:,3) + temp_box(:,1) - 1;
    temp_bboxes(:,4) = temp_box(:,4) + temp_box(:,2) - 1;
    temp_bboxes(1:num_nboxes,5) = temp_box(:,7);
    
    %t
    %num_nboxes
    
    
    %binary score(s)
    if (num_nboxes > 0)
        hists{num_nboxes} = []; %declare new cell array every time
        parfor i = 1:num_nboxes %top_k
            %i
            bi = temp_bboxes(i,:); %bboxes(i,:,t);
            %size(img(bi(2):bi(4),bi(1):bi(3),:));
            %if (bi(1) > 0)
            hists{i} = phow_hist(img(bi(2):bi(4),bi(1):bi(3),:), ssize);
            %end
        end %parfor i
        hist = cat(2, hists{:});
        clear hists; %remove this variable so it's created new each iteration
        hist = hist';
        
        
        if t > 1
            %nboxes_prev
            %fprintf('size of hist_prev, hist');
            %size(hist_prev)
            %size(hist)
            simi(1:nboxes_prev,1:num_nboxes,t-1) = -pdist2(hist_prev, hist, 'chisq');
            %foo = -pdist2(hist_prev, hist, 'chisq');
            %foo
            %fprintf('size of foo');
            %size(foo)
        end %if
        hist_prev = hist;
        nboxes_prev = num_nboxes;
    end %if
end %for t

%probably need another loop through T here to do the between-frames
%distance measure for the box locations
for t = 1:T
    curr_box = temp_boxes{t};
    num_curr_boxes = size(curr_box,1);
    newscores = zeros(num_curr_boxes,1);
    X1 = curr_box(:,5:6);
    for u = 1:T
        if (u ~= t)
            other_box = temp_boxes{u};
            num_other_boxes = size(other_box,1);
            X2 = other_box(:,5:6);
            D = pdist2(X1,X2,'euclidean');
            for i = 1:num_curr_boxes
                for j = 1:num_other_boxes
                    newscores(i) = newscores(i) +...
                        curr_box(i,7)*gaussmf(D(i,j),gaussparam);
                end %for j
            end %for i
        end %if
    end %for u
    bbs = zeros(num_curr_boxes,5);
    bbs(:,1:4) = curr_box(:,1:4);
    bbs(:,5) = newscores/(T*top_k);
    
    %converting from [x y w h] to [x1 y1 x2 y2]
    bbs(:,3) = bbs(:,3) + bbs(:,1) - 1;
    bbs(:,4) = bbs(:,4) + bbs(:,2) - 1;
    
    %storing in final output variable
    bboxes(1:num_curr_boxes,:,t) = bbs;
end %for t


%tt = toc;
%fid = fopen('/tmp/output', 'w');
%fprintf(fid, '%f', tt);
%fclose(fid);    

%set output
boxes_w_fscore = bboxes;
gscore = simi;
end %function scott_proposals_similarity

%Haonan's helper functions
function hist = phow_hist(im, ssize)
load('phow-model/vocab.mat');
model.vocab = vocab;
model.phowOpts = {'Step', 3};
model.numSpatialX = [2, 4];
model.numSpatialY = [2, 4];
model.quantizer = 'kdtree';
model.kdtree = vl_kdtreebuild(vocab);
hist = getImageDescriptor(model, im, ssize);
end

function im = standarizeImage(im, ssize)
im = im2single(im) ;
scaling = max([ssize/size(im,1) ssize/size(im,2)]);
newsize = round([size(im,1) size(im,2)]*scaling);
im = imresize(im, newsize);
end

function hist = getImageDescriptor(model, im, ssize)
im = standarizeImage(im, ssize) ;
width = size(im,2) ;
height = size(im,1) ;
numWords = size(model.vocab, 2) ;
% get PHOW features
[frames, descrs] = vl_phow(im, model.phowOpts{:}) ;
% quantize local descriptors into visual words
switch model.quantizer
  case 'vq'
    [drop, binsa] = min(vl_alldist(model.vocab, single(descrs)), [], 1) ;
  case 'kdtree'
    binsa = double(vl_kdtreequery(model.kdtree, model.vocab, ...
                                  single(descrs), ...
                                  'MaxComparisons', 50)) ;
end
for i = 1:length(model.numSpatialX)
    binsx = vl_binsearch(linspace(1,width,model.numSpatialX(i)+1), frames(1,:)) ;
    binsy = vl_binsearch(linspace(1,height,model.numSpatialY(i)+1), frames(2,:)) ;
    % combined quantization
    bins = sub2ind([model.numSpatialY(i), model.numSpatialX(i), numWords], ...
                   binsy,binsx,binsa) ;
    hist = zeros(model.numSpatialY(i) * model.numSpatialX(i) * numWords, 1) ;
    hist = vl_binsum(hist, ones(size(bins)), bins) ;
    hists{i} = single(hist / sum(hist)) ;
end
hist = cat(1,hists{:}) ;
hist = hist / sum(hist) ;
end

%my helper functions
function rotmat = rotation3dx(a) %roll
    rotmat = [1,0,0,0;...
              0,cos(a),-sin(a),0;...
              0,sin(a),cos(a),0;...
              0,0,0,1];
end

function rotmat = rotation3dy(a) %pitch
    rotmat = [cos(a),0,sin(a),0;...
              0,1,0,0;...
              -sin(a),0,cos(a),0;...
              0,0,0,1];
end

function rotmat = rotation3dz(a) %yaw
    rotmat = [cos(a),-sin(a),0,0;...
              sin(a),cos(a),0,0;...
              0,0,1,0;...
              0,0,0,1];
end

function transmat = translation3d(x,y,z)
    transmat = [1,0,0,x;...
                0,1,0,y;...
                0,0,1,z;...
                0,0,0,1];
end

function trans = make_transform_3d(theta,phi,psi,x,y,z)
    transmat = translation3d(x,y,z);
    zrot = rotation3dz(theta);
    yrot = rotation3dy(phi);
    xrot = rotation3dx(psi);
    trans = transmat * zrot * yrot *xrot;
end

function world_to_cam = robot_pose_to_world__camera_txf(pose, cam_offset)
    x = cam_offset(1); y = cam_offset(2); z = cam_offset(3);
    trans1 = translation3d(x,y,z);
    trans2 = make_transform_3d((pose(3) - (pi/2)),0,-pi/2,...
                               pose(1), pose(2), 0);
    world_to_cam = trans1/trans2;                               
end 

function h = point_to_homogeneous(p)
    h = horzcat(p,1);
end

function p = homogeneous_to_point(h)
    p = h(1:(length(h)-1));
end

function p = transform_point_3d(mat, point)
    h = point_to_homogeneous(point);
    temp = mat*h';
    p = homogeneous_to_point(temp);
end

function point = pixel_and_height_to_world(pix, height, cam_k, pose, cam_offset)
    world_to_cam = robot_pose_to_world__camera_txf(pose,cam_offset);
    cam_world = transform_point_3d(inv(world_to_cam),[0,0,0]);
    fx = cam_k(1,1); fy = cam_k(2,2);
    cx = cam_k(1,3); cy = cam_k(2,3);
    px = (pix(1)-cx)/fx;
    py = (pix(2)-cy)/fy;
    pixel_world = transform_point_3d(inv(world_to_cam),[px,py,1]);
    dxyz = pixel_world - cam_world;
    if (dxyz(3) > 0)
        point = [NaN, NaN];
    else
        l = (height - cam_world(3))/dxyz(3);
        point = cam_world + dxyz*l;
    end
end 