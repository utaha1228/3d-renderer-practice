#include <vector>

#include "color.h"
#include "const.h"
#include "geometry.h"
#include "objects.h"

using namespace std;

RGB ray_trace(Vec3<double> camera_pos, Vec3<double> camera_angle,
              vector<Object *> &objs, vector<Light> &lights);

vector<vector<RGB>> render(Vec3<double> camera_pos, Vec3<double> camera_angle,
                           double horizontal_view, double vertical_view,
                           int img_width, int img_height, vector<Object *> objs,
                           vector<Light> lights);
