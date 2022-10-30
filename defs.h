template<typename T>
struct Vec3;
// geometry.cpp

template <typename T>
const Vec3<T> operator * (const T lhs, const Vec3<T> &rhs);

double 			len(Vec3<double> A);
Vec3<double> 	normalize(Vec3<double> A);

template <typename T>
T dot(Vec3<T> A, Vec3<T> B);

template <typename T>
Vec3<T> cross(Vec3<T> A, Vec3<T> B);