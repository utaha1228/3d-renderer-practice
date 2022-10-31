#include "../color.h"

#include <vector>

#include <opencv2/opencv.hpp>

struct Viewer {
public:

  Viewer() {}
  int Display(const std::vector<std::vector<RGB> > &colors);

private:
  cv::Mat image_;

  void EmptyFrame_(int rows, int cols);
};
