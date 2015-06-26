function [xy_with_label,avg_similarity_matrix] = ... % xy_with_label = 
    sort_clusters_single_floorplan(objectxys, img_dir)
%This function takes the images sorted into clusters (tmpN directories) and
%finds the like objects, then re-sorts the images into new directories and
%returns the xy locations with labels (like objects labeled alike)

%ALSO moves the files from the tmp* directories into fplabel* directories
%based on floorplan labels, and saves the xy_with_label data to a .mat file

%inputs: objectxys: M x 2 matrix of cluster center xy locations
%        img_dir: directory where detection images are
%output: xy_with_label M x 3 matrix of [x y label]

%%???could call sort_by_cluster here if I add cluster_data as an argument

fprintf('in sort_clusters_single_floorplan\n');

[M,~] = size(objectxys);
xy_with_label = zeros(M,3);
xy_with_label(:,1:2) = objectxys;
ssize = 64; %HARDCODED ssize: the size to which each proposal is rescaled 
%               to (for phow_hist); ssize should be 2^i; increase i to 
%               trade efficiency for accuracy

%create cell array for storing feature vectors from each image
fvcell = cell(M,1);

%add paths for phow stuff
addpath(genpath('vlfeat/toolbox'));
run('/home/sbroniko/codetection/source/sentence-codetection/vlfeat/toolbox/vl_setup');

%loop through 1:M, adding feature vectors for each image to a matrix
parfor i = 1:M %for each temp label
    tmp_img_dir = strcat(img_dir,'tmp',num2str(i),'/');
    tmp_file_list = dir(tmp_img_dir);
    num_files = numel(tmp_file_list) - 2; % -2 is because of . and ..
    tmp_phists = zeros(num_files, 12000,'single'); %HARDCODED for phist size
    for j = 1:num_files %for each image in tmpN dir
        img = imread(strcat(tmp_img_dir,tmp_file_list(j+2).name));
        hist_out = phow_hist(img,ssize);
        tmp_phists(j,:) = hist_out';
    end %for j
    fvcell{i} = tmp_phists;
end %for i

fprintf('fvcell built\n');

n_factor = 0.5; %used in condensing simi_matrix
m_factor = 0.2; 

%now do comparison of feature vectors between each pair of temp labels
avg_similarity_matrix = zeros(M,'single');
for i = 1:M
    [num_img_i,~] = size(fvcell{i});
    for j = i:M %trying with self-similarity instead of i+1:M
        [num_img_j,~] = size(fvcell{j});
        simi_matrix = zeros(num_img_i,num_img_j,'single');
        temp_hists1 = fvcell{i};
        temp_hists2 = fvcell{j};
        parfor k = 1:num_img_i
            %hist1 = fvcell{i}(k,:);
            hist1 = temp_hists1(k,:);
            temp_mat = zeros(1,num_img_j);
            for l = 1:num_img_j
                %hist2 = fvcell{j}(l,:);
                hist2 = temp_hists2(l,:);
                temp_mat(l) = 1-pdist2(hist1,hist2,'chisq');
                %simi_matrix(k,l)= 1 - pdist2(hist1,hist2,'chisq');
            end %for l
            simi_matrix(k,:) = temp_mat;
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
        
        %attempt 1: 1a, 2a -- doesn't work -- self similarity = 1
        row_maxes = max(simi_matrix,[],2);
        col_maxes = max(simi_matrix,[],1);
        avg_simi = mean(row_maxes);
        avg_simi2 = mean(col_maxes);
        %old way
        %avg_simi = max(mean(simi_matrix,1));
        %avg_simi2 = max(mean(simi_matrix,2));
        avg_similarity_matrix(i,j) = avg_simi;
        avg_similarity_matrix(j,i) = avg_simi2; 
    end %for j
end %for i

fprintf('avg_similarity_matrix computed\n');

%now look at avg_similarity values to determine which are alike
%diagonal elements are self-similarity--look in row and column to see if
%any other values are higher

similarity_ratio_factor = 0.4;

