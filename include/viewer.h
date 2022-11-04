#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "color.h"

struct Viewer {
 public:
  Viewer(std::string window_name = "Viewer") : window_name_(window_name) {}
  int Display(const std::vector<std::vector<RGB> > &colors);

 private:
  std::string window_name_;
  cv::Mat image_;

  void EmptyFrame_(int rows, int cols);
};
