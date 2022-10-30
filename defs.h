template<typename T>
struct Vec3;

struct RGB;
// geometry.cpp

template <typename T>
T 				dot(Vec3<T> A, Vec3<T> B);

template <typename T>
Vec3<T> 		cross(Vec3<T> A, Vec3<T> B);

template <typename T>
const Vec3<T> 	operator * (const T lhs, const Vec3<T> &rhs);

double 			len(Vec3<double> A);
Vec3<double> 	normalize(Vec3<double> A);
double 			distance(Vec3<double> A, Vec3<double> B);

// render.cpp

RGB ray_trace(Vec3<double> camera_pos, Vec3<double> camera_angle, vector<Object> &objs);

vector<vector<RGB>> render(Vec3<double> camera_pos, Vec3<double> camera_angle, 
	double horizontal_view, double vertical_view, int img_width, int img_height, 
	vector<Object> objs);
