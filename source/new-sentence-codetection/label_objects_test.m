function [labeled_xys,feature_vectors,avg_similarity_matrix,alt_asm,labels] = ...
    label_objects_test(dataset_dir,data_output_dirname)


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
fprintf('Starting label_objects_all_floorplans\n');
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

% then loading up fvcell and xy_label
feature_vectors = cell(num_floorplans,1);
labeled_xys = cell(num_floorplans,1);
temp_labels_by_floorplan = zeros(num_floorplans,1);
for i = 1:num_floorplans
    read_dir = strcat(dataset_dir,dir_names(i,:),'/',data_output_dirname);
    tmp_xys = load(strcat(read_dir,'/object_xy_with_label.mat'),...
                   'xy_with_label');
    [rows,cols] = size(tmp_xys.xy_with_label);
    labelmat = zeros(rows,cols+1);
    labelmat(1:rows,1) = 0; labelmat(:,2:4) = tmp_xys.xy_with_label;
    labeled_xys{i} = labelmat;
    %need to use xy_with_label here to combine feature_vectors from the
    %same object
    max_tmp_label = max(labelmat(:,4));
    temp_labels_by_floorplan(i) = max_tmp_label;
    %display(rows);
    %display(max_tmp_label);
    tmp_fvcell = load(strcat(read_dir,'/phow_hist_fvcell.mat'));
    if (rows == max_tmp_label)
        %fprintf('no combining needed\n');
        feature_vectors{i} = tmp_fvcell.fvcell;
    else
%         fprintf('need to combine for i = %d: rows=%d, max_tmp_label=%d\n',i,rows,max_tmp_label);
%         fprintf('before concatenation\n');
%         display(tmp_fvcell.fvcell);
        combined_fvcell = cell(max_tmp_label,1);
        for j = 1:max_tmp_label
            same_labels = find(labelmat(:,4) == j);
            current_fvcell = tmp_fvcell.fvcell{same_labels(1)};
            if (length(same_labels) > 1)
                %need to concatenate
                for k = 2:length(same_labels)
                    current_fvcell = ...
                        [current_fvcell;tmp_fvcell.fvcell{same_labels(k)}];
                end %for k
            end %if
                
%             current_tmp_label = labelmat(j,4);
%             current_fvcell = tmp_fvcell.fvcell{j};
%             for k = j+1:rows
%                 next_tmp_label = labelmat(k,4);
%                 if (current_tmp_label == next_tmp_label)
%                     %need to concatenate
%                     current_fvcell = [current_fvcell;tmp_fvcell.fvcell{k}];
%                 end %if
%             end %for k
            combined_fvcell{j} = current_fvcell;
        end %for j
        feature_vectors{i} = combined_fvcell;
%         fprintf('after concatenation\n');
%         display(feature_vectors{i});
    end %if
    %clear tmp_xys;
end %for i

fprintf('feature_vectors built\n');
system('date');

%now do comparisons between image feature vectors across floorplans
M = sum(temp_labels_by_floorplan);
avg_similarity_matrix = zeros(M,'single');
alt_asm = avg_similarity_matrix;

% n_factor = 0.5; %used in condensing simi_matrix
% m_factor = 0.5; 

s_factor = 0.75;

for i = 1:M %map-vector
    [new_i,new_j] = find_indices(i,temp_labels_by_floorplan);
    [num_img_i,~] = size(feature_vectors{new_i}{new_j});
    for j = i:M %trying with self-similarity instead of i+1:M map-vector
        [new_i2,new_j2] = find_indices(j,temp_labels_by_floorplan);
        [num_img_j,~] = size(feature_vectors{new_i2}{new_j2});
        simi_matrix = zeros(num_img_i,num_img_j,'single');
        temp_hists1 = feature_vectors{new_i}{new_j};
        temp_hists2 = feature_vectors{new_i2}{new_j2};
        parfor k = 1:num_img_i %let with 2 nested map-vectors
            %hist1 = feature_vectors{new_i}{new_j}(k,:);
            hist1 = temp_hists1(k,:);
            temp_mat = zeros(1,num_img_j);
            for l = 1:num_img_j
                %hist2 = feature_vectors{new_i2}{new_j2}(l,:);
                hist2 = temp_hists2(l,:);
                temp_mat(l) = 1 - pdist2(hist1,hist2,'chisq');
            end %for l
            simi_matrix(k,:) = temp_mat;
        end %for k
        
        [U,S,V] = svd(simi_matrix);
        s = diag(S);
        
        %REMEMBER that singular value is sqrt of eigenvalue--need to
        %square here?
        
        %avg_s = mean(s); %might want to average only singular values > 0
        avg_s = mean(s(s>0));
        %display(s);
        %display(s(s<1e-10));
        if (~isempty(s(s<1e-10)))
            fprintf('found a small singular value\n');
            
        end %if
        num_s = round(s_factor * length(s));
        %avg_s2 = mean(s(s>=1)); %seems bogus
        avg_s2 = mean(s(1:num_s));
        fprintf('for i = %d, j = %d: avg_s = %2.6f, avg_s2 = %2.6f\n',i,j,avg_s,avg_s2);
        %display(U(:,1));
        avg_similarity_matrix(i,j) = avg_s;
        avg_similarity_matrix(j,i) = avg_s;
        alt_asm(i,j) = avg_s2;
        alt_asm(j,i) = avg_s2;
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
        
