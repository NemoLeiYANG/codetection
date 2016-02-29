function [mean_error, error_by_object] = ...
    find_object_error(detected_objects, ground_truth)
%inputs: detected_objects - xy locations of visually detected objects
%        ground_truth - ground truth xy locations for objects in floorplan
%outputs: mean_error - average of object location errors (NOTE: if #
%                      detected_objects > # ground_truth, this INGORES the
%                      objects with the greatest distance error since those
%                      are most likely the objects not in ground truth
%         error_by_object - error between detected object and nearest
%                           ground truth objecct; will include errors for
%                           objects ignored by mean_error

detected_objects = detected_objects(:,1:2);

D = length(detected_objects);
G = length(ground_truth);

if D < G
    fprintf('WARNING in find_object_error: ');
    fprintf('fewer detections than ground_truth\n');
    num_valid = D;
    num_to_compute = D;
else
    num_valid = G;
    num_to_compute = G;
    if G < D
        fprintf('WARNING in find_object_error: ');
        fprintf('more detections than ground_truth, ');
        fprintf('so ignoring extra objects\n');
        num_to_compute = D;
    end %if
end %if

error_by_object = zeros(num_to_compute,1);
for i = 1:num_to_compute
    temp_dist = zeros(G,1);
    for j = 1:G
        temp_dist(j) = norm(detected_objects(i,:)-ground_truth(j,:));
    end %for j
    error_by_object(i) = min(temp_dist);
end %for i
error_by_object = sort(error_by_object);
mean_error = mean(error_by_object(1:num_valid)); %done
end %function