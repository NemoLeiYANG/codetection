function house_make_plots_new(path, testdir, detection_data, xmin, xmax, ymin, ymax, cm_between, gaussian_variance)
%testdir = 'test20151117';
close all;
numpeaks = 0;
% if (isempty(detection_data))
%     fprintf('NO DETECTIONS in %s/%s\n',path,testdir);
% else
%scatter plot
hfig0=figure('visible','off');
set(hfig0,'Position',[0 0 1600 1200]);
hold on;
%set up grid
plot([xmin xmin xmax xmax xmax],[ymin ymax ymax ymin ymin],'k-')
plot([xmin xmin xmax xmax xmin],[ymin ymax ymax ymin ymin],'k-')
plot(0,0,'g*');
text(0,0,'\leftarrow start');
xlabel('World X (meters)')
ylabel('World Y (meters)')
axis([xmin xmax ymin ymax]);
box on;
%plot data (or text)
if (isempty(detection_data))
    text(1,1,'NO DETECTIONS FOUND');
else
    scatter(detection_data(:,1),detection_data(:,2));
end %if
scattername = sprintf('%s%s/scatter.png',path, testdir);
th=title(scattername);
set(th,'interpreter','none');
saveas(hfig0,scattername);

%surface plot

xpoints = xmin:(cm_between/100):xmax;
ypoints = ymax:-(cm_between/100):ymin;
[X,Y] = meshgrid(xpoints,ypoints);
hfig = figure('visible','off');
set(hfig,'Position',[0 0 1600 1400])
xlabel('World X (meters)');
ylabel('World Y (meters)');
zlabel('S_{x,y}');
if (isempty(detection_data))
    fprintf('NO DETECTIONS FOUND\n');
    scores_out = zeros(size(X));
    text(0,0,0,'NO DETECTIONS FOUND');
else
    tic;[numpeaks, peakxys,scores_out] = find_objects(detection_data, xmin,xmax, ymin, ymax, cm_between, gaussian_variance);toc
    fprintf('\nfound %d peaks in %s\n', numpeaks, path)
end %if
surf(X,Y,scores_out,'Edgecolor','none');
colorbar;
axis([xmin xmax ymin ymax -0.001 max((1.1*max(max(scores_out))),0.001)]);
surfacename = sprintf('%s%s/surface.png',path, testdir);
th=title(surfacename);
set(th,'interpreter','none');
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
plot(0,0,'g*');
text(0,0,'\leftarrow start');
if (max(max(scores_out)) > 0)
    %plot contour
    contour(X,Y,scores_out)
    colorbar
else
    text(1,1,'NO DETECTIONS FOUND');
end %if

if (numpeaks > 0)
    %plot centroids
    for i = 1:numpeaks %length(peakxys)
        plot(peakxys(i,1),peakxys(i,2),'s','MarkerEdgeColor','b','MarkerFaceColor','b')
        text(peakxys(i,1),peakxys(i,2),'\leftarrow detected peak')
    end %for
end %if
axis([xmin xmax ymin ymax]);
contourname = sprintf('%s%s/contour.png',path, testdir);
th=title(contourname);
set(th,'interpreter','none');
saveas(hfig2,contourname);
% end %if


close all;
end %function