#include "render.h"

#include <vector>
#include <math.h>
#include <cassert>
#include <algorithm>

/* 
TODO(utaha): 
1. implement lighting
2. implement specular lighting?
3. introduce shadow
4. implement reflection/refraction
*/

RGB ray_trace(Vec3<double> camera_pos, Vec3<double> camera_angle, std::vector<Object *> &objs, std::vector<Light> &lights) {
	Vec3<double> intersection;
	Object *closest = NULL;
	for (Object *obj: objs) {
		auto res = obj->first_intersection(camera_pos, camera_angle);
		const Itsct_stat stat = res.first;
		const Vec3<double> point = res.second;

		assert (stat != Itsct_stat::INSIDE);

		if (stat == Itsct_stat::NO_INTERSECTION) continue;

		if (closest == NULL || distance(camera_pos, point) < distance(camera_pos, intersection)) {
			closest = obj;
			intersection = point;
		}
	}
	if (closest == NULL) {
		// background
		return RGB(255, 255, 255);
	}
	else {
		double total_intensity = 0;
		for (Light light: lights) {
			const Vec3<double> light_dir = normalize(light.pos - intersection);
			const Vec3<double> norm_vec = closest->norm_vec(intersection);
			total_intensity += std::max(0., dot(light_dir, norm_vec)) * light.intensity;
		}
		return (closest->color * total_intensity).rescale();
	}
}

/*
param:
camera_pos: the position of the view.
camera_angle: the angle of the view.
horizontal_view: how wide the view can see, in radius.
vertical_view: how high the view can see, in radius.
img_height, img_width: the dimension of the rendered image.
objs: the objects on the map.
lights: all the light sources.

Return a 2D color array which represents the rendered image. Index i, j represents 
the pixel at row i (from top to bottom) and column j (from left to right).
*/

vector<vector<RGB>> render(Vec3<double> camera_pos, Vec3<double> camera_angle, 
	double horizontal_view, double vertical_view, int img_width, int img_height, 
	std::vector<Object *> objs, std::vector<Light> lights) {

	assert (horizontal_view <= PI);
	assert (vertical_view <= PI);

	std::vector<vector<RGB>> img;
	img.resize(img_height);
	for (int i = 0; i < img_height; i++) {
		img[i].resize(img_width);
	}

	camera_angle = normalize(camera_angle);

	const double _ = hypot(camera_angle.x, camera_angle.y);
	const Vec3<double> down = Vec3<double>(camera_angle.z / _ * camera_angle.x, camera_angle.z / _ * camera_angle.y , -_);
	const Vec3<double> right = cross(down, camera_angle);
	const double width = 2 * tan(horizontal_view / 2);
	const double height = 2 * tan(vertical_view / 2);
	for (int i = 0; i < img_height; i++) {
		for (int j = 0; j < img_width; j++) {
			Vec3<double> angle = camera_angle
				+ (width * (2 * j + 1) / (2 * img_width) - width / 2) * right
				+ (height * (2 * i + 1) / (2 * img_height) - height / 2) * down;

			img[i][j] = ray_trace(camera_pos, angle, objs, lights);
		}
	}
	return img;
}