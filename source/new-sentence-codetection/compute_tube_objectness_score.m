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
        
