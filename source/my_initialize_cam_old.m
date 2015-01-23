function cam = my_initialize_cam()

d =     0.0112; %according to authors' own conversion code, this is fixed
nRows = 480;%240;
nCols = 640;%320;
Cx =    3.1889431359075871e+02;%1.7945 / d;
Cy =    1.8497490921833668e+02;%1.4433 / d;
k1=     -3.0726364131082201e-01;%6.333e-2;
k2=     -3.9596701669508116e-01;%1.390e-2;
fx =    7.2719606008661424e+02;
fy =    7.2421735121644656e+02;
f =     (fx + fy)*d;%2.1735;



cam.k1 =    k1;
cam.k2 =    k2;
cam.nRows = nRows;
cam.nCols = nCols;
cam.Cx =    Cx;
cam.Cy =    Cy;
cam.f =     f;
cam.dx =    d;
cam.dy =    d;
cam.model = 'two_distortion_parameters';

cam.K =     sparse( [ fx   0    Cx;
                       0  fy    Cy;
                       0   0     1] );