
%% Demo to show the results of MCG
clear all;close all;home;

% Read an input image
I = imread('/home/haonan/Desktop/frame.png');

tic;
% Test the 'fast' version, which takes around 5 seconds in mean
[candidates_scg, ucm2_scg] = im2mcg(I,'fast');
toc;

%% Show UCM results (dilated for visualization)
figure;
subplot(1,3,1)
imshow(I), title('Image')

subplot(1,3,2)
imshow(imdilate(ucm2_scg,strel(ones(3))),[]), title('Fast UCM (SCG)')

%% Show Object Candidates results and bounding boxes
% Candidates in rank position
id1 = 1;

disp(candidates_scg);
% Get the masks from superpixels and labels
mask1 = ismember(candidates_scg.superpixels, candidates_scg.labels{id1});

% Bboxes is a matrix that contains the four coordinates of the bounding box
% of each candidate in the form [up,left,down,right]. See folder bboxes for
% more function to work with them

% Show results
figure;
subplot(1,3,1)
imshow(I), title('Image')
subplot(1,3,2)
imshow(mask1), title('Candidate + Box')
hold on
plot([candidates_scg.bboxes(id1,4) candidates_scg.bboxes(id1,4) candidates_scg.bboxes(id1,2) candidates_scg.bboxes(id1,2) candidates_scg.bboxes(id1,4)],...
     [candidates_scg.bboxes(id1,3) candidates_scg.bboxes(id1,1) candidates_scg.bboxes(id1,1) candidates_scg.bboxes(id1,3) candidates_scg.bboxes(id1,3)],'r-')
