function [boxes_w_fscore,gscore,num_gscore,G,G_mat]= ...
    new_binary_scores_world_and_pixel2(bboxes,a)
%inputs: bboxes: top_k x 16 x T matrix of scored proposals with location
%               data, each row of topk_k x 16 is
%                 (x1,y1,x2,y2,f,xloc_bc,yloc_bc,wwidth,oldscore,xloc_tl,
%                  yloc_tl,zloc_tl,xloc_br,yloc_br,zloc_br,wdist_bc) 
%
%outputs: boxes_w_fscore: top_k x 16 x T array of scored proposals:
%               each row of topk_k x 16 is
%                 (x1,y1,x2,y2,f,xloc_bc,yloc_bc,wwidth,oldscore,xloc_tl,
%                  yloc_tl,zloc_tl,xloc_br,yloc_br,zloc_br,wdist_bc)
%                        f is the unary score for each box in range
%                        [0,1], higher is better.
%           SAME AS BBOXES INPUT
%
%OLD boxes_w_fscore: top_k*8*num_frames, each row of top_k*8 is (x1,y1,x2,y2,f,xloc,yloc,wwidth) 
%
%         gscore: num_gscorex5 matrix of [f1,b1,f2,b2,g] of binary scores; 
%              g is the binary score between frame1,box1 and frame2,box2;
%              number of rows is variable based on which elements of the
%              binary score matrices are non-zero
%         num_gscore: number of rows in gscore
%         G: top_k*T x top_k*T matrix of binary scores between every box in
%            every frame (MIGHT NOT NEED THIS ANYMORE)
%         G_mat: top_k x top_k x (T-1) matrix of binary scores between
%                adjacent frames; G_mat(:,:,1) is binary scores between
%                frames 1 and 2

% add paths
addpath(pwd);
addpath(genpath('piotr-toolbox'));
addpath(genpath('vlfeat/toolbox'));
addpath(genpath('forests_edges_boxes'));
addpath(genpath('MCG-PreTrained'));

fprintf('\nin new-sentence-codetection/new_binary_scores_world_and_pixel2.m\n');

[top_k,~,T] = size(bboxes);
G=0;  %for now--if we end up not using, delete? or keep for compatibility

%might want to tie this to top_k like in new_score_saved...
%or might just want it on all the time
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
%a = 0.5; % range [0,1], only used when both flags are true

%experiment parameters--shouldn't change
%gaussparam1 = [.25,0]; %setting sigma=.25,mu=0 for distance
%gaussparam2 = [.1,0]; %setting sigma=.1,mu=0 for width difference
%cam_offset = [-0.03 0.16 -0.2]; %estimated measurement, in m
% world_boundary = [-3 3.05 -2.62 3.93]; %[x1 x2 y1 y2] in m
%distance_threshold = 0.5; %distance threshold for similarity score--in m
%binary_score_threshold = 0; %turning off binary score threshold
        %1e-3;%1e-6; %threshold for a binary score to go into ouput--ARBITRARY, may need to change

sigmoid_a = -1;%-6; %sigmoid steepness
sigmoid_c = 2;%0.75; %sigmoid threshold (50% value)

sigmoid_a2 = -0.005';%-0.075;%-0.1; %for pixel distance
sigmoid_c2 = 400;%40;%80; 


