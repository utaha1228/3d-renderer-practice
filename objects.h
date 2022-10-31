#pragma once

#include <utility>
#include "geometry.h"
#include "color.h"

enum Itsct_stat {
	INSIDE,
	NO_INTERSECTION,
	HAS_INTERSECTION,
};

struct Object {
	double ambient_coef;
	double diffuse_coef;
	double specular_coef;
	double shininess;
	RGB color;

	Object() {}

	std::pair<Itsct_stat, Vec3<double>> first_intersection(Vec3<double>, Vec3<double>);
};

struct Sphere: Object {
	Vec3<double> center;
	double r;

	std::pair<Itsct_stat, Vec3<double>> first_intersection(Vec3<double>, Vec3<double>);
};

struct Light {
	double intensity;
	Vec3<double> pos;
};

