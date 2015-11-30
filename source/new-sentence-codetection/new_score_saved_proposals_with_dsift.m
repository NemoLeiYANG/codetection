function [bboxes,phists] = ...
    new_score_saved_proposals_with_dsift(proposal_boxes,top_k,ssize,frames,positions,min_x,max_x,min_y,max_y,discount_factor)
%inputs: proposal_boxes: Nx5xnum_frames array of saved proposals; each row is [x y w h score]
%        top_k: number of proposals to generate in each frame
%        ssize: the size to which each proposal is rescaled to (for
%               phow_hist); ssize should be 2^i; increase i to trade efficiency for accuracy
%        frames: h*w*3*num_frames matrix of images
%        positions: num_frames*3 matrix of [x y theta]
%        min_x, max_x, min_y, max_y: world boundaries
%        discount_factor: [0,1] value to multiply unary scores by
%
%outputs: bboxes: top_k x 8 x num_frames array of scored proposals:
%               each row of top_k x 8 is (x1,y1,x2,y2,score,xloc,yloc,wwidth) 
%         phists: top_k x 12000 x num_frames array of dsift descriptors 

% add paths
run('/home/sbroniko/codetection/source/new-sentence-codetection/MCG-PreTrained/install.m');
addpath(pwd);
addpath(genpath('piotr-toolbox'));
addpath(genpath('vlfeat/toolbox'));
addpath(genpath('forests_edges_boxes'));
run('/home/sbroniko/codetection/source/new-sentence-codetection/vlfeat/toolbox/vl_setup');
addpath(genpath('MCG-PreTrained'));

fprintf('\nin new-sentence-codetection/new_score_saved_proposals_with_dsift.m\n');

% % enable parfor
% pools = matlabpool('size');
% cpus = feature('numCores');
% if pools ~= (cpus - 1)
%     if pools > 0
%         matlabpool('close');
%     end
%     matlabpool('open', cpus - 1);
% end

%experiment parameters--shouldn't change
cam_offset = [-0.03 0.16 -0.2]; %estimated measurement, in m
world_boundary = [min_x max_x min_y max_y]; %[x1 x2 y1 y2] in m
%camera calibration data
cam_k = [7.2434508362823397e+02 0.0 3.1232994017160644e+02;...
        0.0 7.2412307134397406e+02 2.0310961045807585e+02;...
        0.0 0.0 1.0]; %not sure of units here

%set up and error check input
[~, ~, ~, T] = size(frames);
[num_proposals,~,T2] = size(proposal_boxes);
if (T ~= T2)
    fprintf('ERROR, frames and proposal_boxes length different, T=%d, T2=%d\n',T,T2);
    return;
end %if
if (num_proposals < top_k)
    fprintf('ERROR, top_k = %d when num_proposals = %d\n',top_k,num_proposals);
    return;
end %if
bboxes = zeros(top_k, 8, T); %each row: [x y w h score xloc yloc wwidth]
phist_size = [top_k, 12000];
phists = zeros([phist_size,T],'single'); %for storing histograms--HARDCODED 12000 as size of phow_hist 

% compute
parfor t = 1:T %main parfor loop to select top_k best proposals and also do histogram (dsift) scores
    %first get precomputed boxes and sort descending by score
    img = frames(:,:,:,t);
    pose = positions(t,:);
    raw_bbs = proposal_boxes(:,:,t); %saved proposals
    bbs = sortrows(raw_bbs,-5); %sort descending by score
    
    %now find the top_k best proposals that are in front of the camera and
    %in bounds
    new_boxes = zeros(top_k, 8);
    temp_phists = zeros(phist_size,'single'); %do phists too
    i = 1; %index into new_boxes
    j = 1; %index into proposal_boxes
    boundary = world_boundary; %copy in bounary locations
    while ((i <= top_k) && (j <= num_proposals))
        %assume box is on ground (height = 0) to find x,y location
        bc_point = [(bbs(j,1)+(bbs(j,3)/2))...
                    (bbs(j,2)+bbs(j,4))]; %bottom center of box
        [loc locflag] = pixel_and_height_to_world(bc_point, 0, cam_k, pose, cam_offset);
        if ~locflag %box behind camera
            j=j+1; %don't use this box, move on
            continue; 
        end %if
        if ((loc(1) > boundary(2)) ||...
            (loc(1) < boundary(1)) ||...
            (loc(2) > boundary(4)) ||...
            (loc(2) < boundary(3))) %box out of bounds
            j = j+1; %don't use this box, move on
            continue;
        end %if
        %if we get here, box is in front of camera and in bounds, so use it
        %copy pixel locations and score
        new_boxes(i,1:5) = bbs(j,:);
        %save x,y in columns 6 and 7
        new_boxes(i,6) = loc(1); new_boxes(i,7) = loc(2);
        %find width and save in column 8
        lcorner = [bbs(i,1) (bbs(i,2)+bbs(i,4))];
        rcorner = [(bbs(i,1)+bbs(i,3)) (bbs(i,2)+bbs(i,4))];
        lcloc = pixel_and_height_to_world(lcorner,0,cam_k,pose,cam_offset);
        rcloc = pixel_and_height_to_world(rcorner,0,cam_k,pose,cam_offset);
        wwidth = norm(lcloc-rcloc); %had to replace pdist b/c license issues (statistics toolbox)
        %pdist([lcloc'; rcloc'],'euclidean');
        new_boxes(i,8) = wwidth;
        %compute histogram for box j (for s_score later)
        x1 = bbs(j,1); x2 = bbs(j,3) + bbs(j,1) - 1;
        y1 = bbs(j,2); y2 = bbs(j,4) + bbs(j,2) - 1;
        hist_out = phow_hist(img(y1:y2,x1:x2,:),ssize);
        temp_phists(i,:) = hist_out';
        i = i+1; %INCREMENT i
    end %while
    bboxes(:,:,t) = new_boxes;
    phists(:,:,t) = temp_phists;
%%unary scores and histogram scores complete
end %parfor
%converting from [x y w h] to [x1 y1 x2 y2]
bboxes(:,3,:) = bboxes(:,3,:) + bboxes(:,1,:) - 1;
bboxes(:,4,:) = bboxes(:,4,:) + bboxes(:,2,:) - 1;
%apply discount factor to unary scores
bboxes(:,5,:) = discount_factor * bboxes(:,5,:);
end %function

%helper functions from phow_caltech101
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
    [~, binsa] = min(vl_alldist(model.vocab, single(descrs)), [], 1) ;
  case 'kdtree'
    binsa = double(vl_kdtreequery(model.kdtree, model.vocab, ...
                                  single(descrs), ...
                                  'MaxComparisons', 50)) ;
end
hists = cell(length(model.numSpatialX));
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