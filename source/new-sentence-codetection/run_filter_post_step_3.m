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

fprintf('plan0:');
tic;
filter_image_test(img_dir0);
toc;

fprintf('plan1:');
tic;
filter_image_test(img_dir1);
toc;

fprintf('plan2:');
tic;
filter_image_test(img_dir2);
toc;

fprintf('plan3:');
tic;
filter_image_test(img_dir3);
toc;

fprintf('plan4:');
tic;
filter_image_test(img_dir4);
toc;

fprintf('plan5:');
tic;
filter_image_test(img_dir5);
toc;

fprintf('plan6:');
tic;
filter_image_test(img_dir6);
toc;

fprintf('plan7:');
tic;
filter_image_test(img_dir7);
toc;

fprintf('plan8:');
tic;
filter_image_test(img_dir8);
toc;

fprintf('plan9:');
tic;
filter_image_test(img_dir9);
toc;