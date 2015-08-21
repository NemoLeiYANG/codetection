img_dir0 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/ralicra2016/plan0/detections-test20150618/';
img_dir5 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/ralicra2016/plan5/detections-test20150618/';
img_dir6 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/ralicra2016/plan6/detections-test20150618/';
img_dir7 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/ralicra2016/plan7/detections-test20150618/';
img_dir8 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/ralicra2016/plan8/detections-test20150618/';
img_dir9 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/ralicra2016/plan9/detections-test20150618/';
xmin = -3; xmax = 3.05; ymin = -2.62; ymax = 3.93;
cm_between = 5; gaussian_variance = 0.25;

fprintf('plan0: ');
tic;
plan0_new = load(strcat(img_dir0,'detection_data.mat'));
[numpeaks0new, peakxys0new,scores0new] = find_objects(plan0_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data0 = cluster_detections_by_object(plan0_new.detection_data, peakxys0new, 0.5);
sort_by_cluster(cluster_data0,img_dir0);
[xy_with_label0new,avg_similarity_matrix0new] = sort_clusters_single_floorplan(peakxys0new,img_dir0);
toc

fprintf('plan5: ');
tic;
plan5_new = load(strcat(img_dir5,'detection_data.mat'));
[numpeaks5new, peakxys5new,scores5new] = find_objects(plan5_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data5 = cluster_detections_by_object(plan5_new.detection_data, peakxys5new, 0.5);
sort_by_cluster(cluster_data5,img_dir5);
[xy_with_label5new,avg_similarity_matrix5new] = sort_clusters_single_floorplan(peakxys5new,img_dir5);
toc

fprintf('plan6: ');
tic;
plan6_new = load(strcat(img_dir6,'detection_data.mat'));
[numpeaks6new, peakxys6new,scores6new] = find_objects(plan6_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data6 = cluster_detections_by_object(plan6_new.detection_data, peakxys6new, 0.5);
sort_by_cluster(cluster_data6,img_dir6);
[xy_with_label6new,avg_similarity_matrix6new] = sort_clusters_single_floorplan(peakxys6new,img_dir6);
toc

fprintf('plan7: ');
tic;
plan7_new = load(strcat(img_dir7,'detection_data.mat'));
[numpeaks7new, peakxys7new,scores7new] = find_objects(plan7_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data7 = cluster_detections_by_object(plan7_new.detection_data, peakxys7new, 0.5);
sort_by_cluster(cluster_data7,img_dir7);
[xy_with_label7new,avg_similarity_matrix7new] = sort_clusters_single_floorplan(peakxys7new,img_dir7);
toc

fprintf('plan8: ');
tic;
plan8_new = load(strcat(img_dir8,'detection_data.mat'));
[numpeaks8new, peakxys8new,scores8new] = find_objects(plan8_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data8 = cluster_detections_by_object(plan8_new.detection_data, peakxys8new, 0.5);
sort_by_cluster(cluster_data8,img_dir8);
[xy_with_label8new,avg_similarity_matrix8new] = sort_clusters_single_floorplan(peakxys8new,img_dir8);
toc

fprintf('plan9: ');
tic;
plan9_new = load(strcat(img_dir9,'detection_data.mat'));
[numpeaks9new, peakxys9new,scores9new] = find_objects(plan9_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data9 = cluster_detections_by_object(plan9_new.detection_data, peakxys9new, 0.5);
sort_by_cluster(cluster_data9,img_dir9);
[xy_with_label9new,avg_similarity_matrix9new] = sort_clusters_single_floorplan(peakxys9new,img_dir9);
toc