#include <vector>
#include <math.h>
#include <cassert>
#include "defs.h"
#include "color.h"
#include "geometry.h"
using namespace std;

#define PI 3.14159265358979323

RGB ray_trace(Vec3<double> camera_pos, Vec3<double> camera_angle, vector<Object> &objs) {
	return RGB(0., 0., 0.);
}

/*
param:
camera_pos: the position of the view
camera_angle: the angle of the view
horizontal_view: how wide the view can see, in radius.
vertical_view: how high the view can see, in radius.
img_height, img_width: the dimension of the rendered image.
objs: the objects on the map, including the light source.

Return a 2D color array which represents the rendered image. Index i, j represents 
the pixel at row i (from bottom to top) and column j (from left to right).

*/
vector<vector<RGB>> render(Vec3<double> camera_pos, Vec3<double> camera_angle, 
	double horizontal_view, double vertical_view, int img_width, int img_height, 
	vector<Object> objs) {

	assert (horizontal_view <= PI);
	assert (vertical_view <= PI);

	vector<vector<RGB>> img;
	img.resize(img_height);
	for (int i = 0; i < img_height; i++) {
		img[i].resize(img_width);
	}

	camera_angle = normalize(camera_angle);

	const double _ = hypot(camera_angle.x, camera_angle.y);
	const Vec3<double> up = Vec3<double>(-camera_angle.z / _ * camera_angle.x, -camera_angle.z / _ * camera_angle.y , _);
	const Vec3<double> right = cross(camera_angle, up);
	const double width = 2 * tan(horizontal_view / 2);
	const double height = 2 * tan(vertical_view / 2);
	for (int i = 0; i < img_height; i++) {
		for (int j = 0; j < img_width; j++) {
			Vec3<double> angle = camera_angle
				+ (width * (2 * j + 1) / (2 * img_width) - width / 2) * right
				+ (height * (2 * i + 1) / (2 * img_height) - height / 2) * up;

			img[i][j] = ray_trace(camera_pos, angle, objs);
		}
	}
	return img;
}