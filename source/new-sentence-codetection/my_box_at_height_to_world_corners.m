function [wc_rows,vflag] = my_box_at_height_to_world_corners(tl, br, height, cam_k, pose, cam_offset)
    [wc_rows,vflag] = box_at_height_to_world_corners(tl, br, height, cam_k, pose, cam_offset);
end
%my helper functions
function rotmat = rotation3dx(a) %roll
    rotmat = [1,0,0,0;...
              0,cos(a),-sin(a),0;...
              0,sin(a),cos(a),0;...
              0,0,0,1];
end

function rotmat = rotation3dy(a) %pitch
    rotmat = [cos(a),0,sin(a),0;...
              0,1,0,0;...
              -sin(a),0,cos(a),0;...
              0,0,0,1];
end

function rotmat = rotation3dz(a) %yaw
    rotmat = [cos(a),-sin(a),0,0;...
              sin(a),cos(a),0,0;...
              0,0,1,0;...
              0,0,0,1];
end

function transmat = translation3d(x,y,z)
    transmat = [1,0,0,x;...
                0,1,0,y;...
                0,0,1,z;...
                0,0,0,1];
end

function trans = make_transform_3d(theta,phi,psi,x,y,z)
    transmat = translation3d(x,y,z);
    zrot = rotation3dz(theta);
    yrot = rotation3dy(phi);
    xrot = rotation3dx(psi);
    trans = transmat * zrot * yrot *xrot;
end

function world_to_cam = robot_pose_to_world__camera_txf(pose, cam_offset)
    x = cam_offset(1); y = cam_offset(2); z = cam_offset(3);
    trans1 = translation3d(x,y,z);
    trans2 = make_transform_3d((pose(3) - (pi/2)),0,-pi/2,...
                               pose(1), pose(2), 0);
    world_to_cam = trans1/trans2;                               
end 

function h = point_to_homogeneous(p)
    h = horzcat(p,1);
end

function p = homogeneous_to_point(h)
    p = h(1:(length(h)-1));
end

function p = transform_point_3d(mat, point)
    h = point_to_homogeneous(point);
    temp = mat*h';
    p = homogeneous_to_point(temp);
end

function [point valid] = pixel_and_height_to_world(pix, height, cam_k, pose, cam_offset)
    world_to_cam = robot_pose_to_world__camera_txf(pose,cam_offset);
    cam_world = transform_point_3d(inv(world_to_cam),[0,0,0]);
    fx = cam_k(1,1); fy = cam_k(2,2);
    cx = cam_k(1,3); cy = cam_k(2,3);
    px = (pix(1)-cx)/fx;
    py = (pix(2)-cy)/fy;
    pixel_world = transform_point_3d(inv(world_to_cam),[px,py,1]);
    dxyz = pixel_world - cam_world;
    if (dxyz(3) > 0)
    %    point = [NaN, NaN];
        valid = false;
    else
        valid = true;
    end
        l = (height - cam_world(3))/dxyz(3);
        point = cam_world + dxyz*l;
    %end
end 

function [top_left_and_bottom_right_in_a_row,valid] = ...
    box_at_height_to_world_corners(tl, br, height, cam_k, pose, cam_offset)
%    top_left = zeros(1,3); %bottom_right = zeros(1,3);
    world_to_cam = robot_pose_to_world__camera_txf(pose,cam_offset);
    cam_world = transform_point_3d(inv(world_to_cam),[0,0,0])
    fx = cam_k(1,1); fy = cam_k(2,2);
    cx = cam_k(1,3); cy = cam_k(2,3);
    pblx = (tl(1) - cx)/fx;
    pbly = (br(2) - cy)/fy;
    pbrx = (br(1) - cx)/fx;
    pbry = pbly;
    ptly = (tl(2) - cy)/fy;
    bl_world = transform_point_3d(inv(world_to_cam),[pblx pbly 1]);
    br_world = transform_point_3d(inv(world_to_cam),[pbrx pbry 1]);
    tl_world = transform_point_3d(inv(world_to_cam),[pblx ptly 1]);
    dxyzbl = bl_world - cam_world
    dxyzbr = br_world - cam_world;
    dxyztl = tl_world - cam_world;
    if (dxyzbl(3) > 0)
        valid = false;
    else
        valid = true;
    end
    lbl = (height - cam_world(3))/dxyzbl(3);
    lbr = (height - cam_world(3))/dxyzbr(3);
    bottom_left = cam_world + lbl*dxyzbl
    bottom_right = cam_world + lbr*dxyzbr
    ltl = (bottom_left(1) - cam_world(1))/(tl_world(1) - cam_world(1));
    top_left = cam_world + ltl*dxyztl
    top_left_and_bottom_right_in_a_row = [top_left' bottom_right'];
end