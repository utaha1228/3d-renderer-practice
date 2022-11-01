#include "color.h"

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