function bbs = mcg_boxes(I, N)
% proposals:
%         scores: [4333x1 double]
%         bboxes: [4333x4 double]
%    superpixels: [480x640 uint32]
%         labels: {4333x1 cell}
% bbs (x1, y1, x2, y2)
[proposals, ~] = im2mcg(I, 'fast');
max_boxes_n = size(proposals.bboxes, 1);
N = min(N, max_boxes_n);
bbs = [proposals.bboxes(1:N,[2,1,4,3]), proposals.scores(1:N)];