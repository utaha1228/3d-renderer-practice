#include "color.h"


RGB operator + (RGB A, RGB B) {
	return RGB(A.r + B.r, A.g + B.g, A.b + B.b);
}

// scalar multiplication
RGB operator * (RGB A, double B) {
	return RGB(A.x * B, A.y * B, A.z * B);
}

RGB operator * (double B, RGB A) {
	return RGB(A.x * B, A.y * B, A.z * B);
}

RGB rescale(RGB A) {
	const double eps = 1e-6;
	const double MAX_VAL = 255;

	double mx = max(A.r, A.g, A.b);
	if (mx < MAX_VAL) return A;

	return RGB(A.r * MAX_VAL / mx, A.g * MAX_VAL / mx, A.b * MAX_VAL / mx);
}