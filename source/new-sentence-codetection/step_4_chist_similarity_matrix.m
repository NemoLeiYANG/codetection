function [sim_chisq3d_full, sim_chisq2d_full, ...
          sim_emd3d_full, sim_emd2d_full,...
          sim_chisq3d_patch, sim_chisq2d_patch, ...
          sim_emd3d_patch, sim_emd2d_patch] = ...
    step_4_chist_similarity_matrix(dataset_dir, data_output_dirname, ...
                                   patch_size, num_patches)

%error check input
sim_chisq3d_full = []; sim_chisq2d_full = []; sim_emd3d_full = [];
sim_emd2d_full = []; sim_chisq3d_patch = []; sim_chisq2d_patch = [];
sim_emd3d_patch = []; sim_emd2d_patch = [];
if (mod(patch_size,2) ~= 1)    
    fprintf('ERROR: patch_size must be odd integer\n');
    return;
else
    p_pix = (patch_size - 1) / 2;
end %if
if(mod(sqrt(num_patches),1) ~= 0)
    fprintf('ERROR: num_patches must be square\n');
    return;
else
    p_num = sqrt(num_patches);
end %if
                               
%add paths for phow stuff (not sure this is necessary)
addpath(genpath('vlfeat/toolbox'));
run('/home/sbroniko/codetection/source/sentence-codetection/vlfeat/toolbox/vl_setup');

% TRY NOT explicitly setting up parfor to use default?
% enable parfor
pools = matlabpool('size');
cpus_available = feature('numCores');
if cpus_available > 8
    cpus = 8;
else
    cpus = cpus_available;% - 1; %UNCOMMENT IF USING SEYKHL
end
if pools ~= cpus
    if pools > 0
        matlabpool('close');
    end
    matlabpool('open', cpus);
end

%%load up images like previous

%start by getting plan directory names 
fprintf('Starting step_4_chist_similarity_matrix\n');
system('date');

tmp_dir_names = dir(dataset_dir);
dir_names = [];
for i = 1:length(tmp_dir_names)
    if((tmp_dir_names(i).isdir) && ~(strcmp(tmp_dir_names(i).name,'.'))...
        && ~(strcmp(tmp_dir_names(i).name,'..')))
        dir_names = [dir_names;tmp_dir_names(i).name];
    end %if
end %for i
[num_floorplans,~] = size(dir_names);
% dir_names

fv_color_hist = cell(num_floorplans,1);
fv_color_hist_patch = cell(num_floorplans,1);
temp_labels_by_floorplan = zeros(num_floorplans,1);

%then get fplabel dir names and set up cells
fplabel_dir_names = cell(num_floorplans,1);
for i = 1:num_floorplans
    fplabel_dir_names{i} = [];
    tmp_names = dir(strcat(dataset_dir,dir_names(i,:),'/',data_output_dirname));
    for j = 1:length(tmp_names)
        if ((tmp_names(j).isdir) && (strncmp(tmp_names(j).name,'fplabel',7)))
            %display(tmp_names(j).name);
            fplabel_dir_names{i} = [fplabel_dir_names{i};tmp_names(j).name];
        end
    end
    [temp_num_labels ,~] = size(fplabel_dir_names{i});
    temp_labels_by_floorplan(i) = temp_num_labels;
    fv_color_hist_patch{i} = cell(temp_num_labels,1);
    fv_color_hist{i} = cell(temp_num_labels,1);
end %for i
% temp_labels_by_floorplan
% fv_color_hist_patch
% fv_color_hist

% then load up fv_color_hist_patch and fv_color_hist from images
ch_num_bins = 8;%16; %HARDCODED for now
ch_cxform = makecform('srgb2lab');

for i = 1:num_floorplans
    read_dir = strcat(dataset_dir,dir_names(i,:),'/',data_output_dirname);
    fplabel_names = fplabel_dir_names{i};
    tmp_fv_ch_patch = cell(temp_labels_by_floorplan(i),1);
    tmp_fv_ch = cell(temp_labels_by_floorplan(i),1);
    parfor j = 1:temp_labels_by_floorplan(i)
        %Old way before filtering
        %img_dir = strcat(read_dir,'/',fplabel_names(j,:),'/'); 
        %new way
        img_dir = strcat(read_dir,'/',fplabel_names(j,:),'/accepted/');
        tmp_file_list = dir(img_dir);
        tmp_file_list = tmp_file_list(3:end); %because of . and ..
        num_files = numel(tmp_file_list);
        tmp_ch = zeros(3,ch_num_bins,num_files);
        tmp_ch_patch = zeros(3,ch_num_bins,num_files);
        for k = 1:num_files %for each image in fplabel dir
            img = imread(strcat(img_dir,tmp_file_list(k).name));
                        
            %histogram of full image
            [ch_out,~] = Lab_histogram(img,ch_num_bins,ch_cxform);
            
