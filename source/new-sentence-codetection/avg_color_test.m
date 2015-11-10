function [rgb,Lab] = avg_color_test(img)

imgLab = RGB2Lab(img); %Lab space
[h,w,~] = size(img);
hcenter = round(h/2);
wcenter = round(w/2);

%grab 3x3 cell around center
rgb3x3 = img(hcenter-1:hcenter+1,wcenter-1:wcenter+1,:);
Lab3x3 = imgLab(hcenter-1:hcenter+1,wcenter-1:wcenter+1,:);

%find mean color
rgb(:,:,1) = mean2(rgb3x3(:,:,1));
rgb(:,:,2) = mean2(rgb3x3(:,:,2));
rgb(:,:,3) = mean2(rgb3x3(:,:,3));
Lab(:,:,1) = mean2(Lab3x3(:,:,1));
Lab(:,:,2) = mean2(Lab3x3(:,:,2));
Lab(:,:,3) = mean2(Lab3x3(:,:,3));

%display
figure; patch([0 1 1 0],[0 0 1 1], rgb/255)
%figure; patch([0 1 1 0],[0 0 1 1], Lab/255)


end %function