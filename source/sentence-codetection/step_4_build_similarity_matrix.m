function ... %[fv_dsift, fv_color_hist, similarity_matrix] = ...
    [sim_dsift_chisq, sim_dsift_emd, sim_chist_chisq3d, sim_chist_emd3d...
    sim_chist_chisq2d,sim_chist_emd2d] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,m_factor)



% %add paths for phow stuff (not sure this is necessary)
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

%start by getting plan directory names 
fprintf('Starting step_4_build_similarity_matrix\n');
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
%dir_names

fv_dsift = cell(num_floorplans,1);
fv_color_hist = cell(num_floorplans,1);
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
    fv_dsift{i} = cell(temp_num_labels,1);
    fv_color_hist{i} = cell(temp_num_labels,1);
end %for i
% temp_labels_by_floorplan
% fv_dsift
% fv_color_hist


% then load up fv_dsift and fv_color_hist from images
ssize = 64; %HARDCODED ssize: the size to which each proposal is rescaled 
%               to (for phow_hist); ssize should be 2^i; increase i to 
%               trade efficiency for accuracy

ch_num_bins = 8;%16; %HARDCODED for now
ch_cxform = makecform('srgb2lab');
% ch_num_bins = 4;%16; %HARDCODED for now
% ch_numel = ch_num_bins^3;

% dsift_weight = 1; %HARDCODED for now
% chist_weight = 1;
% weightsum = dsift_weight+chist_weight;
% dsift_norm = dsift_weight/weightsum;
% chist_norm = chist_weight/weightsum;

for i = 1:num_floorplans
    read_dir = strcat(dataset_dir,dir_names(i,:),'/',data_output_dirname);
    fplabel_names = fplabel_dir_names{i};
    tmp_fv_dsift = cell(temp_labels_by_floorplan(i),1);
    tmp_fv_ch = cell(temp_labels_by_floorplan(i),1);
    parfor j = 1:temp_labels_by_floorplan(i)
        %Old way before filtering
        img_dir = strcat(read_dir,'/',fplabel_names(j,:),'/'); 
%         %new way COMMENTED OUT for ralicra2016 run
%         img_dir = strcat(read_dir,'/',fplabel_names(j,:),'/accepted/');
        tmp_file_list = dir(img_dir);
        num_files = numel(tmp_file_list) - 2; % -2 is because of . and ..
        tmp_phists = zeros(num_files, 12000,'single'); %HARDCODED for phist size
        %tmp_ch = zeros(num_files, ch_numel,'single');
        tmp_ch = zeros(3,ch_num_bins,num_files);
        for k = 1:num_files %for each image in fplabel dir
            img = imread(strcat(img_dir,tmp_file_list(k+2).name));
            hist_out = phow_hist(img,ssize);
            %ch_out = rgbhist_fast(img,ch_num_bins,1);
            
            %old way--histogram of full image
            %[ch_out,~] = Lab_histogram(img,ch_num_bins,ch_cxform);
            
            %new way--histogram of small area at center of image
            numPix = 3; %number of patch pixels on either side of center (i.e, 3 means a 7x7 patch)
            [img_h,img_w,~] = size(img);
            img_h_center = round(img_h/2);
            img_w_center = round(img_w/2);
            img_patch = img(img_h_center-numPix:img_h_center+numPix,...
                            img_w_center-numPix:img_w_center+numPix,:);
            [ch_out,~] = Lab_histogram(img_patch,ch_num_bins,ch_cxform);
            
            tmp_phists(k,:) = hist_out';
            tmp_ch(:,:,k) = ch_out;
        end %for k
     tmp_fv_dsift{j} = tmp_phists;
     tmp_fv_ch{j} = tmp_ch;
    end %parfor j
    fv_dsift{i} = tmp_fv_dsift;
    fv_color_hist{i} = tmp_fv_ch;
end %for i

fprintf('feature_vectors built\n');
system('date');

%now do comparisons between image feature vectors across floorplans
M = sum(temp_labels_by_floorplan);
%similarity_matrix = zeros(M,'single');
sim_dsift_chisq = zeros(M,'single');
sim_dsift_emd = zeros(M,'single');
% sim_chist_chisq = zeros(M,'single');
% sim_chist_emd = zeros(M,'single');