%             %histogram of patch at center of image
%             [img_h,img_w,~] = size(img);
%             img_h_center = round(img_h/2);
%             img_w_center = round(img_w/2);
%             img_patch = img(img_h_center-p_pix:img_h_center+p_pix,...
%                             img_w_center-p_pix:img_w_center+p_pix,:);
%             [ch_out_patch,~] = Lab_histogram(img_patch,ch_num_bins,ch_cxform);
            %make image of patches and take histogram of that
            [img_h, img_w,~] = size(img);
            %fprintf('img_h = %d, img_w = %d\n',img_h,img_w);
            img_h_seg = floor(img_h/(p_num+1));
            img_w_seg = floor(img_w/(p_num+1));
            %COULD have problems here with patch that exceeds image
            %size--check p_pix against h_seg and w_seg--how to fix???
            img_patch = zeros(p_num*patch_size,p_num*patch_size,3);
            for l = 1:p_num
                p_t = (l-1)*patch_size + 1; p_b = l*patch_size;
                img_t = l*img_h_seg - p_pix; img_b = l*img_h_seg + p_pix;
%                 fprintf('p_t = %d, p_b = %d, img_t = %d, img_b = %d ',...
%                     p_t, p_b, img_t, img_b);
                for m = 1:p_num
                    p_l = (m-1)*patch_size + 1; p_r = m*patch_size;
                    img_l = m*img_w_seg - p_pix; img_r = m*img_w_seg + p_pix;
%                     fprintf('p_l = %d, p_r = %d, img_l = %d, img_r = %d\n',...
%                         p_l, p_r, img_l, img_r);
                    img_patch(p_t:p_b,p_l:p_r,:) = ...
                        img(img_t:img_b,img_l:img_r,:);
                end %for m
            end %for l
                
            [ch_out_patch,~] = Lab_histogram(img_patch,ch_num_bins,ch_cxform);

            tmp_ch(:,:,k) = ch_out;
            tmp_ch_patch(:,:,k) = ch_out_patch;
        end %for k
     tmp_fv_ch_patch{j} = tmp_ch_patch;
     tmp_fv_ch{j} = tmp_ch;
    end %parfor j
    fv_color_hist_patch{i} = tmp_fv_ch_patch;
    fv_color_hist{i} = tmp_fv_ch;
end %for i
fprintf('feature_vectors built\n');
system('date');

%set up output variables
M = sum(temp_labels_by_floorplan);
% M
sim_chisq3d_full = zeros(M); sim_chisq2d_full = zeros(M); 
sim_emd3d_full = zeros(M); sim_emd2d_full = zeros(M); 
sim_chisq3d_patch = zeros(M); sim_chisq2d_patch = zeros(M);
sim_emd3d_patch = zeros(M); sim_emd2d_patch = zeros(M);

