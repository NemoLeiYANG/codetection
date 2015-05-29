function points = find_score_peaks(scores,threshold_ratio)
%%Adapted from FastPeakFind.m at
%%http://www.mathworks.com/matlabcentral/fileexchange/37388-fast-2d-peak-finder

%inputs: scores: matrix of scores at each point in scoring grid
%        threshold_ratio: number between 0 and 0.5 which is multiplied by
%            the max of scores to determine the noise threshold (values
%            below which are ignored)
%output: points: Nx2 matrix of [x,y] points of peak locations


%%DO I ALSO NEED THE XPOINTS AND YPOINTS FROM SCORE_DETECTIONS IN ORDER TO
%%CONVERT BACK TO POINT (NOT PIXEL) LOCATIONS?

%cast the scores to uint16 if necessary (to speed up code)
if isfloat(scores)
    if max(scores(:)) <= 1
        scores = uint16(scores.*2^16./(max(scores(:))));
    else
        scores = uint16(scores);
    end %if
end %if

%set up threshold value and filter
thresh = threshold_ratio*max(scores(:));
filt = fspecial('gaussian',9,1);

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
    
    %TEMPORARY--still need to translate pixels to xy
    points = cent;
else %can't do anything because matrix is zero
    points = [];
    fprintf('Thresholded matrix was all zeros--check threshold\n');
    return;
end %if

end %function