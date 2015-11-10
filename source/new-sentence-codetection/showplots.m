function showplots(scoresname,peaksname,displayname)
xmin = -3; xmax = 3.05; ymin = -2.62; ymax = 3.93;
[X_5cm,Y_5cm]=meshgrid(xmin:0.05:xmax,ymax:-0.05:ymin);

figure(); 
surf(X_5cm,Y_5cm,scoresname,'EdgeColor','none'); 
hold on; 
title(['Surface plot for ', displayname]); 
hold off;

figure();
contour(X_5cm,Y_5cm, scoresname);
hold on;
plot(peaksname(:,1),peaksname(:,2),'r+');
title(['Contour plot for ', displayname]);
plot([xmin xmin xmax xmax xmax],[ymin ymax ymax ymin ymin],'k-')
plot([xmin xmax],[-1.31 -1.31],'k--')
plot([xmin xmax],[1.31 1.31],'k--')
plot([xmin xmax],[2.62 2.62],'k--')
plot([xmin xmax],[0 0],'k-')
plot([0 0],[ymin ymax],'k-')
plot([-1.37 -1.37],[ymin ymax],'k--')
plot([1.37 1.37],[ymin ymax],'k--')
hold off;



end %function