#include <cstring>
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

#include "color.h"
#include "directions.h"
#include "geometry.h"
#include "objects.h"
#include "render.h"
#include "viewer.h"

using namespace std;

void save_image(string filename, vector<vector<RGB>> img) {
  const uint height = img.size();
  const uint width = img[0].size();
  ofstream ofs;
  ofs.open(filename);
  ofs << "P6\n" << width << " " << height << "\n255\n";
  for (int i = 0; i < height; i++) {  // form top to bottom
    for (int j = 0; j < width; j++) {
      int r, g, b;
      img[i][j].to_color(r, g, b);
      ofs << (char)r << (char)g << (char)b;
    }
  }
  ofs.close();
}

void test_render() {
  vector<Light> lights;
  Light only_light = Light();
  only_light.pos = Vec3<double>(-100, 100, 0);
  only_light.intensity = 1;
  lights.push_back(only_light);

  vector<Object *> objs;
  objs.push_back(new Sphere());
  ((Sphere *)objs[0])->center = Vec3<double>(10, 1, -1);
  ((Sphere *)objs[0])->r = 3;
  ((Sphere *)objs[0])->color = PURPLE;

  objs.push_back(new Sphere());
  ((Sphere *)objs[1])->center = Vec3<double>(17, -1, 1);
  ((Sphere *)objs[1])->r = 4;
  ((Sphere *)objs[1])->color = GREEN;

  Vec3<double> camera_pos(0, 4, 0), camera_angle(1, 0, 0);
  double horizontal_view = PI * 2 / 3,
         vertical_view = horizontal_view = PI * 2 / 3;
  int img_width = 500, img_height = 500;

  auto res = render(camera_pos, camera_angle, horizontal_view, vertical_view,
                    img_width, img_height, objs, lights);
  save_image("./tmp.ppm", res);

  Viewer viewer("Render");
  while (true) {
    int key = viewer.Display(res);
    if (key != -1) {
      update_camera_pos(camera_pos, camera_angle, key);
      printf("Key = %d.\n", key);
    }
    res = render(camera_pos, camera_angle, horizontal_view, vertical_view,
                 img_width, img_height, objs, lights);
  }
}

int main() {
  test_render();
  return 0;
}