%now compute binary scores:
% 1) world distance between boxes (all boxes all frames)
% 2) difference in world box width (all boxes all frames)
% 3) visual similarity (Haonan's method) between boxes that are closer
% together than some threshold

%%START HERE--Think I can get rid of all this reshaping bs and just grab
%%the location data directly from each frame for the computation

pixel_coordinates = bboxes(:,1:4,:); %2 2-d (x1 y1 x2 y2)
world_coordinates = bboxes(:,10:15,:); %2 3-d (wxtl,wytl,wztl,wxbr,wybr,wzbr)

%%OLD WAY
% % %first vectorize world xy and width measures for all boxes OLD WAY
% % worldX = bboxes(:,6,:);
% % worldY = bboxes(:,7,:);
% % %worldW = bboxes(:,8,:);
% % worldX = reshape(worldX, T*top_k, 1);
% % worldY = reshape(worldY, T*top_k, 1);
% % worldXY = [worldX worldY];
% % %worldW = reshape(worldW, T*top_k, 1);
% 
% %new method for world locations/distance using 2 3-d corners
% worldX_tl = bboxes(:,10,:);
% worldY_tl = bboxes(:,11,:);
% worldZ_tl = bboxes(:,12,:);
% worldX_br = bboxes(:,13,:);
% worldY_br = bboxes(:,14,:);
% worldZ_br = bboxes(:,15,:);
% worldX_tl = reshape(worldX_tl,T*top_k,1);
% worldY_tl = reshape(worldY_tl,T*top_k,1);
% worldZ_tl = reshape(worldZ_tl,T*top_k,1);
% worldX_br = reshape(worldX_br,T*top_k,1);
% worldY_br = reshape(worldY_br,T*top_k,1);
% worldZ_br = reshape(worldZ_br,T*top_k,1);
% worldXYZXYZ = [worldX_tl worldY_tl worldZ_tl worldX_br worldY_br worldZ_br];
% 
% 
% % %using pixel location of center of box for 2-d distance
% % % pixXcenter = bboxes(:,1,:) + 0.5*bboxes(:,3,:);
% % % pixYcenter = bboxes(:,2,:) + 0.5*bboxes(:,4,:);
% % pixXcenter = bboxes(:,1,:) + (0.5*(bboxes(:,3,:) - bboxes(:,1,:)));
% % pixYcenter = bboxes(:,2,:) + (0.5*(bboxes(:,4,:) - bboxes(:,2,:)));
% % pixXcenter = reshape(pixXcenter,T*top_k,1);
% % pixYcenter = reshape(pixYcenter,T*top_k,1);
% % pixXYcenter = [pixXcenter pixYcenter];
% 
% %using pixel locations of top-left and bottom-right corners for 4-d
% %distance
% pixXleft = bboxes(:,1,:); pixXleft = reshape(pixXleft,T*top_k,1);
% pixYleft = bboxes(:,2,:); pixYleft = reshape(pixYleft,T*top_k,1);
% pixXright = bboxes(:,3,:); pixXright = reshape(pixXright,T*top_k,1);
% pixYright = bboxes(:,4,:); pixYright = reshape(pixYright,T*top_k,1);
% pixXYXY = [pixXleft pixYleft pixXright pixYright];

%instead of using huge matrices, make matrices of top_k x top_k x (T-1)

pixel_distance = zeros(top_k,top_k,(T-1));
world_distance = zeros(top_k,top_k,(T-1));

%find each top_k x top_k score matrix individually (and pass thru sigmoid)

for i = 1:(T-1)
    pc1 = pixel_coordinates(:,:,i);
    pc2 = pixel_coordinates(:,:,(i+1));
    wc1 = world_coordinates(:,:,i);
    wc2 = world_coordinates(:,:,(i+1));
    tpd = sigmf(pdist2(pc1,pc2,'euclidean'),[sigmoid_a2,sigmoid_c2]);
    twd = sigmf(pdist2(wc1,wc2,'euclidean'),[sigmoid_a,sigmoid_c]);
    pixel_distance(:,:,i) = tpd';
    world_distance(:,:,i) = twd';
     %transposing here so that rows are second frame and columns are first
     %frame
end %for i 

%%OLD METHOD THAT USED HUGE MATRIX
% % ZERO THIS OUT BECAUSE NOT USING WORLD WIDTH HERE
% worldW = worldW * 0;

% %now compute distances -- using euclidean might be slow, but simpler than
% %using squared euclidean distance as input to gaussian kernel
% 
% %old way using world location of bottom center of box
% %worldDist = real(pdist2(worldXY,worldXY,'euclidean')); %triu(real(pdist2(worldXY,worldXY,'euclidean'))); 
% %new way using 3-d box corners
% worldDist = real(pdist2(worldXYZXYZ,worldXYZXYZ,'euclidean'));
% 
% %old way with box center
% %pixDist = real(pdist2(pixXYcenter,pixXYcenter,'euclidean')); %triu(real(pdist2(pixXYcenter,pixXYcenter,'euclidean'))); 
% %new way with box corners
% pixDist = real(pdist2(pixXYXY,pixXYXY,'euclidean'));
% 
% % % ZERO THIS OUT BECAUSE NOT USING WORLD WIDTH HERE
% % worldWdiff = triu(real(pdist2(worldW,worldW,'euclidean'))); 
% % worldWdiff = worldWdiff * 0;
% 
% % %use gaussian kernel to scale to (0,1), higher=better
% % d_score = triu(single(gaussmf(worldDist,gaussparam1)));
% 
% %use sigmoidal membership function to scale to (0,1), higher=better
% d_score = single(sigmf(worldDist,[sigmoid_a,sigmoid_c]));%triu(single(sigmf(worldDist,[sigmoid_a,sigmoid_c])));
% p_score = single(sigmf(pixDist,[sigmoid_a2,sigmoid_c2]));%triu(single(sigmf(pixDist,[sigmoid_a2,sigmoid_c2])));
% 
% % fprintf('\nd_score and p_score computed\n');
% % return;
% 
% % % ZERO THIS OUT BECAUSE NOT USING WORLD WIDTH HERE
% % w_score = triu(single(gaussmf(worldWdiff,gaussparam2)));
% % w_score = w_score * 0;
% 
% 
% %now zero out scores for boxes in same frame
% blankscore = zeros(top_k,'single');
% for i = 1:T
%     start = (i-1)*top_k + 1; stop = i*top_k;
%     d_score(start:stop,start:stop) = blankscore;
% %    w_score(start:stop,start:stop) = blankscore;
%     p_score(start:stop,start:stop) = blankscore;
% end % for i
% 
% world_distance = d_score; %done with world distance computation
% pixel_distance = p_score;
% %save('foo_p_score.mat','p_score');
% 
% %d_score and w_score complete 
% 
% % %now do visual similarity (s_score) on boxes that are within some distance
% % %threshold of each other
% % s_score = zeros(T*top_k,'single');
% % 
% % % NO S_SCORES
% % % for i = 1:T*top_k
% % %     for j = (i+1):T*top_k %can do this b/c matrix will be symmetric
% % %         if ((worldDist(i,j) < distance_threshold) && ...
% % %             (w_score(i,j) ~= 0)) %last condition ensures that we don't do
% % %                                  % similarity on boxes in same frame
% % %             frame_idx1 = ceil(i/top_k);
% % %             frame_idx2 = ceil(j/top_k);
% % %             box_idx1 = mod(i,top_k);
% % %             if (box_idx1 == 0)
% % %                 box_idx1 = top_k;
% % %             end %if
% % %             box_idx2 = mod(j,top_k);
% % %             if (box_idx2 == 0)
% % %                 box_idx2 = top_k;
% % %             end %if
% % %             if ((~valid_loc(box_idx1,frame_idx1)) || ...
% % %                 (~valid_loc(box_idx2,frame_idx2)))
% % %                 continue; %at least one box not valid
% % %             else %do pdist2 on histograms
% % %                 hist1 = phists(box_idx1,:,frame_idx1);
% % %                 hist2 = phists(box_idx2,:,frame_idx2);
% % %                 tempscore = 1-pdist2(hist1,hist2,'chisq');
% % %                 s_score(i,j) = tempscore;
% % %                 s_score(j,i) = tempscore; %b/c matrix is symmetric
% % %             end %If
% % %         end %if
% % %     end %for j
% % % end %for i
% 

%combine pixel and world distances
if (world_distance_flag && pixel_distance_flag)
    G_mat = a * world_distance + (1-a) * pixel_distance;
    fprintf('binary score computed from COMBINATION\n');
elseif (world_distance_flag)
    G_mat = world_distance;
    fprintf('binary score from WORLD DISTANCE\n');
else
    G_mat = pixel_distance;
    fprintf('binary score from PIXEL DISTANCE\n');
end %if

% OLD METHOD
% %linear combination of s_score, d_score, and w_score
% %G = alpha*s_score + beta*d_score + gamma*w_score;
% 
% if (world_distance_flag && pixel_distance_flag)
%     G = a * world_distance + (1-a) * pixel_distance;
%     fprintf('binary score computed from COMBINATION\n');
% elseif (world_distance_flag)
%     G = world_distance;
%     fprintf('binary score from WORLD DISTANCE\n');
% else
%     G = pixel_distance;
%     fprintf('binary score from PIXEL DISTANCE\n');
% end %if
%%END OLD STUFF


%set output
boxes_w_fscore = bboxes;

%OLD METHOD
% %make top_k x top_k x (T-1) matrix of transitions between adjacent frames
% G_mat = zeros(top_k,top_k,(T-1));
% for i = 1:(T-1)
%     rowstart = (i-1)*top_k + 1; rowstop = i*top_k;
%     colstart = i*top_k + 1; colstop = (i+1)*top_k;
%     G_mat(:,:,i) = G(rowstart:rowstop,colstart:colstop);
%     G_mat(:,:,i) = G_mat(:,:,i)';
%     %transposing here so that rows are second frame and columns are first
%     %frame
% end %for i

%build gscore list

num_gscore = numel(G_mat);
gscore = zeros(1,5);
%TRYING eliminating this to speed things up--need placeholder for output
% gscore = zeros(num_gscore, 5,'single'); %each row is [f1,b1,f2,b2,g]
% g_idx = 1;
% for fr1 = 1:(T-1)
%     fr2 = fr1 + 1;
%     for i = 1:top_k
%         for j = 1:top_k
%             gscore(g_idx,:) = [fr1,j,fr2,i,G_mat(i,j,fr1)];
%             g_idx = g_idx + 1;
%         end %for j
%     end %for i
% end %for fr1

%gscore = zeros(((T*top_k)^2)/2, 5,'single'); %each row is [f1,b1,f2,b2,g]
%g_idx = 0;
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

%%OLD METHOD
% for fr1 = 1:(T-1)
%     fr2 = fr1 + 1;
%     for i = 1:top_k
%         box1 = ((fr1-1)*top_k + i);
%         for j = 1:top_k
%             box2 = ((fr2-1)*top_k + j);
%             if (G(box1,box2) > binary_score_threshold)%~= 0)
%                 g_idx = g_idx + 1;
%                 gscore(g_idx,:) = [fr1, i, fr2, j, G(box1,box2)];
%             end %if
%         end %for j
%     end %for i
% end %for frame_idx1
% gscore = gscore(1:g_idx,:);
% gscore = sortrows(gscore,3);
% %might want to do sortrows(gscore,[1,3]) to sort by 1st then 3rd columns

%num_gscore = g_idx;
%fprintf('Elapsed time for output setup: %f\n',toc);
end %main function

