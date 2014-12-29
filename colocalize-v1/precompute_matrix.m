function precompute_matrix
%% PRECOMPUTE MATRICES USED IN QP

	globals;

	% set up vlfeat
	addpath(genpath(vlfeat_dir));
	vl_setup;

	% load feat
	load([tmp_dir 'feat.mat']);

	% initialize variables
	X = [];
	box_obj = [];
	var_index = []; % image box_index

	% loop through images
	for j = 1:numel(feat)

		% feat
		X = vertcat(X, feat(j).hist(1:param.num_boxes,:));

		% box scores
		box_obj = vertcat(box_obj, feat(j).boxes(1:param.num_boxes,end));

		% var index
		var_index = vertcat(var_index, [j*ones(1,param.num_boxes); 1:param.num_boxes]');

	end

	N = size(X,1);

	% compute index matrix
	savename = [tmp_dir 'qp_index'];
	save(savename, 'var_index', '-v7.3');


	% compute linear term (box prior)
	linVector = -log(box_obj + eps);
	linVector = linVector / sum(linVector);
	savename = [tmp_dir 'qp_linVector'];
	save(savename, 'linVector', '-v7.3');


	% compute Laplacian matrix (box similarity)
	disp('Computing Laplacian matrix...')
	Xchi = vl_alldist2(X', 'CHI2');
	Xchi = exp(-param.gamma * Xchi);
	Dinvroot = sparse(diag(sqrt(1 ./ (sum(Xchi)+eps))));
	lapMatrix = sparse(1:N, 1:N, 1) - Dinvroot * Xchi * Dinvroot;
	lapMatrix = lapMatrix / trace(lapMatrix);
	savename = [tmp_dir 'qp_lapMatrix'];
	save(savename, 'lapMatrix', '-v7.3');


	% compute ridge regression matrix (box discriminability)
	disp('Computing ridge regression matrix...')
	X = X(:,end-999:end);
	P = sparse(1:N, 1:N, 1) - 1 / N;
	PX = P * X;
	rrMatrix = P' * (sparse(1:N, 1:N, 1) - PX * (PX'*PX + N * param.kappa * sparse(1:size(X,2), 1:size(X,2), 1))^-1 * PX') * P;
	rrMatrix = rrMatrix / trace(rrMatrix);
	savename = [tmp_dir 'qp_rrMatrix'];
	save(savename, 'rrMatrix', '-v7.3');