unique_label = 1; %first unique label value
labels = zeros(M,1);
while (min(labels) == 0) %keep going until all labels set
    fprintf('at top of labeling loop\n');
    display(labels);
    for i = 1:M
        if (labels(i) == 0)  %only do stuff if label not already set
            display(i);
            diagonal_value = avg_similarity_matrix(i,i);
            row_vals = avg_similarity_matrix(i,:);
            col_vals = avg_similarity_matrix(:,i);
            row_wo_diag = row_vals(row_vals ~= diagonal_value);
            col_wo_diag = col_vals(col_vals ~= diagonal_value);
            
            big_col_vals = col_wo_diag(col_wo_diag > ...
                (similarity_ratio_factor * diagonal_value));
            big_row_vals = row_wo_diag(row_wo_diag > ...
                (similarity_ratio_factor * diagonal_value));
            
            [~,cidx] = ismember(big_col_vals,col_vals);
            [~,ridx] = ismember(big_row_vals,row_vals);
            
            idx = unique([cidx',ridx]);
            other_labels = labels(idx);
            
            %START HERE
            if (isempty(other_labels) || (max(other_labels) == 0)) 
                 %we have a new unique label
                labels(i) = unique_label;
                unique_label = unique_label + 1;
            elseif (length(unique(other_labels)) == 1)
                %use this label
                labels(i) = other_labels(1);
            else
                fprintf('BAD JUJU HERE\n');
            end %if length
            %end new logic
            
%             max_row_val = max(row_wo_diag);
%             max_col_val = max(col_wo_diag);
%             row_idx = find(row_vals == max_row_val);
%             col_idx = find(col_vals == max_col_val);
%             test1 = ((similarity_ratio_factor*diagonal_value) > max_row_val)
%             test2 = ((similarity_ratio_factor*diagonal_value) > max_col_val)
%             if (test1 && test2)
%                 %we have a new unique label
%                 labels(i) = unique_label;
%                 unique_label = unique_label+1;
%             elseif (test1)
%                 %take label from column if already set, else unique
%                 if (labels(col_idx) ~= 0)
%                     labels(i) = labels(col_idx);
%                 else
%                     labels(i) = unique_label;
%                     unique_label = unique_label + 1;
%                 end %if
%             elseif (test2)
%                 %take label from row if already set, else unique
%                 if (labels(row_idx) ~= 0)
%                     labels(i) = labels(row_idx);
%                 else
%                     labels(i) = unique_label;
%                     unique_label = unique_label + 1;
%                 end %if
%             else
%                 %fprintf('THIS SHOULDN''T HAPPEN');
%                 if (row_idx == col_idx) %same label
%                     labels(i) = labels(row_idx);
%                 else %pick the bigger one
%                     if (max_row_val > max_col_val)
%                         labels(i) = labels(row_idx);
%                     else
%                         labels(i) = labels(col_idx);
%                     end
%                 end
%             end %if
         
            % OLD METHOD
%             [~,rowidx] = max(avg_similarity_matrix(i,:));
%             [~,colidx] = max(avg_similarity_matrix(:,i));
%             if ((rowidx == i) && (colidx == i)) %we have a new unique label
%                 labels(i) = unique_label;
%                 unique_label = unique_label + 1;
%             elseif (colidx ~= i) %copy label from colidx
%                 labels(i) = labels(colidx);
%             elseif (rowidx ~= i) %copy label from rowidx
%                 labels(i) = labels(rowidx);
%             else
%                 fprintf('THIS SHOULDN''T HAPPEN');
%             end % if row && col
        end %if        
    end %for i
end %while

fprintf('done with labeling\n');
xy_with_label(:,3) = labels; %done with this

%now do sorting and saving
outfilename = strcat(img_dir,'/object_xy_with_label.mat');
save(outfilename,'xy_with_label'); %object locations/labels saved
outfilename2 = strcat(img_dir,'/phow_hist_fvcell.mat');
save(outfilename2,'fvcell'); %phow histograms saved to file

for i = 1:(unique_label - 1)
    new_dir = strcat(img_dir,'fplabel',num2str(i),'/');
    if (exist(new_dir,'dir'))
        rmdir(new_dir,'s'); %get rid of old data
    end %if
    mkdir(new_dir); %make fplabel directories
end %for i

for i = 1:M %for each temp label
    src_dir = strcat(img_dir,'tmp',num2str(i),'/');
    src_file_list = dir(src_dir);
    num_files = numel(src_file_list) - 2; % -2 is because of . and ..
    dest_dir = strcat(img_dir,'fplabel',num2str(xy_with_label(i,3)),'/');
    for j = 1:num_files %for each image in tmpN dir
        src = strcat(src_dir,src_file_list(j+2).name);
        dest = strcat(dest_dir,src_file_list(j+2).name);
        movefile(src,dest); %CHANGE BACK copy to move in sort_by_cluster.m
    end %for j
    rmdir(src_dir,'s');
end %for i

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
