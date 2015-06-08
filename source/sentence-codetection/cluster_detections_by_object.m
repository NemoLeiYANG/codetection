function cluster_data = ...
    cluster_detections_by_object(detection_data, objectxys, thresh)
%inputs: detection_data: N x 3 matrix of detections' [x y fscore]
%        object_xys: M x 2 matrix of cluster center xy locations
%        thresh: threshold value for distance b/w det and obj (in m)
%output: cluster_data: N x 2 matrix of [cluster_idx, distance]
%  **NOTE: cluster_idx and distance will be 0 if detection too far from a
%  cluster

[N,~] = size(detection_data);
[M,~] = size(objectxys);

cluster_data = zeros(N,2);

for i = 1:N
    temp_dist = zeros(M,1);
    for j = 1:M
        temp_dist(j) = norm(detection_data(i,1:2)-objectxys(j,:));
    end %for j
    [dist, idx] = min(temp_dist);
    if (dist < thresh) %threshold for detections too far away
        cluster_data(i,:) = [idx,dist];
    end %if
end % for i
end %function