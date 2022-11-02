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

#define WHITE RGB(255, 255, 255)
#define BLACK RGB(0, 0, 0)
#define RED RGB(255, 0, 0)
#define GREEN RGB(0, 255, 0)
#define BLUE RGB(0, 0, 255)
#define YELLOW RGB(255, 255, 0)
#define PURPLE RGB(127, 0, 255)