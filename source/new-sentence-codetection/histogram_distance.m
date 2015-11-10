function [dist] = histogram_distance(hist1, hist2, metric, numDim)
%inputs: hist1, hist2 - 2 3-d histograms
%        metric - histogram measurement metric (i.e., 'chisq' or 'emd')
%        numDim - number of dimensions to compare (must be 3 or 2)
%                 if 2, will compare last 2 dim (a and b in Lab space)
%output: dist - scalar distance measure between histograms

dist = inf;
%check input
if ((numDim ~= 2) && (numDim ~= 3))
    fprintf('ERROR: numDim must be 2 or 3\n');
    return;
end

metstr = sprintf('%s',metric);

dist_vec = zeros(1,3);
for i = 2:3
    dist_vec(i) = pdist2(hist1(i,:),hist2(i,:),metstr);
end
if (numDim == 3)
    dist_vec(1) = pdist2(hist1(1,:),hist2(1,:),metstr);
end
%dist_vec
%sqrt(sum(dist_vec .* dist_vec))
dist=norm(dist_vec);
end