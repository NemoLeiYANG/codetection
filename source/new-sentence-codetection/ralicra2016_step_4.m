dataset_dir = '/aux/sbroniko/vader-rover/logs/MSEE1-dataset/ralicra2016/';
data_output_dirname = 'detections-test20150618';

[sim_dsift_chisq, sim_dsift_emd, sim_chist_chisq_3d, sim_chist_emd_3d, sim_chist_chisq_2d, sim_chist_emd_2d] = ...
    step_4_build_similarity_matrix(dataset_dir,data_output_dirname,0.50);

save('ralicra2016_asm.mat',...
    'sim_dsift_chisq','sim_dsift_emd',...
    'sim_chist_chisq_3d','sim_chist_emd_3d',...
    'sim_chist_chisq_2d','sim_chist_emd_2d');

fprintf('ralicra2016_step_4 complete\n');