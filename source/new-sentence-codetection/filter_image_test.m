function filter_image_test(dir_name)%%[phists,file_list]=filter_image_test(img_dir)
%input: img_dir: dir where images are (ABOVE FPLABEL DIR)
%output: NONE (side effects of moving/copying images only)

%add paths for phow stuff
addpath(genpath('vlfeat/toolbox'));
run('/home/sbroniko/codetection/source/sentence-codetection/vlfeat/toolbox/vl_setup');

ssize = 64; %HARDCODED ssize: the size to which each proposal is rescaled 
%               to (for phow_hist); ssize should be 2^i; increase i to 
%               trade efficiency for accuracy

tmp_dir = dir(dir_name);
fp_dir_names = [];
for i = 1:numel(tmp_dir)
    if((tmp_dir(i).isdir) && ~(strcmp(tmp_dir(i).name,'.')) ...
            && ~(strcmp(tmp_dir(i).name,'..')) && ...
            ~(strcmp(tmp_dir(i).name,'no_cluster')))
        %tmp_dir(i).name
        fp_dir_names = [fp_dir_names;tmp_dir(i).name];
    end%if
end %for i

[num_dirs,~] = size(fp_dir_names);

for j = 1:num_dirs
    img_dir = strcat(dir_name,fp_dir_names(j,:),'/');
    accept_dir = strcat(img_dir,'/accepted/');
    if exist(accept_dir,'dir')
        rmdir(accept_dir,'s'); %get rid of old data
    end %if
    reject_dir = strcat(img_dir,'/rejected/');
    if exist(reject_dir,'dir')
        rmdir(reject_dir,'s'); %get rid of old data
    end %if
    %have to remove these before listing files
    file_list = dir(img_dir);
    file_list = file_list(3:end); %to get rid of . and ..
    num_files = numel(file_list);
    
    %now make dirs
    mkdir(accept_dir);
    mkdir(reject_dir);
    
    phists = zeros(num_files, 12000, 'single'); %HARDCODED for phist size
    %get DISFT histograms
    parfor i = 1:num_files
        img = imread(strcat(img_dir,file_list(i).name));
        phists(i,:) = phow_hist(img,ssize)';
    end %parfor
    mean_phist = mean(phists); %mean image histogram
    hist_dists = zeros(num_files,1);
    for i = 1:num_files %find distance of each image from mean
        hist_dists(i) = pdist2(phists(i,:),mean_phist,'chisq');
    end %for i
    %now find mean and std of dists and set thresh
    mean_dist = mean(hist_dists); std_dist = std(hist_dists);
    thresh = mean_dist + 0.5*std_dist;
    %now loop through one last time and move (copy) images based on thresh
    for i = 1:num_files
        filename = file_list(i).name;
        src = strcat(img_dir,filename);
        if (hist_dists(i) > thresh)
            dest = strcat(reject_dir,filename);
        else
            dest = strcat(accept_dir,filename);
        end %if
        copyfile(src,dest);
    end %for i
end %for j

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
