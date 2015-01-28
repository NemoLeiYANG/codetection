function [imgs, sentence, frame_times] = robottest(datapath)

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
fileID = fopen([datapath '/sentence.txt'],'r');
sentence = textscan(fileID, '%q');
fclose(fileID);

%load frame timing data from camera_front.txt
fileID = fopen([datapath '/camera_front.txt'],'r');
for i = 1:2 %drop 1st 2 lines (header data)
    fgetl(fileID);
end
tline = fgetl(fileID);
timing = zeros(1,2);
i = 1;
while (tline(19) ~= ' ') %ischar(tline)
    timing(i,:) = sscanf(tline,'%f:%d',[1,2]);
    i = i + 1;
    tline = fgetl(fileID);
end
frame_times = timing(:,1);

%load position estimates from imu-log.txt


%match frames with positions by time


%get proposals (edgeBoxesOut??)


%camera calibration data


%convert pixels to locations


end

%probably need some helper functions down here