#include "render.h"
#include "geometry.h"
#include "color.h"
#include "objects.h"
#include "viewer.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include <opencv2/opencv.hpp>

using namespace std;

void save_image(string filename, vector<vector<RGB>> img) {
	const uint height = img.size();
	const uint width = img[0].size();
	ofstream ofs;
    ofs.open(filename);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (int i = height - 1; i >= 0; i--) { // form top to bottom
    	for (int j = 0; j < width; j++) {
            ofs << (char) img[i][j].r << (char) img[i][j].g << (char) img[i][j].b;
    	}
    }
    ofs.close();
}

void test_render() {
	vector<Light> lights;
	vector<Object*> objs;
	objs.push_back(new Sphere());
	((Sphere *)objs[0])->center = Vec3<double>(10, 1, -1);
	((Sphere *)objs[0])->r = 3;
	((Sphere *)objs[0])->color = PURPLE;

	objs.push_back(new Sphere());
	((Sphere *)objs[1])->center = Vec3<double>(17, -1, 1);
	((Sphere *)objs[1])->r = 4;
	((Sphere *)objs[1])->color = GREEN;

	Vec3<double> camera_pos(0, 0, 0), camera_angle(1, 0, 0);
	double horizontal_view = PI * 2 / 3, vertical_view = horizontal_view = PI * 2 / 3;
	int img_width = 500, img_height = 500;

	auto res = render(camera_pos, camera_angle, horizontal_view, vertical_view, img_width, img_height, objs, lights);
	save_image("./tmp.ppm", res);

  Viewer viewer("Render");
  while (true) {
    int key = viewer.Display(res);
    if (key != -1) {
      printf("Key = %d.\n", key);
    }
  }
}

int main() {
	test_render();
	return 0;
}
