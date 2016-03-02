function detection_data_out = preprocess_detection_data(detection_data)
    detection_data_out = detection_data;
%     minscore = min(detection_data(:,3));
%     maxscore = max(detection_data(:,3));
%     minfreq = min(detection_data(:,4));
%     maxfreq = max(detection_data(:,4));
    good_points=[];
    for i = 1:length(detection_data)
        if (detection_data(i,3) ~= 0)
            good_points = [good_points;detection_data(i,:)];
            %detection_data_out(i,3) = minscore + (maxscore-minscore)*rand;  
        end %if
%         if (detection_data(i,4) == 0)
%             detection_data_out(i,4) = minfreq + (maxfreq-minfreq)*rand;  
%         end %if
    end %for
    detection_data_out = good_points;
end %function