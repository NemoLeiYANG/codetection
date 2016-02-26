function xy_with_label = create_xy_with_label(objectxys,img_dir)
%This function simply takes objectxys and outputs a matrix with [x y idx]
fprintf('in create_xy_with_label\n');

[M,~] = size(objectxys);
xy_with_label = zeros(M,3);
xy_with_label(:,1:2) = objectxys;
for i = 1:M
    xy_with_label(i,3) = i;
end %for

%now save
outfilename = strcat(img_dir,'/object_xy_with_label.mat');
save(outfilename,'xy_with_label'); %object locations/labels saved

end %function