%%do group-by-group comparison (matrix)
for i = 1:M %map-vector
    [new_i,new_j] = find_indices(i,temp_labels_by_floorplan);
    [num_img_i,~] = size(fv_color_hist{new_i}{new_j});
    for j = i:M %trying with self-similarity instead of i+1:M map-vector
        [new_i2,new_j2] = find_indices(j,temp_labels_by_floorplan);
        [num_img_j,~] = size(fv_color_hist{new_i2}{new_j2});
        s_mat_1 = zeros(num_img_i, num_img_j); %sim_chisq3d_full
        s_mat_2 = zeros(num_img_i, num_img_j); %sim_chisq2d_full
        s_mat_3 = zeros(num_img_i, num_img_j); %sim_emd3d_full
        s_mat_4 = zeros(num_img_i, num_img_j); %sim_emd2d_full
        s_mat_5 = zeros(num_img_i, num_img_j); %sim_chisq3d_patch
        s_mat_6 = zeros(num_img_i, num_img_j); %sim_chisq2d_patch
        s_mat_7 = zeros(num_img_i, num_img_j); %sim_emd3d_patch
        s_mat_8 = zeros(num_img_i, num_img_j); %sim_emd2d_patch
        full_hists1 = fv_color_hist{new_i}{new_j};
        full_hists2 = fv_color_hist{new_i2}{new_j2};
        patch_hists1 = fv_color_hist_patch{new_i}{new_j};
        patch_hists2 = fv_color_hist_patch{new_i2}{new_j2};
        parfor k = 1:num_img_i %let with 2 nested map-vectors
            full1 = full_hists1(:,:,k);
            patch1 = patch_hists1(:,:,k);
            temp_vec1 = zeros(1,num_img_j); temp_vec2 = zeros(1,num_img_j);
            temp_vec3 = zeros(1,num_img_j); temp_vec4 = zeros(1,num_img_j);
            temp_vec5 = zeros(1,num_img_j); temp_vec6 = zeros(1,num_img_j);
            temp_vec7 = zeros(1,num_img_j); temp_vec8 = zeros(1,num_img_j);           
            for l = 1:num_img_j
                full2 = full_hists2(:,:,l);
                patch2 = patch_hists2(:,:,l);
                temp_vec1(l) = histogram_distance(full1,full2,'chisq',3);
                temp_vec2(l) = histogram_distance(full1,full2,'chisq',2);
                temp_vec3(l) = histogram_distance(full1,full2,'emd',3);
                temp_vec4(l) = histogram_distance(full1,full2,'emd',2);
                temp_vec5(l) = histogram_distance(patch1,patch2,'chisq',3);
                temp_vec6(l) = histogram_distance(patch1,patch2,'chisq',2);
                temp_vec7(l) = histogram_distance(patch1,patch2,'emd',3);
                temp_vec8(l) = histogram_distance(patch1,patch2,'emd',2);
            end %for l
            s_mat_1(k,:) = temp_vec1; %sim_chisq3d_full
            s_mat_2(k,:) = temp_vec2; %sim_chisq2d_full
            s_mat_3(k,:) = temp_vec3; %sim_emd3d_full
            s_mat_4(k,:) = temp_vec4; %sim_emd2d_full
            s_mat_5(k,:) = temp_vec5; %sim_chisq3d_patch
            s_mat_6(k,:) = temp_vec6; %sim_chisq2d_patch
            s_mat_7(k,:) = temp_vec7; %sim_emd3d_patch
            s_mat_8(k,:) = temp_vec8; %sim_emd2d_patch            
        end %for k
        %%vectorize matrix and take best N percent of scores (best scores
        %%are low b/c we are using distance metrics)
        N = 0.3; %HARDCODED for 30 percent
        N1 = round(N*numel(s_mat_1)); N2 = round(N*numel(s_mat_2));
        N3 = round(N*numel(s_mat_3)); N4 = round(N*numel(s_mat_4));
        N5 = round(N*numel(s_mat_5)); N6 = round(N*numel(s_mat_6));
        N7 = round(N*numel(s_mat_7)); N8 = round(N*numel(s_mat_8));
        sorted_1 = sort(s_mat_1(:),'ascend');%sim_chisq3d_full
        sorted_2 = sort(s_mat_2(:),'ascend');%sim_chisq2d_full
        sorted_3 = sort(s_mat_3(:),'ascend');%sim_emd3d_full
        sorted_4 = sort(s_mat_4(:),'ascend');%sim_emd2d_full
        sorted_5 = sort(s_mat_5(:),'ascend');%sim_chisq3d_patch
        sorted_6 = sort(s_mat_6(:),'ascend');%sim_chisq2d_patch
        sorted_7 = sort(s_mat_7(:),'ascend');%sim_emd3d_patch
        sorted_8 = sort(s_mat_8(:),'ascend');%sim_emd2d_patch
        best_1 = sorted_1(1:N1); best_2 = sorted_2(1:N2);
        best_3 = sorted_3(1:N3); best_4 = sorted_4(1:N4);
        best_5 = sorted_5(1:N5); best_6 = sorted_6(1:N6);
        best_7 = sorted_7(1:N7); best_8 = sorted_8(1:N8);
        %%average those best scores and use as similarity measure
        sim_1 = mean(best_1); sim_2 = mean(best_2); sim_3 = mean(best_3);
        sim_4 = mean(best_4); sim_5 = mean(best_5); sim_6 = mean(best_6);
        sim_7 = mean(best_7); sim_8 = mean(best_8);
        
        sim_chisq3d_full(i,j) = sim_1; sim_chisq3d_full(j,i) = sim_1;
        sim_chisq2d_full(i,j) = sim_2; sim_chisq2d_full(j,i) = sim_2;
        sim_emd3d_full(i,j) = sim_3; sim_emd3d_full(j,i) = sim_3;
        sim_emd2d_full(i,j) = sim_4; sim_emd2d_full(j,i) = sim_4;
        sim_chisq3d_patch(i,j) = sim_5; sim_chisq3d_patch(j,i) = sim_5;
        sim_chisq2d_patch(i,j) = sim_6; sim_chisq2d_patch(j,i) = sim_6;
        sim_emd3d_patch(i,j) = sim_7; sim_emd3d_patch(j,i) = sim_7;
        sim_emd2d_patch(i,j) = sim_8; sim_emd2d_patch(j,i) = sim_8;
    end %for j
end %for i
fprintf('Similarity matrices computed\n');
system('date');
matlabpool('close'); %kill parallel workers
end %function (main)

function [i_out,j_out] = find_indices(i_in,M)
    len = numel(M);
    for a = 1:len
        running_total = sum(M(1:a));
        if (i_in <= running_total)
            i_out = a;
            j_out = i_in - sum(M(1:a-1));
            return;
        end %if
    end %for a
end %function