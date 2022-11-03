#pragma once

#include "geometry.h"

Vec3<double> 	forward(Vec3<double> camera_angle);
Vec3<double> 	backward(Vec3<double> camera_angle);
Vec3<double> 	leftside(Vec3<double> camera_angle);
Vec3<double> 	rightside(Vec3<double> camera_angle);

void  update_camera_pos(Vec3<double> &camera_pos, const Vec3<double> &camera_angle, int key);