sim_chist_chisq3d = zeros(M);
sim_chist_emd3d = zeros(M);
sim_chist_chisq2d = zeros(M);
sim_chist_emd2d = zeros(M);
% n_factor = 0.5; %used in condensing simi_matrix
%m_factor = 0.5; %USED AS INPUT PARAMETER NOW

for i = 1:M %map-vector
    [new_i,new_j] = find_indices(i,temp_labels_by_floorplan);
    [num_img_i,~] = size(fv_dsift{new_i}{new_j});
    for j = i:M %trying with self-similarity instead of i+1:M map-vector
        [new_i2,new_j2] = find_indices(j,temp_labels_by_floorplan);
        [num_img_j,~] = size(fv_dsift{new_i2}{new_j2});
        simi_matrix = zeros(num_img_i,num_img_j,'single'); %dsift chisq
        simi_matrix2 = zeros(num_img_i,num_img_j); %chist chisq 3d
        simi_matrix3 = zeros(num_img_i,num_img_j,'single'); %dsift emd
        simi_matrix4 = zeros(num_img_i,num_img_j); %chisq emd 3d
        simi_matrix5 = zeros(num_img_i,num_img_j); %chisq chisq 2d
        simi_matrix6 = zeros(num_img_i,num_img_j); %chisq emd 2d
        temp_hists1 = fv_dsift{new_i}{new_j};
        temp_hists2 = fv_dsift{new_i2}{new_j2};
        temp_hists3 = fv_color_hist{new_i}{new_j};
        temp_hists4 = fv_color_hist{new_i2}{new_j2};
        parfor k = 1:num_img_i %let with 2 nested map-vectors
            %hist1 = feature_vectors{new_i}{new_j}(k,:);
            hist1 = temp_hists1(k,:);
            hist3 = temp_hists3(:,:,k);
            temp_mat = zeros(1,num_img_j);
            temp_mat2 = zeros(1,num_img_j);
            temp_mat3 = zeros(1,num_img_j);
            temp_mat4 = zeros(1,num_img_j);
            temp_mat5 = zeros(1,num_img_j);
            temp_mat6 = zeros(1,num_img_j);
            for l = 1:num_img_j
                %hist2 = feature_vectors{new_i2}{new_j2}(l,:);
                hist2 = temp_hists2(l,:);
                temp_mat(l) = 1 - pdist2(hist1,hist2,'chisq');
                temp_mat3(l) = pdist2(hist1,hist2,'emd');
                hist4 = temp_hists4(:,:,l);
%                 temp_mat2(l) = 1 - pdist2(hist3,hist4,'chisq');
%                 temp_mat4(l) = pdist2(hist3,hist4,'emd');
                temp_mat2(l) = histogram_distance(hist3,hist4,'chisq',3);
                temp_mat4(l) = histogram_distance(hist3,hist4,'emd',3);
                temp_mat5(l) = histogram_distance(hist3,hist4,'chisq',2);
                temp_mat6(l) = histogram_distance(hist3,hist4,'emd',2);
            end %for l
            simi_matrix(k,:) = temp_mat; %d-c
            simi_matrix2(k,:) = temp_mat2; %c-c3
            simi_matrix3(k,:) = temp_mat3; %d-e
            simi_matrix4(k,:) = temp_mat4; %c-e3
            simi_matrix5(k,:) = temp_mat5; %c-c2
            simi_matrix6(k,:) = temp_mat6; %c-e2
        end %for k
        %         %atempt 2: 1b, 2a
%         [num_col_elements,num_row_elements] = size(simi_matrix);
%         simi_sorted_cols = sort(simi_matrix,'descend');
%         simi_sorted_rows = sort(simi_matrix,2,'descend');
%         n_rows = round(n_factor*num_row_elements);
%         n_cols = round(n_factor*num_col_elements);
%         row_means = mean(simi_sorted_rows(:,1:n_rows),2);
%         col_means = mean(simi_sorted_cols(1:n_cols,:),1);
%         avg_simi = mean(row_means);
%         avg_simi2 = mean(col_means);
        
