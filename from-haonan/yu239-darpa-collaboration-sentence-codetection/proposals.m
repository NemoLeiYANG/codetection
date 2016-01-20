function [bboxes_t, bboxes] = proposals(top_k, frames, video_dir, b_write)
%
% compute proposals and write to disk
%
% add paths
addpath(genpath('piotr-toolbox'));
addpath(genpath('vlfeat/toolbox'));
cd MCG; install; cd ..; % MCG install
run('vlfeat/toolbox/vl_setup');

data_dir = [video_dir, '/codetection-data'];
if ~exist(data_dir, 'dir'), system(['mkdir -p ', data_dir]); end

% enable parfor
if false
    pools = matlabpool('size');
    cpus = feature('numCores');
    if pools ~= (cpus - 1)
        if pools > 0
            matlabpool('close');
        end
        matlabpool('open', cpus - 1);
    end
end

% compute boxes
T = size(frames, 4);
bboxes = zeros(top_k, 5, T);
for t = 1:T
    img = frames(:,:,:,t);
    if false
        %% forest edge boxes
        threads_n = 5;
        % somehow forest edge conflicts with MCG
        addpath(genpath('forests_edges_boxes'));
        bbs = edgeBoxesOut(img, int32(top_k/2), threads_n);
        bbs(:,3) = bbs(:,3) + bbs(:,1) - 1;
        bbs(:,4) = bbs(:,4) + bbs(:,2) - 1;
        rmpath(genpath('forests_edges_boxes'));
    end
    %% MCG boxes
    bbs = mcg_boxes(img, top_k);
    % sort the scores
    [~,idx] = sort(bbs(:,5));
    bbs = bbs(idx, :);
    % permute the boxes
    %    bbs = bbs(randperm(top_k),:);
    % pad the boxes with the last one
    if size(bbs,1) < top_k
        bbs = [bbs; repmat(bbs(end,:),top_k-size(bbs,1),1)];
    end        
    bboxes(:,:,t) = bbs;
end

% write boxes
if b_write
    save([data_dir,'/proposals.mat'], 'bboxes');
end
bboxes_t = size(bboxes, 3);

