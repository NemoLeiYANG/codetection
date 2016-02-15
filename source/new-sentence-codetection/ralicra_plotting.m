function ralicra_plotting(detection_data, output_path)

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
set(hfig0,'Position',[0 0 800 600]);
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
tic;[numpeaks, peakxys,scores_out] = find_objects(detection_data, xmin,xmax, ymin, ymax, cm_between, gaussian_variance);toc
xpoints = xmin:(cm_between/100):xmax;
ypoints = ymax:-(cm_between/100):ymin;
[X,Y] = meshgrid(xpoints,ypoints);
hfig = figure('visible','off');
set(hfig,'Position',[0 0 800 700])
surf(X,Y,scores_out,'Edgecolor','none');
axis([-4 4 -4 4 -0.002 0.2]);
colorbar;
xlabel('World X (meters)');
ylabel('World Y (meters)');
zlabel('S_{x,y}');
surfacename = sprintf('%s/surface.png',output_path);
title(surfacename);
saveas(hfig,surfacename);

%contour plot with centroids and ground truth marked
hfig2=figure('visible','off');
set(hfig2,'Position',[0 0 800 700]);
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
%plot ground truth (plan0 generation)
plot(1.37,0,'d','MarkerEdgeColor','m','MarkerFaceColor','m')
text(1.37,-0.20,'CONE','FontWeight','bold')
plot(-1.37,0,'d','MarkerEdgeColor','m','MarkerFaceColor','m')
text(-1.37,-0.20,'BAG','FontWeight','bold')
plot(-1.37,-1.304,'d','MarkerEdgeColor','m','MarkerFaceColor','m')
text(-1.37,-1.504,'CHAIR','FontWeight','bold')
text(1.37,-1.504,'CHAIR','FontWeight','bold')
plot(1.37,-1.304,'d','MarkerEdgeColor','m','MarkerFaceColor','m')
plot(0,-1.304,'d','MarkerEdgeColor','m','MarkerFaceColor','m')
text(0,-1.504,'TABLE','FontWeight','bold')
%plot centroids
for i = 1:length(peakxys)
plot(peakxys(i,1),peakxys(i,2),'s','MarkerEdgeColor','b','MarkerFaceColor','b')
end
contourname = sprintf('%s/contour.png',output_path);
title(contourname);
saveas(hfig2,contourname);
