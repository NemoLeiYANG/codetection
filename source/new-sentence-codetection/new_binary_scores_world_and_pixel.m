function [boxes_w_fscore,gscore,num_gscore]= ...
    new_binary_scores_world_and_pixel(bboxes)
%inputs: bboxes: top_k x 8 x T matrix of scored proposals with location
%               data
%
%outputs: boxes_w_fscore: top_k*8*num_frames, each row of top_k*8 is (x1,y1,x2,y2,f,xloc,yloc,wwidth) 
%                        f is the unary score for each box in range
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
addpath(genpath('MCG-PreTrained'));

fprintf('\nin new-sentence-codetection/new_binary_scores_world_and_pixel.m\n');

[top_k,~,T] = size(bboxes);

% % enable parfor
% pools = matlabpool('size');
% cpus = feature('numCores');
% if pools ~= (cpus - 1)
%     if pools > 0
%         matlabpool('close');
%     end
%     matlabpool('open', cpus - 1);
% end

%flags/parameters to use different methods
world_distance_flag = true;%false;
pixel_distance_flag = true;
a = 0.5; % range [0,1], only used when both flags are true

%experiment parameters--shouldn't change
%gaussparam1 = [.25,0]; %setting sigma=.25,mu=0 for distance
%gaussparam2 = [.1,0]; %setting sigma=.1,mu=0 for width difference
%cam_offset = [-0.03 0.16 -0.2]; %estimated measurement, in m
% world_boundary = [-3 3.05 -2.62 3.93]; %[x1 x2 y1 y2] in m
%distance_threshold = 0.5; %distance threshold for similarity score--in m
binary_score_threshold = 0; %turning off binary score threshold
        %1e-3;%1e-6; %threshold for a binary score to go into ouput--ARBITRARY, may need to change

sigmoid_a = -6; %sigmoid steepness
sigmoid_c = 0.75; %sigmoid threshold (50% value)

sigmoid_a2 = -0.1; %for pixel distance
sigmoid_c2 = 80; 