%         %attempt 1: 1a, 2a %LAST WORKING CONFIGURATION A/O 1JUL15
%         row_maxes = max(simi_matrix,[],2);
%         col_maxes = max(simi_matrix,[],1);
%         avg_simi = mean(row_maxes);
%         avg_simi2 = mean(col_maxes);
        
        %MAYBE try something with 1a, 2b here.
        
%         simi_matrix(1:7,1:7)
%         simi_matrix3(1:7,1:7)
        
        %dsift chisq
        row_maxes = max(simi_matrix,[],2);
        col_maxes = max(simi_matrix,[],1);
        sorted_row_maxes = sort(row_maxes,'descend');
        sorted_col_maxes = sort(col_maxes,'descend');
        n_r_elem = round(m_factor*length(row_maxes));
        n_c_elem = round(m_factor*length(col_maxes));
        avg_simi = mean(sorted_row_maxes(1:n_r_elem));
        avg_simi2 = mean(sorted_col_maxes(1:n_c_elem));
        
        %chist chisq 3d
%         row_maxes2 = max(simi_matrix2,[],2);
%         col_maxes2 = max(simi_matrix2,[],1);
%         sorted_row_maxes2 = sort(row_maxes2,'descend');
%         sorted_col_maxes2 = sort(col_maxes2,'descend');
%         n_r_elem2 = round(m_factor*length(row_maxes2));
%         n_c_elem2 = round(m_factor*length(col_maxes2));
%         avg_simi3 = mean(sorted_row_maxes2(1:n_r_elem2));
%         avg_simi4 = mean(sorted_col_maxes2(1:n_c_elem2));
        row_m = min(simi_matrix2,[],2);
        col_m = min(simi_matrix2,[],1);
        sorted_row_m = sort(row_m,'ascend');
        sorted_col_m = sort(col_m,'ascend');
        n_r_elem2 = round(m_factor*length(row_m));
        n_c_elem2 = round(m_factor*length(col_m));
        avg_simi3 = mean(sorted_row_m(1:n_r_elem2));
        avg_simi4 = mean(sorted_col_m(1:n_c_elem2));      
        
        %dsift emd
        row_mins = min(simi_matrix3,[],2);
        col_mins = min(simi_matrix3,[],1);
        sorted_row_mins = sort(row_mins,'ascend');
        sorted_col_mins = sort(col_mins,'ascend');
        n_r_elem3 = round(m_factor*length(row_mins));
        n_c_elem3 = round(m_factor*length(col_mins));
        avg_simi5 = mean(sorted_row_mins(1:n_r_elem3));
        avg_simi6 = mean(sorted_col_mins(1:n_c_elem3));
        
        %chist emd 3d
        row_mins2 = min(simi_matrix4,[],2);
        col_mins2 = min(simi_matrix4,[],1);
        sorted_row_mins2 = sort(row_mins2,'ascend');
        sorted_col_mins2 = sort(col_mins2,'ascend');
        n_r_elem4 = round(m_factor*length(row_mins2));
        n_c_elem4 = round(m_factor*length(col_mins2));
        avg_simi7 = mean(sorted_row_mins2(1:n_r_elem4));
        avg_simi8 = mean(sorted_col_mins2(1:n_c_elem4));
        
        %chist chisq 2d
        row_m2 = min(simi_matrix5,[],2);
        col_m2 = min(simi_matrix5,[],1);
        sorted_row_m2 = sort(row_m2,'ascend');
        sorted_col_m2 = sort(col_m2,'ascend');
        n_r_elem5 = round(m_factor*length(row_m2));
        n_c_elem5 = round(m_factor*length(col_m2));
        avg_simi9 = mean(sorted_row_m2(1:n_r_elem5));
        avg_simi10 = mean(sorted_col_m2(1:n_c_elem5));        
        
        %chist emd 2d
        row_m3 = min(simi_matrix6,[],2);
        col_m3 = min(simi_matrix6,[],1);
        sorted_row_m3 = sort(row_m3,'ascend');
        sorted_col_m3 = sort(col_m3,'ascend');
        n_r_elem6 = round(m_factor*length(row_m3));
        n_c_elem6 = round(m_factor*length(col_m3));
        avg_simi11 = mean(sorted_row_m3(1:n_r_elem6));
        avg_simi12 = mean(sorted_col_m3(1:n_c_elem6));          
        
        
        %old way
        %avg_simi = max(mean(simi_matrix,1));
        %avg_simi2 = max(mean(simi_matrix,2));
        
        
