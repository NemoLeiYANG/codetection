function labels = labels_from_avg_similarity_matrix_step3(avg_similarity_matrix)

%now look at avg_similarity values to determine which are alike
%diagonal elements are self-similarity--look in row and column to see if
%any other values are higher than a threshold

similarity_ratio_factor = 0.39;
val_ratio_threshold = 0.75;

[M,~] = size(avg_similarity_matrix);

unique_label = 1; %first unique label value
labels = zeros(M,1);
iter_count = 1;
while (min(labels) == 0) %keep going until all labels set
    if (iter_count > 2*M)
        fprintf('exiting after too many iterations\n');
        break;
    end %if
    %fprintf('at top of labeling loop, iteration %d\n',iter_count);
    %display(labels);
    for i = 1:M
        if (labels(i) == 0)  %only do stuff if label not already set
     %       display(i);
            diagonal_value = avg_similarity_matrix(i,i);
            row_vals = avg_similarity_matrix(i,:);
            col_vals = avg_similarity_matrix(:,i);
            row_wo_diag = row_vals(row_vals ~= diagonal_value);
            col_wo_diag = col_vals(col_vals ~= diagonal_value);
            
            big_col_vals = col_wo_diag(col_wo_diag > ...
                (similarity_ratio_factor * diagonal_value));
            big_row_vals = row_wo_diag(row_wo_diag > ...
                (similarity_ratio_factor * diagonal_value));        
            
            [~,cidx] = ismember(big_col_vals,col_vals);
            [~,ridx] = ismember(big_row_vals,row_vals);
            idx = unique([cidx',ridx]);
            
            %check ratio of row & col value
            to_remove = [];
            for j = 1:length(idx)
                colval = avg_similarity_matrix(idx(j),i);
                rowval = avg_similarity_matrix(i,idx(j));
                if colval > rowval
                    val_ratio = rowval/colval;
                else
                    val_ratio = colval/rowval;
                end %if
                %remove from index list if avg is not above threshold
                if (val_ratio <= val_ratio_threshold)
                    to_remove = [to_remove,j]; 
                end %if
            end %for j
            idx(to_remove) = [];
            
            other_labels = labels(idx);
            other_labels = other_labels(other_labels > 0);
            
            if (isempty(other_labels) || (max(other_labels) == 0)) 
                 %we have a new unique label
                labels(i) = unique_label;
                unique_label = unique_label + 1;
            elseif (length(unique(other_labels)) == 1)
                %use this label
                labels(i) = other_labels(1);
            else
                %still need some work here--how to choose between 2 labels?
                fprintf('BAD JUJU HERE\n');
                display(i);
                display(labels);
                display(other_labels);
            end %if isempty
        end %if        
    end %for i
    iter_count = iter_count + 1;
end %while
end %function