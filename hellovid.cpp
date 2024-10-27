#include <fstream>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp>

// g_run controls the number of frames to play
// when g_run = 0, the video is paused,
// when g_run = positive integer k, video plays k frames then pause
// when g_run is negative, video plays continuously until the end
int g_slider_pos = 0;
int g_run = 1, g_dontset = 0; // start out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *)
{
  g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
  if (!g_dontset)
    g_run = 1;
  g_dontset = 0;
}

int main(int argc, char *argv[])
{

  cv::namedWindow("Hello Video", cv::WINDOW_AUTOSIZE);
  g_cap.open(std::string(argv[1]));
  int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
  int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
  int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);

  std::cout << "Video has " << frames << " frames of dimensions(" << tmpw
            << ", " << tmph << ")." << std::endl;

  cv::createTrackbar("Position", "Hello Video", &g_slider_pos, frames,
                     onTrackbarSlide);
  cv::Mat frame;

  while (1) {
    if (g_run != 0) {
      g_cap >> frame;
      if (frame.empty())
        break; // Ran out of film
      int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
      g_dontset = 1;

      cv::setTrackbarPos("Position", "Hello Video", current_pos);
      cv::imshow("Hello Video", frame);
      g_run -= 1;
    }
    char c = (char)cv::waitKey(10);
    if (c == 's') // single step
    {
      g_run = 1;
      std::cout << "Single step, run = " << g_run << std::endl;
    }
    if (c == 'r') // run mode
    {
      g_run = -1;
      std::cout << "Run mode, run = " << g_run << std::endl;
    }
    if (c == 27) // Escape key stops the video
      break;
  }
  cv::destroyWindow("Hello Video");

  return 0;
}
