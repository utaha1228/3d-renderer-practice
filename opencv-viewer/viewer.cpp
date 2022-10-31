#include "viewer.h"

#include <cassert>
#include <vector>

#include <opencv2/opencv.hpp>

void Viewer::EmptyFrame_(int rows, int cols) {
  image_ = cv::Mat::zeros(rows, cols, CV_64FC3);
}

int Viewer::Display(const std::vector<std::vector<RGB> > &colors) {
  assert(!colors.empty());

  int n = colors.size(), m = colors[0].size();
  EmptyFrame_(n, m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // Default channel is BGR in OpenCV.
      image_.at<cv::Vec3d>(i, j)[0] = colors[i][j].b;
      image_.at<cv::Vec3d>(i, j)[1] = colors[i][j].g;
      image_.at<cv::Vec3d>(i, j)[2] = colors[i][j].r;
    }
  }
  cv::imshow("Viewer", image_);

  return cv::waitKey(5);
}

void TestDisplay() {
  int n = 200, m = 100;
  std::vector<std::vector<RGB> > colors(n, std::vector<RGB>(m));

  Viewer viewer;

  for (int t = 0; t < 1000; t ++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        colors[i][j].r = colors[i][j].g = colors[i][j].b = 0;
        if (t <= 300) colors[i][j].r = 255.0;
        else if (t <= 600) colors[i][j].g = 255.0;
        else colors[i][j].b = 255.0;
      }
    }

    printf("%d\n", viewer.Display(colors));
  }
}

int main () {
  TestDisplay();
  return 0;
}
