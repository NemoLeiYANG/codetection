function [boxes_w_fscore, gscore,d_score,w_score,s_score] = ...
    scott_proposals_similarity2(top_k, ssize, frames, positions)%,alpha,beta)
%inputs: top_k, ssize same as Haonan's code
%        frames: h*w*3*num_frames matrix of images
%        positions: num_frames*3 matrix of [x y theta]
%        alpha: scalar weight for proposal score
%        beta: scalar weight for single-frame distance score
%outputs: boxes_w_fscore: top_k*8*num_frames, each row of top_k*8 is (x1,y1,x2,y2,f,xloc,yloc,wwidth) 
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
addpath(genpath('MCG-PreTrained'));

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
gaussparam1 = [.25,0]; %setting sigma=.25,mu=0 for distance
gaussparam2 = [.1,0]; %setting sigma=.1,mu=0 for width difference
cam_offset = [-0.03 0.16 -0.2]; %estimated measurement, in m
world_boundary = [-3 3.05 -2.62 3.93]; %[x1 x2 y1 y2] in m
distance_threshold = 0.5; %distance threshold for similarity score--in m
%camera calibration data
cam_k = [7.2434508362823397e+02 0.0 3.1232994017160644e+02;...
        0.0 7.2412307134397406e+02 2.0310961045807585e+02;...
        0.0 0.0 1.0]; %not sure of units here

% compute
[h, w, d, T] = size(frames);
bboxes = zeros(top_k, 8, T); %each row: [x y w h score xloc yloc wwidth]
simi = zeros(top_k, top_k, T-1);
%temp_boxes{T} = [];  %cell array for holding boxes used in calculations

%first get boxes for all frames
% outboxes = zeros(top_k,5,T);
% parfor t = 1:T
%     img = frames(:,:,:,t);
%     outboxes(:,:,t) = MCGboxes(img,top_k);
% end %parfor
% fprintf('After parfor loop to get all boxes\n');

parfor t = 1:T
%     display(t)
    img = frames(:,:,:,t);
    pose = positions(t,:);
    bbs = MCGboxes(img,top_k);
    %bbs = outboxes(:,:,t);
    %now do re-scoring of proposal scores based on frames
    new_boxes = zeros(top_k, 8);
    new_boxes(:,1:5) = bbs;
    boundary = world_boundary;
    for i = 1:top_k
%         display(i)
        bc_point = [(bbs(i,1)+(bbs(i,3)/2)) (bbs(i,2)+bbs(i,4))];
        %assume box is on ground (height = 0)
        [loc locflag] = pixel_and_height_to_world(bc_point, 0, cam_k, pose, cam_offset);
        %PUT LOCATION INTO BOXES MATRIX FOR LATER USE
        new_boxes(i,6) = loc(1); new_boxes(i,7) = loc(2);
        %FIND WORLD WIDTH OF BOX AND SAVE
        lcorner = [bbs(i,1) (bbs(i,2)+bbs(i,4))];
        rcorner = [(bbs(i,1)+bbs(i,3)) (bbs(i,2)+bbs(i,4))];
        lcloc = pixel_and_height_to_world(lcorner,0,cam_k,pose,cam_offset);
        rcloc = pixel_and_height_to_world(rcorner,0,cam_k,pose,cam_offset);
%         display(lcloc); display(rcloc);
        wwidth = pdist([lcloc'; rcloc'],'euclidean');
%         display(wwidth)
        new_boxes(i,8) = wwidth;
        %REDO UNARY SCORES HERE
        if (locflag == 0) %box is behind camera
            penalty = -10; %ARBITRARY penalty factor here--might need to adjust
            new_boxes(i,5) = new_boxes(i,5)*exp(penalty);
            continue; %done with this box
        end %if locflag
        
        if (loc(1) > boundary(2))
            xpenalty = boundary(2) - loc(1);
        elseif (loc(1) < boundary(1))
            xpenalty = loc(1) - boundary(1);
        else
            xpenalty = 0;
        end %if loc(1)
        
        if (loc(2) > boundary(4))
            ypenalty = boundary(4) - loc(2);
        elseif (loc(2) < boundary(3))
            ypenalty = loc(2) - boundary(3);
        else
            ypenalty = 0;
        end %if loc(2)
        new_boxes(i,5) = new_boxes(i,5)*exp(xpenalty)*exp(ypenalty);
    end %for i
    bboxes(:,:,t) = new_boxes;
%%I THINK UNARY SCORES COMPLETE HERE--TRUE?    
end %parfor

% fprintf('Unary scores computed\n');

%converting from [x y w h] to [x1 y1 x2 y2]
bboxes(:,3,:) = bboxes(:,3,:) + bboxes(:,1,:) - 1;
bboxes(:,4,:) = bboxes(:,4,:) + bboxes(:,2,:) - 1;

