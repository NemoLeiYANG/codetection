function mean_obj_score = compute_tube_objectness_score(vid,framenums,boxes)
cues={'CC','ED','SS'};
%convert from scheme to matlab numbering
framenums = framenums + 1;
boxes = boxes(:,1:4) + 1;
[~,nframes] = size(framenums);
scores = zeros (1,nframes);
[img_h,img_w,~] = size(vid(:,:,:,1));
newvid = vid(:,:,:,framenums);
parfor n = 1:nframes
    img = newvid(:,:,:,n);
    box = boxes(n,:);
    [x1,y1,x2,y2] = resize_box(box,img_h,img_w,1.2);
    
        
end %parfor
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