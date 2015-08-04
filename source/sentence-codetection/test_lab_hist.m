function sim_mat = test_lab_hist(imgs,nBins,metric)

%compute histograms for each image
numImg = length(imgs);
hists = zeros(3,nBins,numImg);
cxform = makecform('srgb2lab');
for i = 1:numImg
    [hists(:,:,i),~] = Lab_histogram(imgs{i},nBins,cxform);
end %for i

%make sim_mat
sim_mat = zeros(numImg);
for i = 1:numImg
    for j = 1:numImg
        sim_mat(i,j) = histogram_distance(hists(:,:,i),...
            hists(:,:,j),metric,2);
    end %for j
end %for i
    
end %function