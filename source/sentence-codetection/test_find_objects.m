tic;
[numpeaks0new, peakxys0new,scores0new] = find_objects(plan0_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
[numpeaks1new, peakxys1new,scores1new] = find_objects(plan1_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
[numpeaks2new, peakxys2new,scores2new] = find_objects(plan2_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
[numpeaks3new, peakxys3new,scores3new] = find_objects(plan3_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
[numpeaks4new, peakxys4new,scores4new] = find_objects(plan4_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
[numpeaks5new, peakxys5new,scores5new] = find_objects(plan5_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
[numpeaks6new, peakxys6new,scores6new] = find_objects(plan6_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
[numpeaks7new, peakxys7new,scores7new] = find_objects(plan7_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
[numpeaks8new, peakxys8new,scores8new] = find_objects(plan8_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
[numpeaks9new, peakxys9new,scores9new] = find_objects(plan9_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
toc

showplots(scores0new,peakxys0new,'0 NEW');
showplots(scores1new,peakxys1new,'1 NEW');
showplots(scores2new,peakxys2new,'2 NEW');
showplots(scores3new,peakxys3new,'3 NEW');
showplots(scores4new,peakxys4new,'4 NEW');
showplots(scores5new,peakxys5new,'5 NEW');
showplots(scores6new,peakxys6new,'6 NEW');
showplots(scores7new,peakxys7new,'7 NEW');
showplots(scores8new,peakxys8new,'8 NEW');
showplots(scores9new,peakxys9new,'9 NEW');