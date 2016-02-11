function tube_score = compute_tube_objectness_score(vid,framenums,boxes,params)
%cues={'CC','ED','SS'};
%convert from scheme to matlab numbering
framenums = framenums + 1;
boxes = boxes(:,1:4) + 1;
[~,nframes] = size(framenums);
scores = zeros (1,nframes);
%[img_h,img_w,~] = size(vid(:,:,:,1));
newvid = vid(:,:,:,framenums);
parfor n = 1:nframes
    img = newvid(:,:,:,n);
    box = boxes(n,:);
    scores(n) = find_img_objectness_score(img,box,params);       
end %parfor
tube_score=median(scores);%mean(scores);
end %function
        
