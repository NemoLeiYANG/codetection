function [boxes_w_fscore, gscore] = ...
    scott_proposals_similarity(top_k, box_size, frames, positions)
%inputs: top_k, box_size same as Haonan's code
%        frames: h*w*3*num_frames matrix of images
%        positions: 3*num_frames matrix of [x y theta]
%   ???do I need some other parameters here (like weighting for
%   different components of scores)
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


end %function