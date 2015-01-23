function cam = my_initialize_cam()

d =     0.0112; %fixed
nRows = 480;%240;
nCols = 640;%320;
Cx =    306.640097058508;%1.7945 / d;
Cy =    202.216680664229;%1.4433 / d;
k1=     0.00619003102898949;%6.333e-2;
k2=     1.13550655408291e-05;%1.390e-2;
f =     2.1735;% SAME 2.1735;

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

cam.K =     sparse( [ f/d   0     Cx;
                0  f/d    Cy;
                0    0     1] );
