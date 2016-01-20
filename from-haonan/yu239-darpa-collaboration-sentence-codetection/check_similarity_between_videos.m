function [computed,simi] = check_similarity_between_videos(video_dir1, video_dir2, ...
                                                  T, top_k, n_orientations)
%
computed = 1;
simi = [];
[root_dir, video1] = fileparts(video_dir1);
[root_dir, video2] = fileparts(video_dir2);
simi_dir = [root_dir, '/similarity'];
simi_file = [simi_dir, '/', video1, '__', video2, '.mat'];

if ~exist(simi_file, 'file')
    % reverse the order (just in case)
    simi_file = [simi_dir, '/', video2, '__', video1, '.mat'];
    if ~exist(simi_file, 'file')
        computed = 0;
        return;
    end
end

% load precomputed similarity
load(simi_file, 'simi');
[num_boxes,~,I,frames_n] = size(simi);
% not enough boxes or frames
if num_boxes<top_k || I<n_orientations || frames_n~=T
    computed = 0;
    return;
end
simi = double(simi(1:top_k,1:top_k,1:n_orientations,:));

