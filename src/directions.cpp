#include "geometry.h"
#include "directions.h"

Vec3<double> forward(Vec3<double> camera_angle) {
	return normalize(Vec3<double>(camera_angle.x, camera_angle.y, 0));
}

Vec3<double> backward(Vec3<double> camera_angle) {
	return normalize(Vec3<double>(-camera_angle.x, -camera_angle.y, 0));
}

Vec3<double> leftside(Vec3<double> camera_angle) {
	return normalize(Vec3<double>(-camera_angle.y, camera_angle.x, 0));
}

Vec3<double> rightside(Vec3<double> camera_angle) {
	return normalize(Vec3<double>(camera_angle.y, -camera_angle.x, 0));
}

