function [Labhist,bincenters] = Lab_histogram(img_rgb,nBins,cxform)
%inputs: img_rgb - h x w x 3 RGB image
%        nBins - number of bins for histogram
%        cxform - color transform; use makecform('srgb2lab') for Lab space
%outputs: Labhist - 3 x nBins of histogram values (L, a, b layers)
%         bincenters - 1 x nBins vector of bin center locations


%set up output variables
Labhist = zeros(3,nBins);
bincenters = zeros(3,nBins);

%convert to Lab space and get info
%img_Lab = RGB2Lab(img_rgb);
img_Lab=applycform(img_rgb,cxform);
[h,w,~] = size(img_rgb);
numPix = h*w;

%split into channels
img_L = img_Lab(:,:,1);
img_a = img_Lab(:,:,2);
img_b = img_Lab(:,:,3);
% max(max(img_L))
% min(min(img_L))
% max(max(img_a))
% min(min(img_a))
% max(max(img_b))
% min(min(img_b))

%get hist for each channel
[yL,xL] = imhist(img_L,nBins);
[ya,xa] = imhist(img_a,nBins);
[yb,xb] = imhist(img_b,nBins);

%normalize and assign
Labhist(1,:) = yL' ./ numPix;
Labhist(2,:) = ya' ./ numPix;
Labhist(3,:) = yb' ./ numPix;
bincenters(1,:) = xL';
bincenters(2,:) = xa';
bincenters(3,:) = xb';
%bincenters = xL';
end %function