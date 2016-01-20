function [computed, bboxes_t, bboxes] = check_proposals(top_k, video_dir)
%
computed = 1; 
bboxes_t = 0;
bboxes = [];
data_file = [video_dir, '/codetection-data/proposals.mat'];
if ~exist(data_file, 'file'), computed = 0; return; end
% load precomputed proposals
load(data_file, 'bboxes');
[num_boxes,~,bboxes_t] = size(bboxes);
% not enough proposals on each frame
if num_boxes < top_k, computed = 0; return; end
bboxes = bboxes(1:top_k,:,:);
