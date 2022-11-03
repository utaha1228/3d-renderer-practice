#include <math.h>
#include "geometry.h"

double len(Vec3<double> A) {
	return hypot(A.x, hypot(A.y, A.z));
}

Vec3<double> normalize(Vec3<double> A) {
	return A / len(A);
}

double distance(Vec3<double> A, Vec3<double> B) {
	return len(A - B);
}