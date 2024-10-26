#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char *argv[])
{
  cv::namedWindow("Hello Video", cv::WINDOW_AUTOSIZE);
  cv::VideoCapture cap;
  cap.open(std::string(argv[1]));

  cv::Mat frame;
  while (1) {
    cap >> frame;
    if (frame.empty())
      break; // Ran out of film
    cv::imshow("Hello Video", frame);
    if ((char)cv::waitKey(33) >= 0)
      break; // Stop if key pressed
  }

  return 0;
}
