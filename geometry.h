#include <utility>
using namespace std;

template <typename T>
struct Vec3 {
	T x;
	T y;
	T z;
	Vec3() {}
	Vec3(T x, T y, T z): x(x), y(y), z(z) {}

	// Assignment

	Vec3<T> & operator = (const Vec3<T> & rhs);

	// Compound assignment operators

	Vec3<T> & operator += (const Vec3<T> &rhs);
	Vec3<T> & operator -= (const Vec3<T> &rhs);
	Vec3<T> & operator *= (const T rhs);
	Vec3<T> & operator /= (const T rhs);

	// Arithmetic operators

	const Vec3<T> operator + (const Vec3<T> &rhs) const;
	const Vec3<T> operator - (const Vec3<T> &rhs) const;
	const Vec3<T> operator * (const T rhs) const;
	const Vec3<T> operator / (const T rhs) const;

};

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

	pair<Itsct_stat, Vec3<double>> first_intersection(Vec3<double>, Vec3<double>);
};

struct Sphere: Object {
	Vec3<double> center;
	double r;

	pair<Itsct_stat, Vec3<double>> first_intersection(Vec3<double>, Vec3<double>);
};

struct Light: Object {
	double intensity;

	pair<Itsct_stat, Vec3<double>> first_intersection(Vec3<double>, Vec3<double>);
};