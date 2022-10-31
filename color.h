#pragma once

struct RGB {
	double r;
	double g;
	double b;

	RGB() {}
	RGB(double r, double g, double b): r(r), g(g), b(b) {}

	// Assignment

	RGB & operator = (const RGB & rhs);

	// Compound assignment operators

	RGB & operator += (const RGB &rhs);
	RGB & operator -= (const RGB &rhs);
	RGB & operator *= (const double rhs);
	RGB & operator /= (const double rhs);

	// Arithmetic operators

	const RGB operator + (const RGB &rhs) const;
	const RGB operator - (const RGB &rhs) const;
	const RGB operator * (const double rhs) const;
	const RGB operator / (const double rhs) const;

	const RGB copy() const;
};