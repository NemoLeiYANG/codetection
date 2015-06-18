function [numpeaks, peakxys,scores] = find_objects(detection_data, xmin, xmax,...
    ymin, ymax, cm_between, gaussian_variance)..., threshold_ratio) HARDCODED
%% This is a combination of score_detections.m and find_score_peaks.m
%  Expect it to return the number of peaks found and their xy locations

%inputs: detection_data: matrix of n x 3, each row is [x,y,fscore]
%        xmin, xmax, ymin, ymax: boundaries in m
%        cm_between: number of cm between points in scoring grid
%        gaussian_variance: variance parameter for distance measure
%        threshold_ratio: number between 0 and 0.5 which is multiplied by
%            the max of scores to determine the noise threshold (values
%            below which are ignored) HARDCODED
%outputs: numpeaks: number of peaks found
%         peakxys: numpeaks x 2 matrix of [x,y] points of peak locations

%create scoring grid
xpoints = xmin:(cm_between/100):xmax;
num_xpoints = length(xpoints);
ypoints = ymax:-(cm_between/100):ymin; %do this in descending order to match raster order
num_ypoints = length(ypoints);
scores = zeros(num_ypoints,num_xpoints);
N = length(detection_data);

%compute score at each point in grid **COULD THIS BE FASTER W/O LOOPS??**
for i = 1:num_ypoints
    for j = 1:num_xpoints
        for n = 1:N
            scorept = [xpoints(j),ypoints(i)];
            datapt = detection_data(n,1:2);
            d = norm(scorept-datapt);
            d_score = gaussmf(d,[gaussian_variance,0]);
            scores(i,j) = scores(i,j) + d_score * detection_data(n,3);
        end % for n
    end %for j
end %for i

%cast the scores to uint16 (to speed up code)
scores = uint16(scores);

%set up threshold value and filter
threshold_ratio = 0.3; %HARDCODED
thresh = threshold_ratio*max(scores(:));
filt = fspecial('gaussian',9,1); %HARDCODED

%do median filtering and apply threshold
scores = medfilt2(scores,[3,3]);
scores = scores.*uint16(scores > thresh);

if any(scores(:)) %proceed only if thresholded matrix is nonzero
    %smooth the matrix
    scores = conv2(single(scores),filt,'same');
    %re-apply threshold
    scores = scores.*(scores > thresh);
    
    %use regionprops to get peak areas and centroids
    s = regionprops(logical(scores),scores,'Area','WeightedCentroid');
    
    %% Next section copied from FastPeakFind.m
    % find reliable peaks by considering only peaks with an area
    % below some limit. The weighted centroid method can be not
    % accurate if peaks are very close to one another, i.e., a
    % single peak will be detected, instead of the real number
    % of peaks. This will result in a much larger area for that
    % peak. At the moment, the code ignores that peak. If that
    % happens often consider a different threshold, or return to
    % the more robust "local maxima" method.
    % To set a proper limit, inspect your data with:
    % hist([stats.Area],min([stats.Area]):max([stats.Area]));
    % to see if the limit I used (mean+2 standard deviations)
    % is an appropriate limit for your data.
    rel_peaks_vec=[s.Area]<=mean([s.Area])+2*std([s.Area]);
    cent=[s(rel_peaks_vec).WeightedCentroid]';
    %end copied section
    %%
    %cent = [s.WeightedCentroid]'; %for no limit on peak area
    
    %set up output
    numpeaks = numel(cent)/2;
    %convert cent vector to matrix of xy pixel points
    tempxy = [cent(1:2:end),cent(2:2:end)];
    %convert from pixel points to xy points
    tempxy = tempxy * (cm_between/100);
    tempxy(:,2) = -tempxy(:,2);
    shiftmat = zeros(numpeaks,2);
    shiftmat(:,1) = xmin; shiftmat(:,2) = ymax;
    peakxys = tempxy + shiftmat; %done
    
else %can't do anything because matrix is zero
    numpeaks = 0;
    peakxys = [];
    fprintf('Thresholded matrix was all zeros--check threshold\n');
    return;
end %if
end %function