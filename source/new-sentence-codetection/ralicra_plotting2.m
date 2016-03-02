function ralicra_plotting2(detection_data,scores_out,ground_truth,output_path,peakxys)

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
    
close all;

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
xlabel('World X (meters)')
ylabel('World Y (meters)')
scattername = sprintf('%s/scatter.png',output_path);
title(scattername);
saveas(hfig0,scattername);
    
%surface plot
%tic;[numpeaks, peakxys,scores_out] = find_objects(detection_data, xmin,xmax, ymin, ymax, cm_between, gaussian_variance);toc
xpoints = xmin:(cm_between/100):xmax;
ypoints = ymax:-(cm_between/100):ymin;
[X,Y] = meshgrid(xpoints,ypoints);
hfig = figure('visible','off');
set(hfig,'Position',[0 0 1600 1400])
surf(X,Y,scores_out,'Edgecolor','none');
maxscore = max(max(scores_out));
minscore = min(min(scores_out));
axis([-4 4 -4 4 (minscore - 0.01*maxscore) (maxscore + 0.01*maxscore)]);
colorbar;
xlabel('World X (meters)');
ylabel('World Y (meters)');
zlabel('S_{x,y}');
surfacename = sprintf('%s/surface.png',output_path);
title(surfacename);
saveas(hfig,surfacename);

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
