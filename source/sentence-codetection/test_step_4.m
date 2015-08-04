dataset_dir = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/';
data_output_dirname = 'detections-test20150618';

[sim_dsift_chisq_05, sim_dsift_emd_05, sim_chist_chisq_3d_05, sim_chist_emd_3d_05, sim_chist_chisq_2d_05, sim_chist_emd_2d_05] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,0.05);

[sim_dsift_chisq_10, sim_dsift_emd_10, sim_chist_chisq_3d_10, sim_chist_emd_3d_10, sim_chist_chisq_2d_10, sim_chist_emd_2d_10] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,0.10);

[sim_dsift_chisq_15, sim_dsift_emd_15, sim_chist_chisq_3d_15, sim_chist_emd_3d_15, sim_chist_chisq_2d_15, sim_chist_emd_2d_15] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,0.15);

[sim_dsift_chisq_20, sim_dsift_emd_20, sim_chist_chisq_3d_20, sim_chist_emd_3d_20, sim_chist_chisq_2d_20, sim_chist_emd_2d_20] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,0.2);

[sim_dsift_chisq_25, sim_dsift_emd_25, sim_chist_chisq_3d_25, sim_chist_emd_3d_25, sim_chist_chisq_2d_25, sim_chist_emd_2d_25] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,0.25);

[sim_dsift_chisq_50, sim_dsift_emd_50, sim_chist_chisq_3d_50, sim_chist_emd_3d_50, sim_chist_chisq_2d_50, sim_chist_emd_2d_50] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,0.50);

[sim_dsift_chisq_75, sim_dsift_emd_75, sim_chist_chisq_3d_75, sim_chist_emd_3d_75, sim_chist_chisq_2d_75, sim_chist_emd_2d_75] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,0.75);

[sim_dsift_chisq_100, sim_dsift_emd_100, sim_chist_chisq_3d_100, sim_chist_emd_3d_100, sim_chist_chisq_2d_100, sim_chist_emd_2d_100] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,1);

save('asm_20150804.mat','sim_dsift_chisq_05','sim_dsift_emd_05',...
    'sim_chist_chisq_3d_05','sim_chist_emd_3d_05','sim_dsift_chisq_10',...
    'sim_dsift_emd_10','sim_chist_chisq_3d_10','sim_chist_emd_3d_10',...
    'sim_dsift_chisq_15','sim_dsift_emd_15','sim_chist_chisq_3d_15',...
    'sim_chist_emd_3d_15','sim_dsift_chisq_20','sim_dsift_emd_20',...
    'sim_chist_chisq_3d_20','sim_chist_emd_3d_20','sim_dsift_chisq_25',...
    'sim_dsift_emd_25','sim_chist_chisq_3d_25','sim_chist_emd_3d_25',...
    'sim_dsift_chisq_50','sim_dsift_emd_50','sim_chist_chisq_3d_50',...
    'sim_chist_emd_3d_50','sim_dsift_chisq_75','sim_dsift_emd_75',...
    'sim_chist_chisq_3d_75','sim_chist_emd_3d_75','sim_dsift_chisq_100',...
    'sim_dsift_emd_100','sim_chist_chisq_3d_100','sim_chist_emd_3d_100',...
    'sim_chist_chisq_2d_05','sim_chist_emd_2d_05',...
    'sim_chist_chisq_2d_10','sim_chist_emd_2d_10',...
    'sim_chist_chisq_2d_15','sim_chist_emd_2d_15',...
    'sim_chist_chisq_2d_20','sim_chist_emd_2d_20',...
    'sim_chist_chisq_2d_25','sim_chist_emd_2d_25',...
    'sim_chist_chisq_2d_50','sim_chist_emd_2d_50',...
    'sim_chist_chisq_2d_75','sim_chist_emd_2d_75',...
    'sim_chist_chisq_2d_100','sim_chist_emd_2d_100');

fprintf('test_step_4 complete\n');