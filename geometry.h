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

struct Object {
	double ambient_coef;
	double diffuse_coef;
	double specular_coef;
	double shininess;
};

struct Sphere: Object {
	Vec3<double> center;
	double r;
};

struct Light: Object {
	double intensity;
};