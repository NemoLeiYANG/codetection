function contour_plot(detection_data,ground_truth,output_path)

%params
xmin = -3; xmax = 3.05; ymin = -2.62; ymax = 3.93;
cm_between = 5; gaussian_variance = 0.25;
xpoints = xmin:(cm_between/100):xmax;
ypoints = ymax:-(cm_between/100):ymin;
[X,Y] = meshgrid(xpoints,ypoints);  

[numpeaks, peakxys,scores_out] = find_objects(detection_data, xmin,xmax, ymin, ymax, cm_between, gaussian_variance);

%contour plot with centroids and ground truth marked
hfig2=figure('visible','off');
set(hfig2,'Position',[0 0 1600 1400]);
%set up grid
hold on;
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
xlabel('World X (meters)')
ylabel('World Y (meters)')
%plot contour
contour(X,Y,scores_out)
colorbar
%ground truth
scatter(ground_truth(:,1),ground_truth(:,2),'d','MarkerEdgeColor','m','MarkerFaceColor','m')
%plot centroids
for i = 1:length(peakxys)
plot(peakxys(i,1),peakxys(i,2),'s','MarkerEdgeColor','b','MarkerFaceColor','b')
end
contourname = sprintf('%s/contour.png',output_path);
title(contourname);
saveas(hfig2,contourname);