%now compute binary scores:
% 1) world distance between boxes (all boxes all frames)
% 2) difference in world box width (all boxes all frames)
% 3) visual similarity (Haonan's method) between boxes that are closer
% together than some threshold

%first vectorize world xy and width measures for all boxes
worldX = bboxes(:,6,:);
worldY = bboxes(:,7,:);
worldW = bboxes(:,8,:);
worldX = reshape(worldX, T*top_k, 1);
worldY = reshape(worldY, T*top_k, 1);
worldXY = [worldX worldY];
worldW = reshape(worldW, T*top_k, 1);

%now compute distances -- using euclidean might be slow, but simpler than
%using squared euclidean distance as input to gaussian kernel
worldDist = real(pdist2(worldXY,worldXY,'euclidean')); 
worldWdiff = real(pdist2(worldW,worldW,'euclidean')); 
% worldDist = pdist2(worldXY,worldXY); 
% worldWdiff = pdist2(worldW,worldW); 

%use gaussian kernel to scale to (0,1), higher=better
d_score = gaussmf(worldDist,gaussparam1);
w_score = gaussmf(worldWdiff,gaussparam2);

%now zero out scores for boxes in same frame
blankscore = zeros(top_k);
for i = 1:T
    start = (i-1)*top_k + 1; stop = i*top_k;
    d_score(start:stop,start:stop) = blankscore;
    w_score(start:stop,start:stop) = blankscore;
end % for i
%d_score and w_score complete 

%now do visual similarity (s_score) on boxes that are within some distance
%threshold of each other
s_score = zeros(T*top_k);
for i = 1:T*top_k
    for j = (i+1):T*top_k %can do this b/c matrix will be symmetric
        if ((worldDist(i,j) < distance_threshold) && ...
            (w_score(i,j) ~= 0)) %second condition ensures that we don't do
                                 % similarity on boxes in same frame
            frame_idx1 = fix((i-1)/top_k) + 1;        
            frame_idx2 = fix((j-1)/top_k) + 1;
            img1 = frames(:,:,:,frame_idx1);
            img2 = frames(:,:,:,frame_idx2);
            box_idx1 = mod(i,top_k);
            if (box_idx1 == 0)
                box_idx1 = top_k;
            end %if
            box_idx2 = mod(j,top_k);
            if (box_idx2 == 0)
                box_idx2 = top_k;
            end %if
            bx1 = bboxes(box_idx1,1:4,frame_idx1);
            bx2 = bboxes(box_idx2,1:4,frame_idx2);
            hist1 = phow_hist(img1(bx1(2):bx1(4),bx1(1):bx1(3),:),ssize);
            hist2 = phow_hist(img2(bx2(2):bx2(4),bx2(1):bx2(3),:),ssize);
            hist1 = hist1'; hist2 = hist2';
            tempscore = 1-pdist2(hist1,hist2,'chisq');
            s_score(i,j) = tempscore;
            s_score(j,i) = tempscore; %b/c matrix is symmetric
        end %if
    end %for j
end %for i

% for t = 1:T
%     img = frames(:,:,:,t);
%     %binary score(s)
%     parfor i = 1:top_k
%         bi = bboxes(i,:,t);
% %         display(bi)
%         hists{i} = phow_hist(img(bi(2):bi(4),bi(1):bi(3),:), ssize);
%     end %parfor i
%     hist = cat(2, hists{:});
%     hist = hist';
% 
%     if t > 1
%         simi(:,:,t-1) = 1-pdist2(hist_prev, hist, 'chisq');
%         %scaled between 0 and 1, higer is better
%     end %if
%     hist_prev = hist;
% end %for t

%%NEED TO ADD UNARY AND BINARY SCORES FOR DUMMY BOXES

% %probably need another loop through T here to do the between-frames
% %distance measure for the box locations
% for t = 1:T
%     curr_box = temp_boxes{t};
%     num_curr_boxes = size(curr_box,1);
%     newscores = zeros(num_curr_boxes,1);
%     X1 = curr_box(:,5:6);
%     for u = 1:T
%         if (u ~= t)
%             other_box = temp_boxes{u};
%             num_other_boxes = size(other_box,1);
%             X2 = other_box(:,5:6);
%             D = pdist2(X1,X2,'euclidean');
%             for i = 1:num_curr_boxes
%                 for j = 1:num_other_boxes
%                     newscores(i) = newscores(i) +...
%                         curr_box(i,7)*gaussmf(D(i,j),gaussparam);
%                 end %for j
%             end %for i
%         end %if
%     end %for u
%     bbs = zeros(num_curr_boxes,5);
%     bbs(:,1:4) = curr_box(:,1:4);
%     bbs(:,5) = newscores;
%     
%     %converting from [x y w h] to [x1 y1 x2 y2]
%     bbs(:,3) = bbs(:,3) + bbs(:,1) - 1;
%     bbs(:,4) = bbs(:,4) + bbs(:,2) - 1;
%     
%     %storing in final output variable
%     bboxes(1:num_curr_boxes,:,t) = bbs;
% end %for t


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

function [point valid] = pixel_and_height_to_world(pix, height, cam_k, pose, cam_offset)
    world_to_cam = robot_pose_to_world__camera_txf(pose,cam_offset);
    cam_world = transform_point_3d(inv(world_to_cam),[0,0,0]);
    fx = cam_k(1,1); fy = cam_k(2,2);
    cx = cam_k(1,3); cy = cam_k(2,3);
    px = (pix(1)-cx)/fx;
    py = (pix(2)-cy)/fy;
    pixel_world = transform_point_3d(inv(world_to_cam),[px,py,1]);
    dxyz = pixel_world - cam_world;
    if (dxyz(3) > 0)
        %point = [NaN, NaN];
        valid = false;
    else
        valid = true;
    end
    l = (height - cam_world(3))/dxyz(3);
    point = cam_world + dxyz*l;
    %end
end 