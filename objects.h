#include "geometry.h"

class Object {
	double ambient_coef;
	double diffuse_coef;
	double specular_coef;
	double shininess;
};

class Sphere: Object {
	Vec3<double> center;
	double r;
};

class Light: Object {
	double intensity;
}