%         %MAYBE try something with 1a, 2b here.
%         row_maxes = max(simi_matrix,[],2);
%         col_maxes = max(simi_matrix,[],1);
%         sorted_row_maxes = sort(row_maxes,'descend');
%         sorted_col_maxes = sort(col_maxes,'descend');
%         n_r_elem = round(m_factor*length(row_maxes));
%         n_c_elem = round(m_factor*length(col_maxes));
%         avg_simi = mean(sorted_row_maxes(1:n_r_elem));
%         avg_simi2 = mean(sorted_col_maxes(1:n_c_elem));
%         
%         %old way
%         %avg_simi = max(mean(simi_matrix,1));
%         %avg_simi2 = max(mean(simi_matrix,2));
%         avg_similarity_matrix(i,j) = avg_simi;
%         avg_similarity_matrix(j,i) = avg_simi2; 
    end %for j
end %for i
fprintf('avg_similarity_matrix computed\n');
system('date');
%now look at avg_similarity values to determine which are alike
%diagonal elements are self-similarity--look in row and column to see if
%any other values are higher

%%START HERE%%

labels = zeros(M,1);
%NEEDSWORK--hittint bad juju
%labels = labels_from_avg_similarity_matrix(avg_similarity_matrix);

%need to do something different with this
%xy_with_label(:,3) = labels; %done with this
% 
% %now do sorting and saving

%%DON'T FORGET TO SOMEHOW GIVE IMAGES UNIQUE FILE NAMES BY FLOORPLAN (FLOORPLANS
%%ARE ALREADY UNIQUE)

% outfilename = strcat(img_dir,'/object_xy_with_label.mat');
% save(outfilename,'xy_with_label'); %object locations/labels saved
% outfilename2 = strcat(img_dir,'/phow_hist_fvcell.mat');
% save(outfilename2,'fvcell'); %phow histograms saved to file
% 
% for i = 1:(unique_label - 1)
%     new_dir = strcat(img_dir,'fplabel',num2str(i),'/');
%     if (exist(new_dir,'dir'))
%         rmdir(new_dir,'s'); %get rid of old data
%     end %if
%     mkdir(new_dir); %make fplabel directories
% end %for i
% 
% for i = 1:M %for each temp label
%     src_dir = strcat(img_dir,'tmp',num2str(i),'/');
%     src_file_list = dir(src_dir);
%     num_files = numel(src_file_list) - 2; % -2 is because of . and ..
%     dest_dir = strcat(img_dir,'fplabel',num2str(xy_with_label(i,3)),'/');
%     for j = 1:num_files %for each image in tmpN dir
%         src = strcat(src_dir,src_file_list(j+2).name);
%         dest = strcat(dest_dir,src_file_list(j+2).name);
%         movefile(src,dest);
%     end %for j
%     rmdir(src_dir,'s');
% end %for i

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

%%%%%%%%%%%%%%%%%%%%%%%OLD HEADER COMMENTS FROM
%%%%%%%%%%%%%%%%%%%%%%%SORT_CLUSTERS_SINGLE_FLOORPLAN
%This function takes the images sorted into clusters (tmpN directories) and
%finds the like objects, then re-sorts the images into new directories and
%returns the xy locations with labels (like objects labeled alike)

%ALSO moves the files from the tmp* directories into fplabel* directories
%based on floorplan labels, and saves the xy_with_label data to a .mat file

%inputs: objectxys: M x 2 matrix of cluster center xy locations
%        img_dir: directory where detection images are
%output: xy_with_label M x 3 matrix of [x y label]

%%???could call sort_by_cluster here if I add cluster_data as an argument