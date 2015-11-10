function labels = labels_from_avg_similarity_matrix(avg_similarity_matrix)

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
        fprintf('************exiting after too many iterations********\n');
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
            ratio_vals = [];
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
                else
                    ratio_vals = [ratio_vals, val_ratio];
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
            elseif (iter_count > 1)
                %still need some work here--how to choose between 2 or more labels?
%                 fprintf('BAD JUJU HERE\n');
                %display(i);
%                 fprintf('i = %d\n',i);
%                 display(labels');
                %fprintf('labels = %d %d %d %d %d\n',labels);
                %display(other_labels');
%                 fprintf('other_labels = %d %d %d %d %d\n',other_labels);
                if (length(other_labels) > 2)
                    %try voting
                    possible_labels = unique(other_labels);
                    vote_count = zeros(length(possible_labels),1);
                    for k = 1:length(possible_labels)
                        vote_count(k) = sum(other_labels == possible_labels(k));
                    end %for k
                    label_idx = find(vote_count == max(vote_count));
                    if (length(label_idx) == 1)
%                         fprintf('SUCCESS!!!!!!!\n');
                        labels(i) = possible_labels(label_idx);
                    else
%                         fprintf('ERROR--tied vote\n')
%                         display(possible_labels);
%                         display(vote_count);
%                         display(idx);
%                         display(ridx);
%                         display(cidx);
%                         display(ratio_vals);
                        label_idx = find(ratio_vals == max(ratio_vals));
                        if (length(label_idx) == 1)
%                             fprintf('Success 2\n');                       
                            labels(i) = other_labels(label_idx);
                        else
                            fprintf('THIS SHOULDN''T HAPPEN!!\n');
                        end %if
                    end %if length(label_idx)
                else
                    %use label with larger ratio
                    fprintf('\n\n***Hit length(other_labels == 2 case***\n\n');
                    label_idx = find(ratio_vals == max(ratio_vals));
                    if (length(label_idx) == 1)
                        %                             fprintf('Success 2\n');
                        labels(i) = other_labels(label_idx);
                    else
                        fprintf('THIS SHOULDN''T HAPPEN!!    2 \n');
                    end %if
                end %if length(other_labels)
%             else
%                 fprintf('i = %d, KEEP GOING!\n',i)
            end %if isempty
        end %if        
    end %for i
%     if (iter_count == 1)
%         display(labels);
%     end
    iter_count = iter_count + 1;
end %while

%now do 1 loop backwards through label #s, looking for matches with lower #
if (M > 10) %only do on big matrix, not individual ones
    relaxed_val_ratio_threshold = 0.8 * val_ratio_threshold;
    for i = (unique_label - 1):-1:1
        rc_idx = find(labels == i);
        for k = 1:length(rc_idx);
            diagonal_value = avg_similarity_matrix(rc_idx(k),rc_idx(k));
            row_vals = avg_similarity_matrix(rc_idx(k),:);
            col_vals = avg_similarity_matrix(:,rc_idx(k));
            row_wo_diag = row_vals(row_vals ~= diagonal_value);
            col_wo_diag = col_vals(col_vals ~= diagonal_value);
            
            big_col_vals = col_wo_diag(col_wo_diag > ...
                (similarity_ratio_factor * diagonal_value));
            big_row_vals = row_wo_diag(row_wo_diag > ...
                (similarity_ratio_factor * diagonal_value));
            
            [~,cidx] = ismember(big_col_vals,col_vals);
            [~,ridx] = ismember(big_row_vals,row_vals);
            idx = unique([cidx',ridx]);
            
%             display(i)
%             display(rc_idx(k))
%             display(idx)
            
            %check ratio of row & col value
            to_remove = [];
            ratio_vals = [];
            for j = 1:length(idx)
                colval = avg_similarity_matrix(idx(j),rc_idx(k));
                rowval = avg_similarity_matrix(rc_idx(k),idx(j));
                if colval > rowval
                    val_ratio = rowval/colval;
                else
                    val_ratio = colval/rowval;
                end %if
                %remove from index list if avg is not above threshold
                if (val_ratio <= relaxed_val_ratio_threshold)
                    to_remove = [to_remove,j];
                else
                    ratio_vals = [ratio_vals, val_ratio];
                end %if
            end %for j
            idx(to_remove) = [];
            other_labels = labels(idx);
            %other_labels = other_labels(other_labels ~= i);
            
%             display(to_remove)
%             display(idx)
%             display(ratio_vals)
%             display(other_labels)
            
            if isempty(other_labels)
                %no change
                fprintf('no change for label = %d\n',i)
            elseif (length(unique(other_labels)) == 1)
                new_label = other_labels(1);
                if (labels(rc_idx(k)) ~= new_label)
                    %relabel with this label
                    labels(rc_idx(k)) = new_label;
                    fprintf('changed label %d to %d for rc_idx = %d\n',i,new_label,rc_idx(k));
                else
                    fprintf('rc_idx %d remains with label %d\n',rc_idx(k),labels(rc_idx(k)));
                end %if
            elseif (length(other_labels) > 2)
                    %try voting BUT ADD OWN LABEL to other_labels
                    other_labels = [other_labels; i];
                    possible_labels = unique(other_labels);
                    vote_count = zeros(length(possible_labels),1);
                    for m = 1:length(possible_labels)
                        vote_count(m) = sum(other_labels == possible_labels(m));
                    end %for m
                    label_idx = find(vote_count == max(vote_count));
                    if (length(label_idx) == 1)
%                         fprintf('SUCCESS!!!!!!!\n');
                        labels(rc_idx(k)) = possible_labels(label_idx);
                        fprintf('VOTED and label %d became label %d for rc_idx = %d\n',i,labels(rc_idx(k)),rc_idx(k));
                    else
%                         fprintf('ERROR--tied vote\n')
%                         display(possible_labels);
%                         display(vote_count);
%                         display(idx);
%                         display(ridx);
%                         display(cidx);
%                         display(ratio_vals);
                        label_idx = find(ratio_vals == max(ratio_vals));
                        if (length(label_idx) == 1)
%                             fprintf('Success 2\n');                       
                            labels(rc_idx(k)) = other_labels(label_idx);
                            fprintf('TIED VOTE so label %d became label %d for rc_idx = %d\n',i,labels(rc_idx(k)),rc_idx(k));
                        else
                            fprintf('THIS SHOULDN''T HAPPEN!!\n');
                        end %if
                    end %if length(label_idx)
                else
                    %use label with larger ratio
                    fprintf('\n\n***Hit length(other_labels == 2 case***\n\n');
                    label_idx = find(ratio_vals == max(ratio_vals));
                    if (length(label_idx) == 1)
                        %                             fprintf('Success 2\n');
                        labels(i) = other_labels(label_idx);
                    else
                        fprintf('THIS SHOULDN''T HAPPEN!!    2 \n');
                    end %if
               
%             else
%                 fprintf('still need to write this one\n');
%                 display(i)
%                 display(rc_idx(k))
%                 display(idx)
%                 display(to_remove)
%                 display(idx)
%                 display(ratio_vals)
%                 display(other_labels)
            end %if isempty
            
            
        end %for k        
    end %for i
end %if M

end %function