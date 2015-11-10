function [sim_mat_chisq_full, sim_mat_emd_full...
    sim_mat_chisq_patch, sim_mat_emd_patch] = histogram_testing(base_dir,num)

imgs_per_class = 3;

%get directory names
tmp_dir = dir(base_dir);
dir_names = [];
for i = 1:numel(tmp_dir)
    if((tmp_dir(i).isdir) && ~(strcmp(tmp_dir(i).name,'.')) ...
            && ~(strcmp(tmp_dir(i).name,'..')))
        %tmp_dir(i).name
        dir_names = [dir_names;tmp_dir(i).name];
    end%if
end %for i
[num_dirs,~] = size(dir_names);

%load a random selection of images
imgs = cell(num_dirs*imgs_per_class,1);
for i = 1:num_dirs
    img_dir = strcat(base_dir,dir_names(i),'/');
    f_names = dir(img_dir);
    f_names = f_names(3:end);%for . and ..
    num_imgs = numel(f_names); 
    temp_perm = randperm(num_imgs);
    for j = 1:imgs_per_class
        imgs{(i-1)*imgs_per_class+j} = ...
            imread(strcat(img_dir,f_names(temp_perm(j)).name));
    end %for j
end %for i

%show images
h=figure();
set(h,'Position',[0 0 1200 800]);
for i = 1:num_dirs
    for j = 1:imgs_per_class
        subplot(num_dirs,imgs_per_class,((i-1)*imgs_per_class)+j),...
            imshow(imgs{(i-1)*imgs_per_class+j});
    end %for j
end %for i
suptitle('Random images from each class');

%SAVING
savestr = strcat('./color-histogram-test-results/',num2str(num,'%02d'),'-images.png');
saveas(gcf,savestr);

%run test on full images
sim_mat_chisq_full = test_lab_hist(imgs,8,'chisq',3);
sim_mat_emd_full = test_lab_hist(imgs,8,'emd',3);

%plot
figure();
imagesc(sim_mat_chisq_full); hold on; 
set(gca,'xtick',0:imgs_per_class:(imgs_per_class*num_dirs)); 
set(gca,'ytick',0:imgs_per_class:(imgs_per_class*num_dirs));
colorbar; title('Similarity for FULL images, 8 bins, chisq, 3d'); hold off;

%SAVING
savestr = strcat('./color-histogram-test-results/',num2str(num,'%02d'),'-chisq-full.png');
saveas(gcf,savestr);


figure();
imagesc(sim_mat_emd_full); hold on; 
set(gca,'xtick',0:imgs_per_class:(imgs_per_class*num_dirs)); 
set(gca,'ytick',0:imgs_per_class:(imgs_per_class*num_dirs));
colorbar; title('Similarity for FULL images, 8 bins, emd, 3d'); hold off;

%SAVING
savestr = strcat('./color-histogram-test-results/',num2str(num,'%02d'),'-emd-full.png');
saveas(gcf,savestr);

%run test on center patches (7x7)
imgs_patch = cell(num_dirs*imgs_per_class,1);
for i = 1:(num_dirs*imgs_per_class)
    [ht,wd,~] = size(imgs{i});
    hc = round(ht/2); wc = round(wd/2);
    imgs_patch{i} = imgs{i}(hc-3:hc+3,wc-3:wc+3,:);
end %for i
sim_mat_chisq_patch = test_lab_hist(imgs_patch,8,'chisq',3);
sim_mat_emd_patch = test_lab_hist(imgs_patch,8,'emd',3);

%plot
figure();
imagesc(sim_mat_chisq_patch); hold on; 
set(gca,'xtick',0:imgs_per_class:(imgs_per_class*num_dirs)); 
set(gca,'ytick',0:imgs_per_class:(imgs_per_class*num_dirs));
colorbar; 
title('Similarity for center patch of images, 8 bins, chisq, 3d'); 
hold off;

%SAVING
savestr = strcat('./color-histogram-test-results/',num2str(num,'%02d'),'-chisq-patch.png');
saveas(gcf,savestr);

figure();
imagesc(sim_mat_emd_patch); hold on; 
set(gca,'xtick',0:imgs_per_class:(imgs_per_class*num_dirs)); 
set(gca,'ytick',0:imgs_per_class:(imgs_per_class*num_dirs));
colorbar; 
title('Similarity for center patch of images, 8 bins, emd, 3d'); 
hold off;

%SAVING
savestr = strcat('./color-histogram-test-results/',num2str(num,'%02d'),'-emd-patch.png');
saveas(gcf,savestr);


end %function