function sim_mat = compute_phow_sim_matrix(hist_cell)
    [num_tubes,~] = size(hist_cell);
    sim_mat = zeros(num_tubes,'single');
%     for i = 1:num_tubes
%         for j = i:num_tubes %b/c matrix is symmetric
%             %equalize lengths of histogram matrices
%             hists1raw = hist_cell{i};
%             hists2raw = hist_cell{j};
%             [numhists1,~] = size(hists1raw);
%             [numhists2,~] = size(hists2raw);
%             if (numhists1 <= numhists2)
%                 hists1 = hists1raw;
%             else
%                 idx = round(linspace(1,numhists1,numhists2));
%                 hists1 = hists1raw(idx,:);
%             end %if
%             if (numhists2 <= numhists1)
%                 hists2 = hists2raw;
%             else
%                 idx = round(linspace(1,numhists2,numhists1));
%                 hists2 = hists2raw(idx,:);
%             end %if
%             %compute matrix entry
%             tempscore = compute_mean_chisq_dist(hists1,hists2);
%             sim_mat(i,j) = 1 - tempscore;
%             sim_mat(j,i) = 1 - tempscore;
%         end %for j
%     end %for i
    
parfor i = 1:num_tubes
    temprow = zeros(1,num_tubes);
    for j = i:num_tubes %b/c matrix is symmetric
        %equalize lengths of histogram matrices
        hists1raw = hist_cell{i};
        hists2raw = hist_cell{j};
        [numhists1,~] = size(hists1raw);
        [numhists2,~] = size(hists2raw);
        if (numhists1 <= numhists2)
            hists1 = hists1raw;
        else
            idx = round(linspace(1,numhists1,numhists2));
            hists1 = hists1raw(idx,:);
        end %if
        if (numhists2 <= numhists1)
            hists2 = hists2raw;
        else
            idx = round(linspace(1,numhists2,numhists1));
            hists2 = hists2raw(idx,:);
        end %if
        %compute matrix entry
        tempscore = compute_mean_chisq_dist(hists1,hists2);
        %sim_mat(i,j) = 1 - tempscore;
        %sim_mat(j,i) = 1 - tempscore;
        temprow(j) = 1 - tempscore;
    end %for j
    sim_mat(i,:) = temprow;    
end %parfor i

for i = 1:num_tubes
    sim_mat(i:num_tubes,i) = sim_mat(i,i:num_tubes)';
end %for i

end %function