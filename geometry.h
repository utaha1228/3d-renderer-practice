#pragma once

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
#include "geometry.tpp"

double 			len(const Vec3<double>);
Vec3<double> 	normalize(const Vec3<double>);
double 			distance(Vec3<double>, Vec3<double>);