function solve_qp
%% SOLVE QP USING MATLAB SOLVER AND RECONSTRUCT SOLUTION

	globals;

	% load precomputed matrices
	load([tmp_dir 'qp_index']);
	load([tmp_dir 'qp_linVector']);
	load([tmp_dir 'qp_lapMatrix']);
	load([tmp_dir 'qp_rrMatrix']);

	N = numel(linVector);

	% setup linear vector
	b = param.lambda * linVector;

	% setup quadratic matrix
	A = lapMatrix + param.mu * rrMatrix;

	% set up equality matrix
	Aeq = [];
	unique_im = unique(var_index(:,1), 'rows');
	for i = 1:size(unique_im,1)
		im_index = unique_im(i,:);
		im_inds = ismember(var_index(:,1), im_index, 'rows');
		Aeq = [Aeq; im_inds'];
	end
	beq = ones(1, size(Aeq,1));

	% set up options
	opts = optimset('Diagnostics', 'on', 'Algorithm', 'interior-point');%'interior-point-convex');

	% solve qp
	[x, fval, exitflag, output, lambda] = quadprog(A, b, [], [], Aeq, beq, zeros(1,N), ones(1,N), [], opts);

	% reconstruct solution
	[~, box_sol_inds] = max(reshape(x, param.num_boxes, []));

	% get boxes for each image
	load([tmp_dir 'feat.mat']);
	box_sol = [];
	for i = 1:numel(box_sol_inds)
		box_sol = vertcat(box_sol, feat(i).boxes(box_sol_inds(i), 1:4));
	end

	% save solution
	savename = [tmp_dir 'qp_sol'];
	save(savename, 'x', 'box_sol', 'box_sol_inds', '-v7.3');
