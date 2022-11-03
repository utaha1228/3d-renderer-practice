#include "color.h"

#include <algorithm>

// Assignment

RGB & RGB::operator = (const RGB & rhs) {
	if (this == &rhs) {
		return *this;
	}
	this->r = rhs.r;
	this->g = rhs.g;
	this->b = rhs.b;
	return *this;
}

// Compound assignment operators

RGB & RGB::operator += (const RGB &rhs) {
	this->r += rhs.r;
	this->g += rhs.g;
	this->b += rhs.b;
	return *this;
}

RGB & RGB::operator -= (const RGB &rhs) {
	this->r -= rhs.r;
	this->g -= rhs.g;
	this->b -= rhs.b;
	return *this;
}

RGB & RGB::operator *= (const double rhs) {
	this->r *= rhs;
	this->g *= rhs;
	this->b *= rhs;
	return *this;
}
RGB & RGB::operator /= (const double rhs) {
	this->r /= rhs;
	this->g /= rhs;
	this->b /= rhs;
	return *this;
}

// Arithmetic operators

const RGB RGB::operator + (const RGB &rhs) const {
	return RGB(this->r + rhs.r, this->g + rhs.g, this->b + rhs.b);
}

const RGB RGB::operator - (const RGB &rhs) const {
	return RGB(this->r - rhs.r, this->g - rhs.g, this->b - rhs.b);
}

const RGB RGB::operator * (const double rhs) const {
	return RGB(this->r * rhs, this->g * rhs, this->b * rhs);
}

const RGB RGB::operator / (const double rhs) const {
	return RGB(this->r / rhs, this->g / rhs, this->b / rhs);
}

const RGB RGB::copy() const {
	RGB res = *this;
	return res;
}

RGB RGB::rescale() const {
	const double mx = std::max({this->r, this->g, this->b});
	if (mx > 255) {
		return RGB(this->r * 255 / mx, this->g * 255 / mx, this->b * 255 / mx);
	}
	else return this->copy();
}

void RGB::to_color(int &r, int &g, int &b) const {
	RGB scaled = this->rescale();
	r = (int) (scaled.r + 0.5);
	g = (int) (scaled.g + 0.5);
	b = (int) (scaled.b + 0.5);
}