img_dir0 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan0/detections-test20150618/';
img_dir1 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan1/detections-test20150618/';
img_dir2 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan2/detections-test20150618/';
img_dir3 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan3/detections-test20150618/';
img_dir4 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan4/detections-test20150618/';
img_dir5 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan5/detections-test20150618/';
img_dir6 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan6/detections-test20150618/';
img_dir7 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan7/detections-test20150618/';
img_dir8 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan8/detections-test20150618/';
img_dir9 = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan9/detections-test20150618/';
xmin = -3; xmax = 3.05; ymin = -2.62; ymax = 3.93;
cm_between = 5; gaussian_variance = 0.25;

fprintf('plan0: ');
tic;
plan0_data = load(strcat(img_dir0,'detection_data.mat'));
[numpeaks0new, peakxys0new,scores0new] = find_objects(plan0_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data0 = cluster_detections_by_object(plan0_data.detection_data, peakxys0new, 0.5);
sort_by_cluster(cluster_data0,img_dir0);
[xy_with_label0,avg_similarity_matrix0] = sort_clusters_single_floorplan(peakxys0new,img_dir0);
toc

fprintf('plan1: ');
tic;
plan1_data = load(strcat(img_dir1,'detection_data.mat'));
[numpeaks1new, peakxys1new,scores1new] = find_objects(plan1_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data1 = cluster_detections_by_object(plan1_data.detection_data, peakxys1new, 0.5);
sort_by_cluster(cluster_data1,img_dir1);
[xy_with_label1,avg_similarity_matrix1] = sort_clusters_single_floorplan(peakxys1new,img_dir1);
toc

fprintf('plan2: ');
tic;
plan2_data = load(strcat(img_dir2,'detection_data.mat'));
[numpeaks2new, peakxys2new,scores2new] = find_objects(plan2_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data2 = cluster_detections_by_object(plan2_data.detection_data, peakxys2new, 0.5);
sort_by_cluster(cluster_data2,img_dir2);
[xy_with_label2,avg_similarity_matrix2] = sort_clusters_single_floorplan(peakxys2new,img_dir2);
toc

fprintf('plan3: ');
tic;
plan3_data = load(strcat(img_dir3,'detection_data.mat'));
[numpeaks3new, peakxys3new,scores3new] = find_objects(plan3_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data3 = cluster_detections_by_object(plan3_data.detection_data, peakxys3new, 0.5);
sort_by_cluster(cluster_data3,img_dir3);
[xy_with_label3,avg_similarity_matrix3] = sort_clusters_single_floorplan(peakxys3new,img_dir3);
toc

fprintf('plan4: ');
tic;
plan4_data = load(strcat(img_dir4,'detection_data.mat'));
[numpeaks4new, peakxys4new,scores4new] = find_objects(plan4_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data4 = cluster_detections_by_object(plan4_data.detection_data, peakxys4new, 0.5);
sort_by_cluster(cluster_data4,img_dir4);
[xy_with_label4,avg_similarity_matrix4] = sort_clusters_single_floorplan(peakxys4new,img_dir4);
toc

fprintf('plan5: ');
tic;
plan5_data = load(strcat(img_dir5,'detection_data.mat'));
[numpeaks5new, peakxys5new,scores5new] = find_objects(plan5_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data5 = cluster_detections_by_object(plan5_data.detection_data, peakxys5new, 0.5);
sort_by_cluster(cluster_data5,img_dir5);
[xy_with_label5,avg_similarity_matrix5] = sort_clusters_single_floorplan(peakxys5new,img_dir5);
toc

fprintf('plan6: ');
tic;
plan6_data = load(strcat(img_dir6,'detection_data.mat'));
[numpeaks6new, peakxys6new,scores6new] = find_objects(plan6_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data6 = cluster_detections_by_object(plan6_data.detection_data, peakxys6new, 0.5);
sort_by_cluster(cluster_data6,img_dir6);
[xy_with_label6,avg_similarity_matrix6] = sort_clusters_single_floorplan(peakxys6new,img_dir6);
toc

fprintf('plan7: ');
tic;
plan7_data = load(strcat(img_dir7,'detection_data.mat'));
[numpeaks7new, peakxys7new,scores7new] = find_objects(plan7_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data7 = cluster_detections_by_object(plan7_data.detection_data, peakxys7new, 0.5);
sort_by_cluster(cluster_data7,img_dir7);
[xy_with_label7,avg_similarity_matrix7] = sort_clusters_single_floorplan(peakxys7new,img_dir7);
toc

fprintf('plan8: ');
tic;
plan8_data = load(strcat(img_dir8,'detection_data.mat'));
[numpeaks8new, peakxys8new,scores8new] = find_objects(plan8_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data8 = cluster_detections_by_object(plan8_data.detection_data, peakxys8new, 0.5);
sort_by_cluster(cluster_data8,img_dir8);
[xy_with_label8,avg_similarity_matrix8] = sort_clusters_single_floorplan(peakxys8new,img_dir8);
toc

fprintf('plan9: ');
tic;
plan9_data = load(strcat(img_dir9,'detection_data.mat'));
[numpeaks9new, peakxys9new,scores9new] = find_objects(plan9_data.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data9 = cluster_detections_by_object(plan9_data.detection_data, peakxys9new, 0.5);
sort_by_cluster(cluster_data9,img_dir9);
[xy_with_label9,avg_similarity_matrix9] = sort_clusters_single_floorplan(peakxys9new,img_dir9);
toc