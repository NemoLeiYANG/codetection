function [bboxes, simi] = proposals_and_similarity(top_k, frames)
% proposals_and_similarity: given a sequence of frames, compute object
%                           proposals in each frame, and similarity between
%                           adjacent frames
% INPUT: 
%     top_k         proposal number in each frame
%     frames        h*w*3*T
% OUTPUT:
%     bboxes        top_k*5*T, each row of top_k*5 is (x1,y1,x2,y2,f) 
%     simi          top_k*top_k*(T-1), phow similarity between proposals in
%                   adjacent frames 
%                   simi(10,15,1): the similarity between the 10th box in 
%                                  the first frame and the 15th box in the
%                                  second frame, the higher the better
%
% add paths
addpath(genpath('piotr-toolbox'));
addpath(genpath('vlfeat/toolbox'));
addpath(genpath('forests_edges_boxes'));
%run('vlfeat/toolbox/vl_setup');
run('~/codetection/source/sentence-codetection/vlfeat/toolbox/vl_setup');

% enable parfor
pools = matlabpool('size');
cpus = feature('numCores');
if pools ~= (cpus - 1)
    if pools > 0
        matlabpool('close');
    end
    matlabpool('open', cpus - 1);
end

% compute
[h, w, d, T] = size(frames);
bboxes = zeros(top_k, 5, T);
simi = zeros(top_k, top_k, T-1);
for t = 1:T
    img = frames(:,:,:,t);
    bbs = edgeBoxesOut(img, top_k, 4);
    bbs(:,3) = bbs(:,3) + bbs(:,1) - 1;
    bbs(:,4) = bbs(:,4) + bbs(:,2) - 1;
    bboxes(:,:,t) = bbs;
    if t > 1
        img_prev = frames(:,:,:,t-1);
        for i = 1:top_k
            bi = bboxes(i,:,t);
            costs = zeros(top_k, 1);
            parfor j = 1:top_k
                bj = bboxes(j,:,t-1);
                histi = phow_hist(img(bi(2):bi(4),bi(1):bi(3),:));
                histj = phow_hist(img_prev(bj(2):bj(4),bj(1):bj(3),:));
                costs(j) = pdist2(histj', histi', 'chisq');
            end
            simi(:,i,t-1) = -costs;
        end
    end
end

function hist = phow_hist(im)
load('phow-model/vocab.mat');
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