function [boxes_w_fscore,gscore,num_gscore]= ... %d_score,w_score,s_score,G,distance_threshold,worldDist,phists,valid_loc,worldWpenexpmat]  
    scott_proposals_similarity2(top_k, ssize, frames, positions,alpha,beta,gamma)
%inputs: top_k: number of proposals to generate in each frame
%        ssize: the size to which each proposal is rescaled to (for
%               phow_hist); ssize should be 2^i; increase i to trade efficiency for accuracy
%        frames: h*w*3*num_frames matrix of images
%        positions: num_frames*3 matrix of [x y theta]
%        alpha: scalar weight visual similarity score (s_score)
%        beta: scalar weight for distance score (d_score)
%        gamma: scalar weight for width score (w_score)
%        NOTE: IOT keep gscore values in range [0,1], need to make sure
%        that alpha,beta,gamma,delta(not used in MATLAB) are scaled so that
%        alpha+beta+gamma+delta = 1; NEED TO DO THIS IN SCHEME SINCE DELTA
%        IS ONLY USED IN SCHEME
%outputs: boxes_w_fscore: top_k*8*num_frames, each row of top_k*8 is (x1,y1,x2,y2,f,xloc,yloc,wwidth) 
%                        f is the unary score for each box (computed from
%                        MCG proposal scores with penalty terms); in range
%                        [0,1], higher is better.
%         gscore: num_gscorex5 matrix of [f1,b1,f2,b2,g] of binary scores; 
%              g is the binary score between frame1,box1 and frame2,box2;
%              number of rows is variable based on which elements of the
%              binary score matrices are non-zero
%         num_gscore: number of rows in gscore

% add paths
addpath(pwd);
addpath(genpath('piotr-toolbox'));
addpath(genpath('vlfeat/toolbox'));
addpath(genpath('forests_edges_boxes'));
run('/home/sbroniko/codetection/source/sentence-codetection/vlfeat/toolbox/vl_setup');
addpath(genpath('MCG-PreTrained'));

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
gaussparam1 = [.25,0]; %setting sigma=.25,mu=0 for distance
gaussparam2 = [.1,0]; %setting sigma=.1,mu=0 for width difference
cam_offset = [-0.03 0.16 -0.2]; %estimated measurement, in m
world_boundary = [-3 3.05 -2.62 3.93]; %[x1 x2 y1 y2] in m
distance_threshold = 0.5; %distance threshold for similarity score--in m
binary_score_threshold = 1e-6; %threshold for a binary score to go into ouput--ARBITRARY, may need to change
%dbox_fscore = 0.5; %dummy box fscore value
width_threshold = 1.0; %threshold on wwidth of boxes (world with of object) in m -- ARBITRARY, may need to change
pixel_threshold = 10; %threshold on pixel distance from edges of frame -- ARBITRARY, may need to change
%camera calibration data
cam_k = [7.2434508362823397e+02 0.0 3.1232994017160644e+02;...
        0.0 7.2412307134397406e+02 2.0310961045807585e+02;...
        0.0 0.0 1.0]; %not sure of units here

% compute
[h, w, d, T] = size(frames);
bboxes = zeros(top_k, 8, T); %each row: [x y w h score xloc yloc wwidth]
phist_size = [top_k, 12000];
phists = zeros([phist_size,T],'single'); %for storing histograms--HARDCODED 12000 as size of phow_hist 
valid_loc = false(top_k,T); %for storing where box location is valid (in front of cam)

%t1=tic;
parfor t = 1:T %main parfor loop to do proposals and histogram scores
    %first get boxes for all frames
    img = frames(:,:,:,t);
    pose = positions(t,:);
    %tic;
    bbs = MCGboxes(img,top_k); %proposals
    %fprintf('Time for single frame proposals: %f\n',toc);
    %now do adjust scores and add world x,y,w information to matrix
    new_boxes = zeros(top_k, 8);
    new_boxes(:,1:5) = bbs;
    boundary = world_boundary;
    valid_locations = false(top_k,1);
    temp_phists = zeros(phist_size,'single');
    for i = 1:top_k %for each proposal
        bc_point = [(bbs(i,1)+(bbs(i,3)/2)) (bbs(i,2)+bbs(i,4))]; %bottom center of box
        %assume box is on ground (height = 0) to find x,y location
        [loc locflag] = pixel_and_height_to_world(bc_point, 0, cam_k, pose, cam_offset);
        valid_locations(i) = locflag; %boxes not on ground plane will 
            %project to a location behind the camera and be marked invalid
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
        %do penalty on f (unary) scores (column 5) here
        if ((bbs(i,1) < pixel_threshold) || ... %penalize boxes too close to edges of image
            (bbs(i,2) < pixel_threshold) || ...
            ((bbs(i,1) + bbs(i,3)) > (w - pixel_threshold)) || ...
            ((bbs(i,2) + bbs(i,4)) > (h - pixel_threshold)) ||...
            (locflag == 0)) %box is behind camera
            penalty = -10; %ARBITRARY penalty factor here--might need to adjust
            new_boxes(i,5) = new_boxes(i,5)*exp(penalty);
            continue; %done with this box
        end %if locflag
        if (loc(1) > boundary(2)) %xpenalty
            xpenalty = boundary(2) - loc(1);
        elseif (loc(1) < boundary(1))
            xpenalty = loc(1) - boundary(1);
        else
            xpenalty = 0;
        end %if loc(1)
        if (loc(2) > boundary(4)) %ypenalty
            ypenalty = boundary(4) - loc(2);
        elseif (loc(2) < boundary(3))
            ypenalty = loc(2) - boundary(3);
        else
            ypenalty = 0;
        end %if loc(2)
        if (wwidth > width_threshold) %wpenalty
            wpenalty = width_threshold - wwidth; %%NOT SURE THIS IS DOING WHAT I WANT IT TO DO
            %display(wpenalty);
            %display(exp(wpenalty));
        else
            wpenalty = 0;
        end %if wwidth
        new_boxes(i,5) = new_boxes(i,5)*exp(xpenalty)*exp(ypenalty)*exp(wpenalty);
        %compute histogram for box i (for s_score later)
        x1 = bbs(i,1); x2 = bbs(i,3) + bbs(i,1) - 1;
        y1 = bbs(i,2); y2 = bbs(i,4) + bbs(i,2) - 1;
        hist_out = phow_hist(img(y1:y2,x1:x2,:),ssize);
        temp_phists(i,:) = hist_out';
    end %for i
    bboxes(:,:,t) = new_boxes;
    valid_loc(:,t) = valid_locations;
    phists(:,:,t) = temp_phists;
