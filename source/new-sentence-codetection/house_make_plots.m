function house_make_plots(path, detection_data, xmin, xmax, ymin, ymax, cm_between, gaussian_variance)
testdir = 'test20151117';
close all;

%scatter plot
hfig0=figure('visible','off');
set(hfig0,'Position',[0 0 1600 1200]);
hold on;
scatter(detection_data(:,1),detection_data(:,2));
%set up grid
plot([xmin xmin xmax xmax xmax],[ymin ymax ymax ymin ymin],'k-')
plot([xmin xmin xmax xmax xmin],[ymin ymax ymax ymin ymin],'k-')
plot(0,0,'g*');
text(0,0,'\leftarrow start');
xlabel('World X (meters)')
ylabel('World Y (meters)')
axis([xmin xmax ymin ymax]);
box on;
scattername = sprintf('%s%s/scatter.png',path, testdir);
title(scattername);
saveas(hfig0,scattername);

%surface plot
tic;[numpeaks, peakxys,scores_out] = find_objects(detection_data, xmin,xmax, ymin, ymax, cm_between, gaussian_variance);toc
fprintf('\nfound %d peaks in %s\n', numpeaks, path)
xpoints = xmin:(cm_between/100):xmax;
ypoints = ymax:-(cm_between/100):ymin;
[X,Y] = meshgrid(xpoints,ypoints);
hfig = figure('visible','off');
set(hfig,'Position',[0 0 1600 1400])
surf(X,Y,scores_out,'Edgecolor','none');
colorbar;
xlabel('World X (meters)');
ylabel('World Y (meters)');
zlabel('S_{x,y}');
axis([xmin xmax ymin ymax -0.001 (1.1*max(max(scores_out)))]);
surfacename = sprintf('%s%s/surface.png',path, testdir);
title(surfacename);
saveas(hfig,surfacename);

%contour plot with centroids marked
hfig2=figure('visible','off');
set(hfig2,'Position',[0 0 1600 1400]);
%set up grid
hold on;
plot([xmin xmin xmax xmax xmax],[ymin ymax ymax ymin ymin],'k-')
plot([xmin xmin xmax xmax xmin],[ymin ymax ymax ymin ymin],'k-')
box on;
xlabel('World X (meters)')
ylabel('World Y (meters)')
%plot contour
contour(X,Y,scores_out)
colorbar
plot(0,0,'g*');
text(0,0,'\leftarrow start');
%plot centroids
for i = 1:numpeaks %length(peakxys)
    plot(peakxys(i,1),peakxys(i,2),'s','MarkerEdgeColor','b','MarkerFaceColor','b')
    text(peakxys(i,1),peakxys(i,2),'\leftarrow detected peak')
end
axis([xmin xmax ymin ymax]);
contourname = sprintf('%s%s/contour.png',path, testdir);
title(contourname);
saveas(hfig2,contourname);


close all;
end %function