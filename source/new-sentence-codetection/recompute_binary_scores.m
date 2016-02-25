function [gscore,num_gscore]= recompute_binary_scores(bboxes)
%inputs: 
%        bboxes: top_k*8*num_frames, each row of top_k*8 is (x1,y1,x2,y2,f,xloc,yloc,wwidth) 
%        beta: scalar weight for distance score (d_score)
%        gamma: scalar weight for width score (w_score)
%        NOTE: IOT keep gscore values in range [0,1], need to make sure
%        that beta,gamma are scaled so that
%        alpha+beta+gamma+delta = 1; NEED TO DO THIS IN SCHEME SINCE DELTA
%        IS ONLY USED IN SCHEME
%outputs: 
%         gscore: num_gscorex5 matrix of [f1,b1,f2,b2,g] of binary scores; 
%              g is the binary score between frame1,box1 and frame2,box2;
%              number of rows is variable based on which elements of the
%              binary score matrices are non-zero
%         num_gscore: number of rows in gscore

% add paths
%run('/home/sbroniko/codetection/source/new-sentence-codetection/MCG-PreTrained/install.m');
addpath(pwd);
%addpath(genpath('piotr-toolbox'));
%addpath(genpath('vlfeat/toolbox'));
%addpath(genpath('forests_edges_boxes'));
%run('/home/sbroniko/codetection/source/new-sentence-codetection/vlfeat/toolbox/vl_setup');
%addpath(genpath('MCG-PreTrained'));

fprintf('in new-sentence-codetection/recompute_binary_scores4.m');

%experiment parameters--shouldn't change
gaussparam1 = [.25,0]; %setting sigma=.25,mu=0 for distance
gaussparam2 = [.1,0]; %setting sigma=.1,mu=0 for width difference
cam_offset = [-0.03 0.16 -0.2]; %estimated measurement, in m
world_boundary = [-3 3.05 -2.62 3.93]; %[x1 x2 y1 y2] in m
distance_threshold = 0.5; %distance threshold for similarity score--in m
binary_score_threshold = 1e-6; %threshold for a binary score to go into ouput--ARBITRARY, may need to change
cam_k = [7.2434508362823397e+02 0.0 3.1232994017160644e+02;...
        0.0 7.2412307134397406e+02 2.0310961045807585e+02;...
        0.0 0.0 1.0]; %not sure of units here

% compute
[top_k, ~, T] = size(bboxes);

%now compute binary scores:
% 1) world distance between boxes (all boxes all frames)
% 2) difference in world box width (all boxes all frames)

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
%%CAN WE CHANGE THIS to inverse of dist/wdiff now?

%now zero out scores for boxes in same frame
blankscore = zeros(top_k,'single');
for i = 1:T
    start = (i-1)*top_k + 1; stop = i*top_k;
    d_score(start:stop,start:stop) = blankscore;
    w_score(start:stop,start:stop) = blankscore;
end % for i
%d_score and w_score complete 

%linear combination of d_score and w_score
%G = beta*d_score + gamma*w_score;
%JUS using d_score
G = d_score;

%set output
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

