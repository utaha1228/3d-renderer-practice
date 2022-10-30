#include <math.h>
#include "geometry.h"

// Assignment

template <typename T>
Vec3<T> & Vec3<T>::operator = (const Vec3<T> & rhs) {
	if (this == &rhs) { // avoid self assignment
		return *this;
	}
	this->x = rhs->x;
	this->y = rhs->y;
	this->z = rhs->z;
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