%now compute binary scores:
% 1) world distance between boxes (all boxes all frames)
% 2) difference in world box width (all boxes all frames)
% 3) visual similarity (Haonan's method) between boxes that are closer
% together than some threshold

%first vectorize world xy and width measures for all boxes
worldX = bboxes(:,6,:);
worldY = bboxes(:,7,:);
%worldW = bboxes(:,8,:);
worldX = reshape(worldX, T*top_k, 1);
worldY = reshape(worldY, T*top_k, 1);
worldXY = [worldX worldY];
%worldW = reshape(worldW, T*top_k, 1);

% pixXcenter = bboxes(:,1,:) + 0.5*bboxes(:,3,:);
% pixYcenter = bboxes(:,2,:) + 0.5*bboxes(:,4,:);
pixXcenter = 0.5*(bboxes(:,3,:) - bboxes(:,1,:));
pixYcenter = 0.5*(bboxes(:,4,:) - bboxes(:,2,:));
pixXcenter = reshape(pixXcenter,T*top_k,1);
pixYcenter = reshape(pixYcenter,T*top_k,1);
pixXYcenter = [pixXcenter pixYcenter];

% % ZERO THIS OUT BECAUSE NOT USING WORLD WIDTH HERE
% worldW = worldW * 0;

%now compute distances -- using euclidean might be slow, but simpler than
%using squared euclidean distance as input to gaussian kernel
worldDist = triu(real(pdist2(worldXY,worldXY,'euclidean'))); 
pixDist = triu(real(pdist2(pixXYcenter,pixXYcenter,'euclidean'))); 


% % ZERO THIS OUT BECAUSE NOT USING WORLD WIDTH HERE
% worldWdiff = triu(real(pdist2(worldW,worldW,'euclidean'))); 
% worldWdiff = worldWdiff * 0;

% %use gaussian kernel to scale to (0,1), higher=better
% d_score = triu(single(gaussmf(worldDist,gaussparam1)));

%use sigmoidal membership function to scale to (0,1), higher=better
d_score = triu(single(sigmf(worldDist,[sigmoid_a,sigmoid_c])));
p_score = triu(single(sigmf(pixDist,[sigmoid_a2,sigmoid_c2])));


% % ZERO THIS OUT BECAUSE NOT USING WORLD WIDTH HERE
% w_score = triu(single(gaussmf(worldWdiff,gaussparam2)));
% w_score = w_score * 0;


%now zero out scores for boxes in same frame
blankscore = zeros(top_k,'single');
for i = 1:T
    start = (i-1)*top_k + 1; stop = i*top_k;
    d_score(start:stop,start:stop) = blankscore;
%    w_score(start:stop,start:stop) = blankscore;
    p_score(start:stop,start:stop) = blankscore;
end % for i

world_distance = d_score; %done with world distance computation
pixel_distance = p_score;
%save('foo_p_score.mat','p_score');

%d_score and w_score complete 

% %now do visual similarity (s_score) on boxes that are within some distance
% %threshold of each other
% s_score = zeros(T*top_k,'single');
% 
% % NO S_SCORES
% % for i = 1:T*top_k
% %     for j = (i+1):T*top_k %can do this b/c matrix will be symmetric
% %         if ((worldDist(i,j) < distance_threshold) && ...
% %             (w_score(i,j) ~= 0)) %last condition ensures that we don't do
% %                                  % similarity on boxes in same frame
% %             frame_idx1 = ceil(i/top_k);
% %             frame_idx2 = ceil(j/top_k);
% %             box_idx1 = mod(i,top_k);
% %             if (box_idx1 == 0)
% %                 box_idx1 = top_k;
% %             end %if
% %             box_idx2 = mod(j,top_k);
% %             if (box_idx2 == 0)
% %                 box_idx2 = top_k;
% %             end %if
% %             if ((~valid_loc(box_idx1,frame_idx1)) || ...
% %                 (~valid_loc(box_idx2,frame_idx2)))
% %                 continue; %at least one box not valid
% %             else %do pdist2 on histograms
% %                 hist1 = phists(box_idx1,:,frame_idx1);
% %                 hist2 = phists(box_idx2,:,frame_idx2);
% %                 tempscore = 1-pdist2(hist1,hist2,'chisq');
% %                 s_score(i,j) = tempscore;
% %                 s_score(j,i) = tempscore; %b/c matrix is symmetric
% %             end %If
% %         end %if
% %     end %for j
% % end %for i

%linear combination of s_score, d_score, and w_score
%G = alpha*s_score + beta*d_score + gamma*w_score;

if (world_distance_flag && pixel_distance_flag)
    G = a * world_distance + (1-a) * pixel_distance;
    fprintf('binary score computed from COMBINATION\n');
elseif (world_distance_flag)
    G = world_distance;
    fprintf('binary score from WORLD DISTANCE\n');
else
    G = pixel_distance;
    fprintf('binary score from PIXEL DISTANCE\n');
end %if

%set output
boxes_w_fscore = bboxes;
gscore = zeros(((T*top_k)^2)/2, 5,'single'); %each row is [f1,b1,f2,b2,g]
g_idx = 0;
%%BAD--looks only 1 proposal ahead instead of 1 frame
% for i = 1:(T*top_k-1)
%     %    for j = (i+1):T*top_k %can do this b/c matrix will be symmetric
%     j=i+1; %this ensures only the NEXT FRAME is connected
%     if (G(i,j) > binary_score_threshold)%~= 0)
%         frame_idx1 = ceil(i/top_k);
%         frame_idx2 = ceil(j/top_k);
%         box_idx1 = mod(i,top_k);
%         if (box_idx1 == 0)
%             box_idx1 = top_k;
%         end %if
%         box_idx2 = mod(j,top_k);
%         if (box_idx2 == 0)
%             box_idx2 = top_k;
%         end %if
%         g_idx = g_idx + 1;
%         gscore(g_idx,:) = [frame_idx1, box_idx1, frame_idx2, ...
%                            box_idx2, G(i,j)];
%     end %if
%         %  end % for j
% end %for i

for fr1 = 1:(T-1)
    fr2 = fr1 + 1;
    for i = 1:top_k
        box1 = ((fr1-1)*top_k + i);
        for j = 1:top_k
            box2 = ((fr2-1)*top_k + j);
            if (G(box1,box2) > binary_score_threshold)%~= 0)
                g_idx = g_idx + 1;
                gscore(g_idx,:) = [fr1, i, fr2, j, G(box1,box2)];
            end %if
        end %for j
    end %for i
end %for frame_idx1
gscore = gscore(1:g_idx,:);
gscore = sortrows(gscore,3);
%might want to do sortrows(gscore,[1,3]) to sort by 1st then 3rd columns
num_gscore = g_idx;
%fprintf('Elapsed time for output setup: %f\n',toc);
end %function scott_proposals_similarity

% %helper functions from phow_caltech101
% function hist = phow_hist(im, ssize)
% load('phow-model/vocab.mat');
% model.vocab = vocab;
% model.phowOpts = {'Step', 3};
% model.numSpatialX = [2, 4];
% model.numSpatialY = [2, 4];
% model.quantizer = 'kdtree';
% model.kdtree = vl_kdtreebuild(vocab);
% hist = getImageDescriptor(model, im, ssize);
% end
% 
% function im = standarizeImage(im, ssize)
% im = im2single(im) ;
% scaling = max([ssize/size(im,1) ssize/size(im,2)]);
% newsize = round([size(im,1) size(im,2)]*scaling);
% im = imresize(im, newsize);
% end

