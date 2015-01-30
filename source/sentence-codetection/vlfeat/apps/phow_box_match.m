function phow_box_match()
% PHOW_CALTECH101 Image classification in the Caltech-101 dataset
%   This program demonstrates how to use VLFeat to construct an image
%
close all;
addpath(genpath('../../piotr-toolbox'));
addpath(genpath('../toolbox'));
% change this to the root directory of your forests_edge_boxes
% to correctly run code from forests_edge_boxes, you might need to 
% read its readme.txt
addpath(genpath('../../forests_edges_boxes'));
run('../toolbox/vl_setup');
% Load image
% change the image paths to yours
img1 = imread('/home/yu239/gist_images/frame.png');
img2 = imread('/home/yu239/gist_images/frame1.png');
imshow(img1);
b1 = round(getrect);
disp(b1);
hist1 = phow_hist(img1(b1(2):b1(2)+b1(4)-1,b1(1):b1(1)+b1(3)-1,:));

bbs = edgeBoxesOut(img2, 500, 4);
scores = zeros(size(bbs,1), 1);

pools = matlabpool('size');
cpus = feature('numCores');
if pools ~= (cpus - 1)
    if pools > 0
        matlabpool('close');
    end
    matlabpool('open', cpus - 1);
end

parfor i = 1:size(bbs,1)
    fprintf('image %d\n', i);
    b = bbs(i,1:4);
    hist2 = phow_hist(img2(b(2):b(2)+b(4)-1,b(1):b(1)+b(3)-1,:));
    scores(i) = pdist2(hist1', hist2', 'chisq');
end
bbs(:,5) = scores;
bbs = sortrows(bbs, 5);    
figure('name', 'img2');
imshow(img2);
hold on;
for i = 1:2
    rectangle('position', bbs(i,1:4), 'linewidth', 2);
    disp(bbs(i,5));
end
hold off;

function hist = phow_hist(im)
load('data/baseline-vocab.mat');
model.vocab = vocab;
model.phowOpts = {'Step', 3};
model.numSpatialX = [2, 4];
model.numSpatialY = [2, 4];
model.quantizer = 'kdtree';
model.kdtree = vl_kdtreebuild(vocab);
hist = getImageDescriptor(model, im);

function im = standarizeImage(im)
im = im2single(im) ;
scaling = max([128/size(im,1) 128/size(im,2)]);
newsize = round([size(im,1) size(im,2)]*scaling);
im = imresize(im, newsize);

function hist = getImageDescriptor(model, im)
im = standarizeImage(im) ;
width = size(im,2) ;
height = size(im,1) ;
numWords = size(model.vocab, 2) ;
% get PHOW features
[frames, descrs] = vl_phow(im, model.phowOpts{:}) ;
% quantize local descriptors into visual words
switch model.quantizer
  case 'vq'
    [drop, binsa] = min(vl_alldist(model.vocab, single(descrs)), [], 1) ;
  case 'kdtree'
    binsa = double(vl_kdtreequery(model.kdtree, model.vocab, ...
                                  single(descrs), ...
                                  'MaxComparisons', 50)) ;
end
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