%         dsift_val = (avg_simi + avg_simi2)/2.0;
%         chist_val = (avg_simi3 + avg_simi4)/2.0;        
%         simi_val = (dsift_val * dsift_norm) + (chist_val * chist_norm);
%         similarity_matrix(i,j) = simi_val;
%         similarity_matrix(j,i) = simi_val; 

        dsift_chisq = (avg_simi + avg_simi2)/2.0;
        chist_chisq3d = (avg_simi3 + avg_simi4)/2.0;
        dsift_emd = (avg_simi5 + avg_simi6)/2.0;
        chist_emd3d = (avg_simi7 + avg_simi8)/2.0;
        chist_chisq2d = (avg_simi9 + avg_simi10)/2.0;
        chist_emd2d = (avg_simi11 + avg_simi12)/2.0;
        
        sim_dsift_chisq(i,j) = dsift_chisq;
        sim_dsift_chisq(j,i) = dsift_chisq;
        sim_dsift_emd(i,j) = dsift_emd;
        sim_dsift_emd(j,i) = dsift_emd;
        sim_chist_chisq3d(i,j) = chist_chisq3d;
        sim_chist_chisq3d(j,i) = chist_chisq3d;
        sim_chist_emd3d(i,j) = chist_emd3d;
        sim_chist_emd3d(j,i) = chist_emd3d;
        sim_chist_chisq2d(i,j) = chist_chisq2d;
        sim_chist_chisq2d(j,i) = chist_chisq2d;
        sim_chist_emd2d(i,j) = chist_emd2d;
        sim_chist_emd2d(j,i) = chist_emd2d;
        
    end %for j
end %for i
fprintf('avg_similarity_matrix computed\n');
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

%helper functions from phow_caltech101 (copied from
%scott_proposals_similarity2)
function hist = phow_hist(im, ssize)
load('phow-model/vocab.mat');
model.vocab = vocab;
model.phowOpts = {'Step', 3};
model.numSpatialX = [2, 4];
model.numSpatialY = [2, 4];
model.quantizer = 'kdtree';
model.kdtree = vl_kdtreebuild(vocab);
hist = getImageDescriptor(model, im, ssize);
end

function im = standarizeImage(im, ssize)
im = im2single(im) ;
scaling = max([ssize/size(im,1) ssize/size(im,2)]);
newsize = round([size(im,1) size(im,2)]*scaling);
im = imresize(im, newsize);
end

function hist = getImageDescriptor(model, im, ssize)
im = standarizeImage(im, ssize) ;
width = size(im,2) ;
height = size(im,1) ;
numWords = size(model.vocab, 2) ;
% get PHOW features
[frames, descrs] = vl_phow(im, model.phowOpts{:}) ;
% quantize local descriptors into visual words
switch model.quantizer
  case 'vq'
    [~, binsa] = min(vl_alldist(model.vocab, single(descrs)), [], 1) ;
  case 'kdtree'
    binsa = double(vl_kdtreequery(model.kdtree, model.vocab, ...
                                  single(descrs), ...
                                  'MaxComparisons', 50)) ;
end
hists = cell(length(model.numSpatialX));
for i = 1:length(model.numSpatialX)
    binsx = vl_binsearch(linspace(1,width,model.numSpatialX(i)+1), frames(1,:)) ;
    binsy = vl_binsearch(linspace(1,height,model.numSpatialY(i)+1), frames(2,:)) ;
    % combined quantization
    bins = sub2ind([model.numSpatialY(i), model.numSpatialX(i), numWords], ...
                   binsy,binsx,binsa) ;
    hist = zeros(model.numSpatialY(i) * model.numSpatialX(i) * numWords, 1) ;
    hist = vl_binsum(hist, ones(size(bins)), bins) ;
    hists{i} = single(hist / sum(hist)) ;
end
hist = cat(1,hists{:}) ;
hist = hist / sum(hist) ;
end