% function hist = getImageDescriptor(model, im, ssize)
% im = standarizeImage(im, ssize) ;
% width = size(im,2) ;
% height = size(im,1) ;
% numWords = size(model.vocab, 2) ;
% % get PHOW features
% [frames, descrs] = vl_phow(im, model.phowOpts{:}) ;
% % quantize local descriptors into visual words
% switch model.quantizer
%   case 'vq'
%     [~, binsa] = min(vl_alldist(model.vocab, single(descrs)), [], 1) ;
%   case 'kdtree'
%     binsa = double(vl_kdtreequery(model.kdtree, model.vocab, ...
%                                   single(descrs), ...
%                                   'MaxComparisons', 50)) ;
% end
% hists = cell(length(model.numSpatialX));
% for i = 1:length(model.numSpatialX)
%     binsx = vl_binsearch(linspace(1,width,model.numSpatialX(i)+1), frames(1,:)) ;
%     binsy = vl_binsearch(linspace(1,height,model.numSpatialY(i)+1), frames(2,:)) ;
%     % combined quantization
%     bins = sub2ind([model.numSpatialY(i), model.numSpatialX(i), numWords], ...
%                    binsy,binsx,binsa) ;
%     hist = zeros(model.numSpatialY(i) * model.numSpatialX(i) * numWords, 1) ;
%     hist = vl_binsum(hist, ones(size(bins)), bins) ;
%     hists{i} = single(hist / sum(hist)) ;
% end
% hist = cat(1,hists{:}) ;
% hist = hist / sum(hist) ;
% end

% %my helper functions
% function rotmat = rotation3dx(a) %roll
%     rotmat = [1,0,0,0;...
%               0,cos(a),-sin(a),0;...
%               0,sin(a),cos(a),0;...
%               0,0,0,1];
% end
% 
% function rotmat = rotation3dy(a) %pitch
%     rotmat = [cos(a),0,sin(a),0;...
%               0,1,0,0;...
%               -sin(a),0,cos(a),0;...
%               0,0,0,1];
% end
% 
% function rotmat = rotation3dz(a) %yaw
%     rotmat = [cos(a),-sin(a),0,0;...
%               sin(a),cos(a),0,0;...
%               0,0,1,0;...
%               0,0,0,1];
% end
% 
% function transmat = translation3d(x,y,z)
%     transmat = [1,0,0,x;...
%                 0,1,0,y;...
%                 0,0,1,z;...
%                 0,0,0,1];
% end

% function trans = make_transform_3d(theta,phi,psi,x,y,z)
%     transmat = translation3d(x,y,z);
%     zrot = rotation3dz(theta);
%     yrot = rotation3dy(phi);
%     xrot = rotation3dx(psi);
%     trans = transmat * zrot * yrot *xrot;
% end

% function world_to_cam = robot_pose_to_world__camera_txf(pose, cam_offset)
%     x = cam_offset(1); y = cam_offset(2); z = cam_offset(3);
%     trans1 = translation3d(x,y,z);
%     trans2 = make_transform_3d((pose(3) - (pi/2)),0,-pi/2,...
%                                pose(1), pose(2), 0);
%     world_to_cam = trans1/trans2;                               
% end 

% function h = point_to_homogeneous(p)
%     h = horzcat(p,1);
% end
% 
% function p = homogeneous_to_point(h)
%     p = h(1:(length(h)-1));
% end

% function p = transform_point_3d(mat, point)
%     h = point_to_homogeneous(point);
%     temp = mat*h';
%     p = homogeneous_to_point(temp);
% end

% function [point valid] = pixel_and_height_to_world(pix, height, cam_k, pose, cam_offset)
%     world_to_cam = robot_pose_to_world__camera_txf(pose,cam_offset);
%     cam_world = transform_point_3d(inv(world_to_cam),[0,0,0]);
%     fx = cam_k(1,1); fy = cam_k(2,2);
%     cx = cam_k(1,3); cy = cam_k(2,3);
%     px = (pix(1)-cx)/fx;
%     py = (pix(2)-cy)/fy;
%     pixel_world = transform_point_3d(inv(world_to_cam),[px,py,1]);
%     dxyz = pixel_world - cam_world;
%     if (dxyz(3) > 0)
%         %point = [NaN, NaN];
%         valid = false;
%     else
%         valid = true;
%     end
%     l = (height - cam_world(3))/dxyz(3);
%     point = cam_world + dxyz*l;
%     %end
% end 