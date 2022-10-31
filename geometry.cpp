#include <math.h>
#include "geometry.h"

#define eps 1e-7

double len(const Vec3<double> A) {
	return hypot(A.x, hypot(A.y, A.z));
}

Vec3<double> normalize(const Vec3<double> A) {
	return A / len(A);
}

double distance(Vec3<double> A, Vec3<double> B) {
	return dot(A - B, A - B);
}