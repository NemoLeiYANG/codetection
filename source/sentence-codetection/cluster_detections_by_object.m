function cluster_data = ...
    cluster_detections_by_object(detection_data, objectxys)
%inputs: detection_data: N x 3 matrix of detections' [x y fscore]
%        object_xys: M x 2 matrix of cluster center xy locations
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
    cluster_data(i,:) = [idx,dist];
end % for i
%%%NEED TO DO THRESHOLD FOR DETECTIONS TOO FAR AWAY HERE.


end %function