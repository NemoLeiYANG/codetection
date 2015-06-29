function labels = labels_from_avg_similarity_matrix_old(avg_similarity_matrix)

%now look at avg_similarity values to determine which are alike
%diagonal elements are self-similarity--look in row and column to see if
%any other values are higher than a threshold

similarity_ratio_factor = 0.39;

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
            %end new logic
            
%             max_row_val = max(row_wo_diag);
%             max_col_val = max(col_wo_diag);
%             row_idx = find(row_vals == max_row_val);
%             col_idx = find(col_vals == max_col_val);
%             test1 = ((similarity_ratio_factor*diagonal_value) > max_row_val)
%             test2 = ((similarity_ratio_factor*diagonal_value) > max_col_val)
%             if (test1 && test2)
%                 %we have a new unique label
%                 labels(i) = unique_label;
%                 unique_label = unique_label+1;
%             elseif (test1)
%                 %take label from column if already set, else unique
%                 if (labels(col_idx) ~= 0)
%                     labels(i) = labels(col_idx);
%                 else
%                     labels(i) = unique_label;
%                     unique_label = unique_label + 1;
%                 end %if
%             elseif (test2)
%                 %take label from row if already set, else unique
%                 if (labels(row_idx) ~= 0)
%                     labels(i) = labels(row_idx);
%                 else
%                     labels(i) = unique_label;
%                     unique_label = unique_label + 1;
%                 end %if
%             else
%                 %fprintf('THIS SHOULDN''T HAPPEN');
%                 if (row_idx == col_idx) %same label
%                     labels(i) = labels(row_idx);
%                 else %pick the bigger one
%                     if (max_row_val > max_col_val)
%                         labels(i) = labels(row_idx);
%                     else
%                         labels(i) = labels(col_idx);
%                     end
%                 end
%             end %if
         
            % OLD METHOD
%             [~,rowidx] = max(avg_similarity_matrix(i,:));
%             [~,colidx] = max(avg_similarity_matrix(:,i));
%             if ((rowidx == i) && (colidx == i)) %we have a new unique label
%                 labels(i) = unique_label;
%                 unique_label = unique_label + 1;
%             elseif (colidx ~= i) %copy label from colidx
%                 labels(i) = labels(colidx);
%             elseif (rowidx ~= i) %copy label from rowidx
%                 labels(i) = labels(rowidx);
%             else
%                 fprintf('THIS SHOULDN''T HAPPEN');
%             end % if row && col
        end %if        
    end %for i
    iter_count = iter_count + 1;
end %while
end %function