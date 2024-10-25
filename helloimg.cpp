#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
  cv::Mat img = cv::imread(argv[1], -1); // -1 means read the image "as is"
  if (img.empty())
    return -1;
  cv::namedWindow("helloImg", cv::WINDOW_AUTOSIZE);
  cv::imshow("helloImg", img);
  cv::waitKey(0);
  cv::destroyWindow("helloImg");

  return 0;
}
