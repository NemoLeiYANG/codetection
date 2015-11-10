function [yRed,yGreen,yBlue] = myrgbhist(image,nBins)
%Split into RGB Channels
Red = image(:,:,1);
Green = image(:,:,2);
Blue = image(:,:,3);
[h,w,~] = size(image);
numPix = h*w;

%Get histValues for each channel
[yRed, x] = imhist(Red,nBins);
[yGreen, x] = imhist(Green,nBins);
[yBlue, x] = imhist(Blue,nBins);

%normalize
yRed = yRed./numPix;
yGreen = yGreen./numPix;
yBlue = yBlue ./ numPix;

%Plot them together in one plot
figure;
plot(x, yRed, 'Red', x, yGreen, 'Green', x, yBlue, 'Blue');