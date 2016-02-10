function img_score = find_img_objectness_score(img,box,cues,params) %(img,box,cues,params)
% scores = zeros(1,length(cues));
% for i = 1:length(cues)
%     foo = computeScores(img,cues{i},params,box);
%     scores(i) = foo(5);
% end %for i
% img_score = integrateBayes(cues,scores,params);
[h,w,~] = size(img);
scale = 1.2; %HARDCODING image scale factor
numboxes = 10; %HARDCODING number of boxes to output
%convert original image box into x y w h
origbox = [1,1,(box(3)-box(1)+1),(box(4)-box(2)+1)];
origboxarea = origbox(3)*origbox(4);
%give box some margins
[x1,y1,x2,y2] = resize_box(box,h,w,scale);
boxscores = runObjectness(img(y1:y2,x1:x2,:),numboxes,params);
%boxes come out as [xmin ymin xmax ymax score], so convert to [x y w h s]
% for use with rectint
boxscores(:,3) = boxscores(:,3) - boxscores(:,1) + 1;
boxscores(:,4) = boxscores(:,4) - boxscores(:,2) + 1;
%boxscores
%convert new img box to x y w h
imgbox = double([1,1,(x2-x1+1),(y2-y1+1)]);
imgboxarea = imgbox(3)*imgbox(4);
boxscores(:,6) = boxscores(:,3) .* boxscores(:,4); %box areas
boxscores(:,7) = rectint(boxscores(:,1:4),origbox); %intersections
boxscores(:,8)=boxscores(:,6)./imgboxarea; %overlap w/expanded box
%boxscores(:,8)
%get rid of boxes that overlap by > thresh
%key to ratio of origbox to imgbox
olthresh = 0.9;
idx = boxscores(:,8) > olthresh;
boxscores(idx,:) = [];
%now do IoU for remaining boxes
boxscores(:,9) = boxscores(:,7) ./ ... %IoU for ORIGINAL box
    (boxscores(:,6) + origboxarea - boxscores(:,7));
boxscores(:,8)
boxscores(:,5)
boxscores(:,9)
%multiply IoU by original objectness score
newscores = boxscores(:,9) .* boxscores(:,5)

imgboxarea
origboxarea
1.1*origboxarea/imgboxarea

img_score = [mean(newscores), median(newscores), max(newscores)];

% meanscore = mean(boxscores(:,5));
% areas = (boxes(:,3)-boxes(:,1)) .* (boxes(:,4)-boxes(:,2));
% areascores = [areas scores];
% areascores = sortrows(areascores);
% boxscores(1,:)
% img_score = [meanscore,areascores(numboxes,2)];

end %function

function [x1,y1,x2,y2] = resize_box(box, im_height, im_width, scale)
cx = (box(1)+box(3)) / 2;
cy = (box(2)+box(4)) / 2;
new_w = (box(3)-box(1)+1) * scale;
new_h = (box(4)-box(2)+1) * scale;
x1 = int32(max(1, cx-new_w/2));
y1 = int32(max(1, cy-new_h/2));
x2 = int32(min(im_width, cx+new_w/2));
y2 = int32(min(im_height, cy+new_h/2));
end %function