%%unary scores and histogram scores complete
end %parfor
% fprintf('Elapsed time for parfor loop: %f\n',toc(t1));
% tic;
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
worldDist = triu(real(pdist2(worldXY,worldXY,'euclidean'))); 
worldWdiff = triu(real(pdist2(worldW,worldW,'euclidean'))); 

%use gaussian kernel to scale to (0,1), higher=better
d_score = triu(single(gaussmf(worldDist,gaussparam1)));
w_score = triu(single(gaussmf(worldWdiff,gaussparam2)));

%now zero out scores for boxes in same frame
blankscore = zeros(top_k,'single');
for i = 1:T
    start = (i-1)*top_k + 1; stop = i*top_k;
    d_score(start:stop,start:stop) = blankscore;
    w_score(start:stop,start:stop) = blankscore;
end % for i

%threshold-related penalty on w_score here **EXPERIMENTAL**
worldWpen = width_threshold - worldW;
worldWpen(worldWpen > 0) = 0;
worldWpenexp = exp(worldWpen);
worldWpenexpmat = worldWpenexp * worldWpenexp';
w_score = w_score .* worldWpenexpmat;

%d_score and w_score complete 
% fprintf('Binary score setup: %f\n',toc); 
% tic;
%now do visual similarity (s_score) on boxes that are within some distance
%threshold of each other
s_score = zeros(T*top_k,'single');
for i = 1:T*top_k
    for j = (i+1):T*top_k %can do this b/c matrix will be symmetric
        if ((worldDist(i,j) < distance_threshold) && ...
            (w_score(i,j) ~= 0)) %last condition ensures that we don't do
                                 % similarity on boxes in same frame
            frame_idx1 = ceil(i/top_k);
            frame_idx2 = ceil(j/top_k);
            box_idx1 = mod(i,top_k);
            if (box_idx1 == 0)
                box_idx1 = top_k;
            end %if
            box_idx2 = mod(j,top_k);
            if (box_idx2 == 0)
                box_idx2 = top_k;
            end %if
            if ((~valid_loc(box_idx1,frame_idx1)) || ...
                (~valid_loc(box_idx2,frame_idx2)))
                continue; %at least one box not valid
            else %do pdist2 on histograms
                hist1 = phists(box_idx1,:,frame_idx1);
                hist2 = phists(box_idx2,:,frame_idx2);
                tempscore = 1-pdist2(hist1,hist2,'chisq');
                s_score(i,j) = tempscore;
                s_score(j,i) = tempscore; %b/c matrix is symmetric
            end %If
        end %if
    end %for j
end %for i

%linear combination of s_score, d_score, and w_score
G = alpha*s_score + beta*d_score + gamma*w_score;
% fprintf('Elapsed time for binary score computation: %f\n',toc);
% tic;
%%NEED TO ADD UNARY AND BINARY SCORES FOR DUMMY BOXES--do I want to do it
%%before or after combining s_score, d_score, and w_score?  probably need
%%it before converting output to list

% %DUMMY BOX SCORES
% %unary dummy box scores/locations
% for t = 1:T
%     bboxes(top_k+1,:,t) = [0,0,0,0,dbox_fscore,-inf,-inf,-inf];
% end %for


%%DOING BOTH UNARY AND BINARY DUMMY BOX SCORES IN C!!!

%set output
boxes_w_fscore = bboxes;
%gscore = simi;
gscore = zeros(((T*top_k)^2)/2, 5,'single'); %each row is [f1,b1,f2,b2,g]
g_idx = 0;
for i = 1:T*top_k
    for j = (i+1):T*top_k %can do this b/c matrix will be symmetric
        if (G(i,j) > binary_score_threshold)%~= 0)
            frame_idx1 = ceil(i/top_k);
            frame_idx2 = ceil(j/top_k);
            box_idx1 = mod(i,top_k);
            if (box_idx1 == 0)
                box_idx1 = top_k;
            end %if
            box_idx2 = mod(j,top_k);
            if (box_idx2 == 0)
                box_idx2 = top_k;
            end %if
            g_idx = g_idx + 1;
            gscore(g_idx,:) = [frame_idx1, box_idx1, frame_idx2, ...
                             box_idx2, G(i,j)];
        end %if
    end % for j
end %for i
gscore = gscore(1:g_idx,:);
gscore = sortrows(gscore,3);
%might want to do sortrows(gscore,[1,3]) to sort by 1st then 3rd columns
num_gscore = g_idx;
%fprintf('Elapsed time for output setup: %f\n',toc);
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