#include <math.h>
#include <utility>
#include "geometry.h"
using namespace std;
// Assignment

#define eps 1e-7

template <typename T>
Vec3<T> & Vec3<T>::operator = (const Vec3<T> & rhs) {
	if (this == &rhs) { // avoid self assignment
		return *this;
	}
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	return *this;
}

// Compound assignment operators

template <typename T>
Vec3<T> & Vec3<T>::operator += (const Vec3<T> &rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z; 
	return *this;
}

template <typename T>
Vec3<T> & Vec3<T>::operator -= (const Vec3<T> &rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z; 
	return *this;
}

template <typename T>
Vec3<T> & Vec3<T>::operator *= (const T rhs) {
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs; 
	return *this;
}

template <typename T>
Vec3<T> & Vec3<T>::operator /= (const T rhs) {
	this->x /= rhs;
	this->y /= rhs;
	this->z /= rhs; 
	return *this;
}

// Arithmetic operators

template <typename T>
const Vec3<T> Vec3<T>::operator + (const Vec3<T> &rhs) const {
	return Vec3<T>(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

template <typename T>
const Vec3<T> Vec3<T>::operator - (const Vec3<T> &rhs) const {
	return Vec3<T>(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

template <typename T>
const Vec3<T> Vec3<T>::operator * (const T rhs) const {
	return Vec3<T>(this->x * rhs, this->y * rhs, this->z * rhs);
}

template <typename T>
const Vec3<T> operator * (const T lhs, const Vec3<T> &rhs) {
	return Vec3<T>(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}

template <typename T>
const Vec3<T> Vec3<T>::operator / (const T rhs) const {
	return Vec3<T>(this->x / rhs, this->y / rhs, this->z / rhs);
}

// Other operations

template <typename T>
T dot(const Vec3<T> A, const Vec3<T> B) {
	return A.x * B.x + A.y * B.y + A.z * B.z;
}

template <typename T>
Vec3<T> cross(const Vec3<T> A, const Vec3<T> B) {
	return Vec3<T>(
		A.y * B.z - A.z * B.y,
		A.z * B.x - A.x * B.z,
		A.x * B.y - A.y * B.x
	);
}

double len(const Vec3<double> A) {
	return hypot(A.x, hypot(A.y, A.z));
}

Vec3<double> normalize(const Vec3<double> A) {
	return A / len(A);
}

double distance(Vec3<double> A, Vec3<double> B) {
	return dot(A - B, A - B);
}

pair<Itsct_stat, Vec3<double>> Sphere::first_intersection(Vec3<double> pos, Vec3<double> angle) {
	// center the ball at (0, 0, 0)
	pos = pos - this->center;

	if (dot(pos, pos) <= r * r + eps) { // pos inside the ball
		return make_pair(Itsct_stat::INSIDE, Vec3<double>());
	}

	// ||pos + x * angle|| = r, x > 0
	// transform to Ax^2 + Bx + C = 0
	const double A = dot(angle, angle);
	const double B = 2 * dot(angle, pos);
	const double C = dot(pos, pos) - r * r;
	// A > 0 for sure
	const double D = B * B - 4 * A * C;
	if (D < eps) { // no intersection
		return make_pair(Itsct_stat::NO_INTERSECTION, Vec3<double>());
	}
	const double small_root = (-B - sqrt(D)) / (A + A);
	if (small_root < eps) {
		const double big_root = -B / A - small_root;
		if (big_root < eps) {
			return make_pair(Itsct_stat::NO_INTERSECTION, Vec3<double>());
		}
		return make_pair(Itsct_stat::HAS_INTERSECTION, pos + angle * big_root);
	}
	else {
		return make_pair(Itsct_stat::HAS_INTERSECTION, pos + angle * small_root);
	}
}

pair<Itsct_stat, Vec3<double>> Light::first_intersection(Vec3<double> pos, Vec3<double> angle) {
	return make_pair(Itsct_stat::NO_INTERSECTION, Vec3<double>());
}