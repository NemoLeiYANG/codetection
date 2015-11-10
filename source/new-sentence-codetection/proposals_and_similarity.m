function [bboxes, simi] = proposals_and_similarity(top_k, frames, ssize)
% proposals_and_similarity: given a sequence of frames, compute object
%                           proposals in each frame, and similarity between
%                           adjacent frames
% INPUT: 
%     top_k         proposal number in each frame
%     frames        h*w*3*T
%     ssize         the size to which each proposal is rescaled to
%                   ssize should be 2^i; increase i to trade efficiency for accuracy
% OUTPUT:
%     bboxes        top_k*5*T, each row of top_k*5 is (x1,y1,x2,y2,f) 
%     simi          top_k*top_k*(T-1), phow similarity between proposals in
%                   adjacent frames 
%                   simi(10,15,1): the similarity between the 10th box in 
%                                  the first frame and the 15th box in the
%                                  second frame, the higher the better
%
% add paths
%addpath(pwd);
addpath(genpath('piotr-toolbox'));
addpath(genpath('vlfeat/toolbox'));
addpath(genpath('forests_edges_boxes'));
run('vlfeat/toolbox/vl_setup');

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

% this will take 2.5 minutes for 12 frames with ssize = 64, top_k = 300 (default)
%                3.5 minutes for 12 frames with ssize = 128, top_k = 300 
%                1.5 minutes for 12 frames with ssize = 64, top_k = 200
%                0.5 minutes for 12 frames with ssize = 64, top_k = 100
%                0.25 minutes for 5 frames with ssize = 64, top_k = 100
%tic;
for t = 1:T
    img = frames(:,:,:,t);
    bbs = edgeBoxesOut(img, top_k, 5);
    bbs(:,3) = bbs(:,3) + bbs(:,1) - 1;
    bbs(:,4) = bbs(:,4) + bbs(:,2) - 1;
    bboxes(:,:,t) = bbs;

    parfor i = 1:top_k
        bi = bboxes(i,:,t);
        hists{i} = phow_hist(img(bi(2):bi(4),bi(1):bi(3),:), ssize);
    end
    hist = cat(2, hists{:});
    hist = hist';

    if t > 1
        simi(:,:,t-1) = -pdist2(hist_prev, hist, 'chisq');
    end
    hist_prev = hist;
end
%tt = toc;
%fid = fopen('/tmp/output', 'w');
%fprintf(fid, '%f', tt);
%fclose(fid);

function hist = phow_hist(im, ssize)
load('phow-model/vocab.mat');
model.vocab = vocab;
model.phowOpts = {'Step', 3};
model.numSpatialX = [2, 4];
model.numSpatialY = [2, 4];
model.quantizer = 'kdtree';
model.kdtree = vl_kdtreebuild(vocab);
hist = getImageDescriptor(model, im, ssize);

function im = standarizeImage(im, ssize)
im = im2single(im) ;
scaling = max([ssize/size(im,1) ssize/size(im,2)]);
newsize = round([size(im,1) size(im,2)]*scaling);
im = imresize(im, newsize);

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