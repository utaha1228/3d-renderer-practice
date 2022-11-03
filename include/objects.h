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

	virtual std::pair<Itsct_stat, Vec3<double>> first_intersection(Vec3<double>, Vec3<double>) const = 0;
	virtual Vec3<double> 						norm_vec(Vec3<double>) const = 0;
};

struct Sphere: Object {
	Vec3<double> center;
	double r;

	Sphere() {}

	std::pair<Itsct_stat, Vec3<double>> first_intersection(Vec3<double>, Vec3<double>) const;
	Vec3<double>						norm_vec(Vec3<double>) const;
};

struct Light {
	double intensity;
	Vec3<double> pos;
};

