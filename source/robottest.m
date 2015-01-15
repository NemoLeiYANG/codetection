function [imgs, sentence] = robottest(datapath)

addpath(genpath('~/codetection/forests_edges_boxes'));
addpath('~/codetection/');

%load images from video_front.avi
vid = mmreader([datapath '/video_front.avi']);
h = vid.Height;
w = vid.Width;
d = vid.BitsPerPixel/8;
nFrames = vid.NumberOfFrames;
imgs = zeros(h,w,d,nFrames,'uint8');
for i = 1:nFrames
    imgs(:,:,:,i) = read(vid,i);
end

%load sentence from sentence.txt
fileID = fopen([datapath '/sentence.txt']);
sentence = textscan(fileID, '%q');
fclose(fileID);

%load frame timing data from camera_front.txt


%load position estimates from imu-log.txt


%match frames with positions by time


%camera calibration data


%convert pixels to locations


end

%probably need some helper functions down here