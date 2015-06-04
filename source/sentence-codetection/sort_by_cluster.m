function sort_by_cluster(cluster_data,img_dir)
%inputs: cluster_data: N x 2 matrix of [cluster_idx, distance]
%        img_dir: directory where detection images are
%output: NONE (side effects only) (maybe return 0/1 for success/error??)
cluster_idx = cluster_data(:,1);
num_obj = max(cluster_idx);
for i = 0:num_obj
    if i == 0
        dest_dir = strcat(img_dir,'no_cluster/');
    else
        dest_dir = strcat(img_dir,'tmp',num2str(i),'/');
    end %if
    if exist(dest_dir,'dir')
        rmdir(dest_dir,'s'); %get rid of old data
    end %if
    mkdir(dest_dir);
    img_list = find(cluster_idx == i);
    for j = 1:length(img_list)
        src = strcat(img_dir, sprintf('%05d',img_list(j)),'.png');
        dest = strcat(dest_dir, sprintf('%05d',img_list(j)),'.png');
        %change copy to move after testing complete
        copyfile(src,dest);
    end %for j
    %do I want to just delete the no_cluster images here?
end %for i
end %function