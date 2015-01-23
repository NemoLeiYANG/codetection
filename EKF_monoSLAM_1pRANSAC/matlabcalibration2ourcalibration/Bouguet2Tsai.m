function Xsol=Bouguet2Tsai()
%
% JMM Montiel. 6 sep 2005

load matlab_calibration.mat
fc = fc_frontal;
kc = kc_frontal;
cc = cc_frontal;
alpha_c = alpha_c_frontal;

% % generate distorted table
% nCols = 320;
% nRows = 240;
% inc=round(min(nCols,nRows)/20)
% [u_grid,v_grid]=meshgrid(-150:inc:nCols+150,-150:inc:nRows+150);
% [nGrid,mGrid]=size(u_grid);
% undistorted=[reshape(u_grid,1, nGrid*mGrid); reshape(v_grid,1,nGrid*mGrid)];
% distorted = distort_bouguet(undistorted,kc,fc,cc)

addpath('TOOLBOX_calib/');

cam = initialize_cam;
Xini = [cam.k1; cam.k2; cam.f; cam.Cx; cam.Cy];

% Image size
nCols = 320;
nRows = 240;

% Step for the image grid
inc = round(min(nCols,nRows)/30); 
% Image grid
[u_grid,v_grid] = meshgrid(3*inc:inc:nCols-3*inc,3*inc:inc:nRows-3*inc);
[nGrid,mGrid] = size(u_grid);
uv_d = [reshape(u_grid,1, nGrid*mGrid); reshape(v_grid,1,nGrid*mGrid)];

xy_u = normalize(uv_d,fc,cc,kc,alpha_c);
x_distort = [(xy_u(1,:)*fc(1) + cc(1));(xy_u(2,:)*fc(2) + cc(2))];

% Non-linear minimization, minimizes the error in the image grid between the
% Bouguet's calibration model and the one we use in our code. Xsol should
% return the calibration parameters for our code in the following order:
% k1, k2, f, cx, cy. dx and dy are set here to 0.0112
Xsol = lsqnonlin('matlab2tsai_error',...
    Xini,[0;0;0;0;0],[3*cam.k1;3*cam.k2;3*cam.f;nCols;nRows],...
    optimset('LargeScale','on','Display','Iter','TolFun',1e-14),cam,uv_d,x_distort)