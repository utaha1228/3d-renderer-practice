#include "geometry.h"
#include "objects.h"
#include "color.h" 

int main() {
	const Vec3<double> vec = Vec3<double>(3, 2, 1);
	const Vec3<double> vec2 = Vec3<double>(3, 2, 1);
	RGB color(1, 2, 3);
	const double d = 1.0;
	const Vec3<double> res = vec + vec2;
	return 0;
}