
run('/home/sbroniko/codetection/source/sentence-codetection/MCG-PreTrained/install');

img = imread('/home/sbroniko/codetection/testing-data/video-frames/frame-0075.ppm');

figure; imshow(img); title('Original image');

tic;
% Test the 'fast' version, which takes around 5 seconds in mean
[output_scg, output_ucm2_scg] = im2mcg(img,'fast');
toc;

boxes = output_scg.bboxes;
boxes_to_plot = 10;
if (length(boxes) < boxes_to_plot)
    boxes_to_plot = length(boxes); end
colors = distinguishable_colors(boxes_to_plot);
figure; imshow(img); title('With boxes'); hold all;
[h,w,~] = size(img);
rectangle('Position',[1 440 w h-440],'FaceColor','white','EdgeColor','white');
baseheight = 450;
for i = 1:boxes_to_plot
    x = boxes(i,2);
    y = boxes(i,1);
    w = boxes(i,4)-boxes(i,2);
    h = boxes(i,3)-boxes(i,1);
    rectangle('Position',[x,y,w,h],'LineWidth',2,'EdgeColor',colors(i,:));
    if (i > 80)
        text((i-80)*15, baseheight+30, num2str(i),'Color',colors(i,:));
    elseif (i > 40)
        text((i-40)*15, baseheight+15, num2str(i),'Color',colors(i,:));
    else
        text(i*15, baseheight, num2str(i),'Color',colors(i,:));
    end
end
title(['Original boxes, ',num2str(length(boxes)),' boxes total']);
axis image;
hold off;