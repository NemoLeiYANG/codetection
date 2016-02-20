function ralicra_scatter(detection_data, ground_truth, output_path)

%%%% slight mod to detection_data to smooth out spurious peak in plan0
% detection_data_mod = detection_data;
% for i = 1:length(detection_data_mod)
%     if ((detection_data_mod(i,1) < -1.8) && (detection_data_mod(i,2) < -1.8))
%         detection_data_mod(i,4) = .2*detection_data_mod(i,4);
%     end
% end
% detection_data = detection_data_mod;
% save('detection_data.mat','detection_data');
%%%%

%params
xmin = -3; xmax = 3.05; ymin = -2.62; ymax = 3.93;
cm_between = 5; gaussian_variance = 0.25;
    
%scatter plot
hfig0=figure('visible','off');
set(hfig0,'Position',[0 0 1600 1200]);
hold on;
scatter(detection_data(:,1),detection_data(:,2));
%set up grid
plot([xmin xmin xmax xmax xmax],[ymin ymax ymax ymin ymin],'k-')
plot([xmin xmin xmax xmax xmin],[ymin ymax ymax ymin ymin],'k-')
axis([-3.5 3.5 -3 4.5])
box on;
plot([xmin xmax],[-1.31 -1.31],'k--')
plot([xmin xmax],[1.31 1.31],'k--')
plot([xmin xmax],[2.62 2.62],'k--')
plot([xmin xmax],[0 0],'k-')
plot([0 0],[ymin ymax],'k-')
plot([-1.37 -1.37],[ymin ymax],'k--')
plot([1.37 1.37],[ymin ymax],'k--')
%ground truth
scatter(ground_truth(:,1),ground_truth(:,2),'d','MarkerEdgeColor','m','MarkerFaceColor','m')
xlabel('World X (meters)')
ylabel('World Y (meters)')
scattername = sprintf('%s/gm1-scatter.png',output_path);
scattertitle = sprintf('Plot of Grahical Model #1 selections');
title(scattertitle);
saveas(hfig0,scattername);
    
