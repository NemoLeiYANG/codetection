function [Labhist,bincenters] = Lab_histogram(img_rgb,nBins)

%set up output variable
Labhist = zeros(3,nBins);

%convert to Lab space and get info
img_Lab = RGB2Lab(img_rgb);
[h,w,~] = size(img_rgb);
numPix = h*w;

%split into channels
img_L = img_Lab(:,:,1);
img_a = img_Lab(:,:,2);
img_b = img_Lab(:,:,3);

%get hist for each channel
[yL,x] = imhist(img_L,nBins);
[ya,x] = imhist(img_a,nBins);
[yb,x] = imhist(img_b,nBins);
bincenters = x;

%normalize and assign
Labhist(1,:) = yL' ./ numPix;
Labhist(2,:) = ya' ./ numPix;
Labhist(3,:) = yb' ./ numPix;

end %function