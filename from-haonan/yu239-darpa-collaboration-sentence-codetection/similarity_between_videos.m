function simi = similarity_between_videos(frames1, frames2, boxes1, ...
                                          boxes2, video_dir1, video_dir2, T, top_k, n_orients)
addpath(genpath('piotr-toolbox'));
addpath(genpath('vlfeat/toolbox'));
run('vlfeat/toolbox/vl_setup');

model = load('phow-model/vocab.mat');
vocab = model.vocab;

% c code coordinate starts from 0
boxes1 = int32(boxes1(:,1:4)) + 1;
boxes2 = int32(boxes2(:,1:4)) + 1;

tmp_phow_feats1 = cell(T*top_k*n_orients);
tmp_phow_feats2 = cell(T*top_k*n_orients);

for t = 0:T-1
    img1 = frames1(:,:,:,t+1);
    img2 = frames2(:,:,:,t+1);
    [h, w, ~] = size(img1);
    for k = 0:top_k-1
        box_idx = t*top_k;    
        bs1 = boxes1(box_idx+1:box_idx+top_k,:);        
        bi1 = bs1(k+1,:);
        bi1 = resize_box(bi1, h, w, 1.2);
        roi1 = img1(bi1(2):bi1(4),bi1(1):bi1(3),:);    
        bs2 = boxes2(box_idx+1:box_idx+top_k,:);
        bi2 = bs2(k+1,:);
        bi2 = resize_box(bi2, h, w, 1.2);
        roi2 = img2(bi2(2):bi2(4),bi2(1):bi2(3),:);
        for j = 0:n_orients-1                
            if j > 0 
                roi1 = imrotate(roi1, 360/n_orients, 'bilinear');
                roi2 = imrotate(roi2, 360/n_orients, 'bilinear');
            end
            it = (t*top_k+k)*n_orients+j;
            tmp_phow_feats1{it+1} = phow_hist(roi1, 64, vocab);
            tmp_phow_feats2{it+1} = phow_hist(roi2, 64, vocab);
        end                
    end
end

for t = 0:T-1
    for k = 0:top_k-1
        for j = 0:n_orients-1
            it = (t*top_k+k)*n_orients+j;
            phow_feats1(:,k+1,j+1,t+1) = tmp_phow_feats1{it+1};
            phow_feats2(:,k+1,j+1,t+1) = tmp_phow_feats2{it+1};
        end
    end
end

simi_tmp = cell(T*n_orients);
simi_max = -inf;
simi_min = inf;
for it = 0:T*n_orients-1        
    j = mod(it,n_orients);
    t = floor(it/n_orients);
    simi_tmp{it+1} = pdist2(phow_feats1(:,:,j+1,t+1)', ...
                            phow_feats2(:,:,1,t+1)', 'chisq');
    simi_max = max(simi_max, max(simi_tmp{it+1}(:)));
    simi_min = min(simi_min, min(simi_tmp{it+1}(:)));
end

for t = 0:T-1
    for j = 0:n_orients-1
        % top_k by top_k by n_orients by T by M
        simi(:,:,j+1,t+1) = ...
            log(1-(simi_tmp{t*n_orients+j+1}-simi_min)...
                ./ (simi_max-simi_min));
    end
end

% to save disk space by half
simi = single(simi);

% write simi
[root_dir, video1] = fileparts(video_dir1);
[root_dir, video2] = fileparts(video_dir2);
simi_dir = [root_dir, '/similarity'];
if ~exist(simi_dir, 'dir'), system(['mkdir -p ', simi_dir]); end
simi_file = [simi_dir, '/', video1, '__', video2, '.mat'];
save(simi_file, 'simi');

simi = double(simi);


function new_box = resize_box(box, im_height, im_width, scale)
cx = (box(1)+box(3)) / 2;
cy = (box(2)+box(4)) / 2;
new_w = (box(3)-box(1)+1) * scale;
new_h = (box(4)-box(2)+1) * scale;
x1 = max(1, cx-new_w/2);
y1 = max(1, cy-new_h/2);
x2 = min(im_width, cx+new_w/2);
y2 = min(im_height, cy+new_h/2);
new_box = [int32(x1),int32(y1),int32(x2),int32(y2)];