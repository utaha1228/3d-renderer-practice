#include "geometry.h"

template <typename T>
Vec3<T> operator + (Vec3<T> A, Vec3<T> B) {
	return Vec3<T>(A.x + B.x, A.y + B.y, A.z + B.z);
}

// scalar multiplication
template <typename T>
Vec3<T> operator * (Vec3<T> A, T B) {
	return Vec3<T>(A.x * B, A.y * B, A.z * B);
}

template <typename T>
Vec3<T> operator * (T B, Vec3<T> A) {
	return Vec3<T>(A.x * B, A.y * B, A.z * B);
}

template <typename T>
T dot(Vec3<T> A, Vec3<T> B) {
	return A.x * B.x + A.y * B.y + A.z * B.z;
}

template <typename T>
T cross(Vec3<T> A, Vec3<T> B) {
	return Vec3<T>(
		A.y * B.z - A.z * B.y,
		A.z * B.x - A.x * B.z,
		A.x * B.y - A.y * B.x
	);
}