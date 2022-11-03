#include "color.h"
#include "const.h"
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

void  update_camera_pos(Vec3<double> &camera_pos, const Vec3<double> &camera_angle, int key) {
  Vec3<double> dir_vec(0, 0, 0);
  if (key == 'w' || key == 0) dir_vec = forward(camera_angle);
  if (key == 's' || key == 1) dir_vec = backward(camera_angle);
  if (key == 'a' || key == 2) dir_vec = leftside(camera_angle);
  if (key == 'd' || key == 3) dir_vec = rightside(camera_angle);
  camera_pos = camera_pos + dir_vec * MOVE_FACTOR;
}
