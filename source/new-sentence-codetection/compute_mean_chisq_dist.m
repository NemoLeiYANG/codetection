function d = compute_mean_chisq_dist(hists1,hists2)
    [l1,~] = size(hists1);
    [l2,~] = size(hists2);
    if l1 ~= l2
        fprintf('ERROR: number of histograms must be equal\n');
        d=1; %worst possible
        return;
    end %if
    hists2rev = flipud(hists2); %for reverse alignment
    fwdscore = zeros(1,l1);
    revscore = zeros(1,l1);
    parfor i = 1:l1
        fwdscore(i) = pdist2(hists1(i,:),hists2(i,:),'chisq');
        revscore(i) = pdist2(hists1(i,:),hists2rev(i,:),'chisq');
    end %parfor
    d1 = mean(fwdscore);
    d2 = mean(revscore);
    if d1 < d2 %b/c it is a DISTANCE, lower is better
        d = d1;
    else
        d = d2;
    end %if
end %function