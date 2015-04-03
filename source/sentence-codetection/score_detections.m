function scores = score_detections(detection_data, xmin, xmax, ymin, ymax, cm_between, gaussian_variance)
%inputs: detection_data: matrix of n x 3, each row is [x,y,fscore]
%        xmin, xmax, ymin, ymax: boundaries in m
%        cm_between: number of cm between points in scoring grid
%        gaussian_variance: variance parameter for distance measure
%output: score: matrix of scores at each point in scoring grid

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

end %function