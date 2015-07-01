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
[numpeaks0new, peakxys0new,scores0new] = find_objects(plan0_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data0 = cluster_detections_by_object(plan0_new.detection_data, peakxys0new, 0.5);
sort_by_cluster(cluster_data0,img_dir0);
[xy_with_label0new,avg_similarity_matrix0new] = sort_clusters_single_floorplan(peakxys0new,img_dir0);
toc

fprintf('plan1: ');
tic;
[numpeaks1new, peakxys1new,scores1new] = find_objects(plan1_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data1 = cluster_detections_by_object(plan1_new.detection_data, peakxys1new, 0.5);
sort_by_cluster(cluster_data1,img_dir1);
[xy_with_label1new,avg_similarity_matrix1new] = sort_clusters_single_floorplan(peakxys1new,img_dir1);
toc

fprintf('plan2: ');
tic;
[numpeaks2new, peakxys2new,scores2new] = find_objects(plan2_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data2 = cluster_detections_by_object(plan2_new.detection_data, peakxys2new, 0.5);
sort_by_cluster(cluster_data2,img_dir2);
[xy_with_label2new,avg_similarity_matrix2new] = sort_clusters_single_floorplan(peakxys2new,img_dir2);
toc

fprintf('plan3: ');
tic;
[numpeaks3new, peakxys3new,scores3new] = find_objects(plan3_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data3 = cluster_detections_by_object(plan3_new.detection_data, peakxys3new, 0.5);
sort_by_cluster(cluster_data3,img_dir3);
[xy_with_label3new,avg_similarity_matrix3new] = sort_clusters_single_floorplan(peakxys3new,img_dir3);
toc

fprintf('plan4: ');
tic;
[numpeaks4new, peakxys4new,scores4new] = find_objects(plan4_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data4 = cluster_detections_by_object(plan4_new.detection_data, peakxys4new, 0.5);
sort_by_cluster(cluster_data4,img_dir4);
[xy_with_label4new,avg_similarity_matrix4new] = sort_clusters_single_floorplan(peakxys4new,img_dir4);
toc

fprintf('plan5: ');
tic;
[numpeaks5new, peakxys5new,scores5new] = find_objects(plan5_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data5 = cluster_detections_by_object(plan5_new.detection_data, peakxys5new, 0.5);
sort_by_cluster(cluster_data5,img_dir5);
[xy_with_label5new,avg_similarity_matrix5new] = sort_clusters_single_floorplan(peakxys5new,img_dir5);
toc

fprintf('plan6: ');
tic;
[numpeaks6new, peakxys6new,scores6new] = find_objects(plan6_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data6 = cluster_detections_by_object(plan6_new.detection_data, peakxys6new, 0.5);
sort_by_cluster(cluster_data6,img_dir6);
[xy_with_label6new,avg_similarity_matrix6new] = sort_clusters_single_floorplan(peakxys6new,img_dir6);
toc

fprintf('plan7: ');
tic;
[numpeaks7new, peakxys7new,scores7new] = find_objects(plan7_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data7 = cluster_detections_by_object(plan7_new.detection_data, peakxys7new, 0.5);
sort_by_cluster(cluster_data7,img_dir7);
[xy_with_label7new,avg_similarity_matrix7new] = sort_clusters_single_floorplan(peakxys7new,img_dir7);
toc

fprintf('plan8: ');
tic;
[numpeaks8new, peakxys8new,scores8new] = find_objects(plan8_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data8 = cluster_detections_by_object(plan8_new.detection_data, peakxys8new, 0.5);
sort_by_cluster(cluster_data8,img_dir8);
[xy_with_label8new,avg_similarity_matrix8new] = sort_clusters_single_floorplan(peakxys8new,img_dir8);
toc

fprintf('plan9: ');
tic;
[numpeaks9new, peakxys9new,scores9new] = find_objects(plan9_new.detection_data, xmin, xmax,ymin, ymax, cm_between, gaussian_variance);
cluster_data9 = cluster_detections_by_object(plan9_new.detection_data, peakxys9new, 0.5);
sort_by_cluster(cluster_data9,img_dir9);
[xy_with_label9new,avg_similarity_matrix9new] = sort_clusters_single_floorplan(peakxys9new,img_dir9);
toc