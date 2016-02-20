function ralicra_scatter2(detection_data, ground_truth, output_path)

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
scattername = sprintf('%s/best-unary-scatter.png',output_path);
scattertitle = sprintf('Plot of Best Unary Score in Each Frame');
title(scattertitle);
saveas(hfig0,scattername);
    
