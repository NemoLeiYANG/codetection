function xy_with_label = ... %[xy_with_label,avg_similarity_matrix] = 
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
for i = 1:M %for each temp label
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

%now do comparison of feature vectors between each pair of temp labels
avg_similarity_matrix = zeros(M,'single');
for i = 1:M
    [num_img_i,~] = size(fvcell{i});
    for j = i:M %trying with self-similarity instead of i+1:M
        [num_img_j,~] = size(fvcell{j});
        simi_matrix = zeros(num_img_i,num_img_j,'single');
        for k = 1:num_img_i
            hist1 = fvcell{i}(k,:);
            for l = 1:num_img_j
                hist2 = fvcell{j}(l,:);
                simi_matrix(k,l)= 1 - pdist2(hist1,hist2,'chisq');
            end %for l
        end %for k
        avg_simi = max(mean(simi_matrix,1));
        avg_simi2 = max(mean(simi_matrix,2));
        avg_similarity_matrix(i,j) = avg_simi;
        avg_similarity_matrix(j,i) = avg_simi2; 
    end %for j
end %for i

%now look at avg_similarity values to determine which are alike
%diagonal elements are self-similarity--look in row and column to see if
%any other values are higher

unique_label = 1; %first unique label value
labels = zeros(M,1);
while (min(labels) == 0) %keep going until all labels set
    for i = 1:M
        if (labels(i) == 0)  %only do stuff if label not already set
            [~,rowidx] = max(avg_similarity_matrix(i,:));
            [~,colidx] = max(avg_similarity_matrix(:,i));
            if ((rowidx == i) && (colidx == i)) %we have a new unique label
                labels(i) = unique_label;
                unique_label = unique_label + 1;
            elseif (colidx ~= i) %copy label from colidx
                labels(i) = labels(colidx);
            elseif (rowidx ~= i) %copy label from rowidx
                labels(i) = labels(rowidx);
            else
                fprintf('THIS SHOULDN''T HAPPEN');
            end % if row && col
        end %if        
    end %for i
end %while
xy_with_label(:,3) = labels; %done with this


%now do sorting and saving

end %function

%helper functions from phow_caltech101 (copied from
%scott_proposals_similarity 2)
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
