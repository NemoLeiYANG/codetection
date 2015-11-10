function bboxes = MCGboxes(img, numboxes)

%  Generate proposal boxes using MCG package presented in:
%    Arbelaez P, Pont-Tuset J, Barron J, Marques F, Malik J,
%    "Multiscale Combinatorial Grouping,"
%    Computer Vision and Pattern Recognition (CVPR) 2014.
%
% inputs: img -- input image
%         numboxes -- number of boxes to return
%
% outputs: bboxes -- numboxes x 5 array of [x y w h score]

% ENSURE THIS PATH IS ADDED BEFORE CALLING: addpath(genpath('MCG-PreTrained'));
%compute boxes
[output_scg, ~] = im2mcg(img,'fast');
%massage output
outboxes = [output_scg.bboxes output_scg.scores];
outboxes = sortrows(outboxes,-5); %descending scort by score
bboxes = zeros(numboxes,5);
bboxes(:,1) = outboxes(1:numboxes,2); %x
bboxes(:,2) = outboxes(1:numboxes,1); %y
bboxes(:,3) = outboxes(1:numboxes,4) - outboxes(1:numboxes,2); %w
bboxes(:,4) = outboxes(1:numboxes,3) - outboxes(1:numboxes,1); %h
bboxes(:,5) = outboxes(1:numboxes,5); %score
end %function