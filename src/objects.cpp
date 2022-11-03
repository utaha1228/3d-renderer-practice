#include <utility>
#include <math.h>
#include "objects.h"

#define eps 1e-7

std::pair<Itsct_stat, Vec3<double>> Sphere::first_intersection(Vec3<double> pos, Vec3<double> angle) const {
	// center the ball at (0, 0, 0), need to change the coordinate back later
	pos = pos - this->center;

	if (dot(pos, pos) <= r * r + eps) { // pos inside the ball
		return std::make_pair(Itsct_stat::INSIDE, Vec3<double>());
	}

	// ||pos + x * angle|| = r, x > 0
	// transform to Ax^2 + Bx + C = 0
	const double A = dot(angle, angle);
	const double B = 2 * dot(angle, pos);
	const double C = dot(pos, pos) - r * r;
	// A > 0 for sure
	const double D = B * B - 4 * A * C;
	if (D < eps) { // no intersection
		return std::make_pair(Itsct_stat::NO_INTERSECTION, Vec3<double>());
	}
	const double small_root = (-B - sqrt(D)) / (A + A);
	if (small_root < eps) {
		const double big_root = -B / A - small_root;
		if (big_root < eps) {
			return std::make_pair(Itsct_stat::NO_INTERSECTION, Vec3<double>());
		}
		return std::make_pair(Itsct_stat::HAS_INTERSECTION, this->center + pos + angle * big_root);
	}
	else {
		return std::make_pair(Itsct_stat::HAS_INTERSECTION, this->center + pos + angle * small_root);
	}
}

Vec3<double> Sphere::norm_vec(Vec3<double> point) const {
	return normalize(point - this->center);
}
