#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;

void on_low_r_thresh_trackbar(int, void *);
void on_high_r_thresh_trackbar(int, void *);
void on_low_g_thresh_trackbar(int, void *);
void on_high_g_thresh_trackbar(int, void *);
void on_low_b_thresh_trackbar(int, void *);
void on_high_b_thresh_trackbar(int, void *);
int low_r=30, low_g=30, low_b=30;
int high_r=100, high_g=100, high_b=100;

int main()
{
    Mat frame, frame_threshold;
    frame = cv::imread("input/image.032808.jpg",CV_LOAD_IMAGE_COLOR);
    cv::GaussianBlur(frame, frame, cv::Size(5,5), 0, 0);
    cv::cvtColor(frame,frame,CV_RGB2HLS);
    namedWindow("Video Capture", WINDOW_NORMAL);
    namedWindow("Object Detection", WINDOW_NORMAL);
    
    //-- Trackbars to set thresholds for RGB values
    createTrackbar("Low R","Object Detection", &low_r, 255, on_low_r_thresh_trackbar);
    createTrackbar("High R","Object Detection", &high_r, 255, on_high_r_thresh_trackbar);
    createTrackbar("Low G","Object Detection", &low_g, 255, on_low_g_thresh_trackbar);
    createTrackbar("High G","Object Detection", &high_g, 255, on_high_g_thresh_trackbar);
    createTrackbar("Low B","Object Detection", &low_b, 255, on_low_b_thresh_trackbar);
    createTrackbar("High B","Object Detection", &high_b, 255, on_high_b_thresh_trackbar);
    while((char)waitKey(1)!='q'){
        //cap>>frame;
        //if(frame.empty())
            //break;
        //-- Detect the object based on RGB Range Values
        inRange(frame,Scalar(low_b,low_g,low_r), Scalar(high_b,high_g,high_r),frame_threshold);
        //-- Show the frames
        imshow("Video Capture",frame);
        imshow("Object Detection",frame_threshold);
        //waitKey(0);
    }
    return 0;
}
void on_low_r_thresh_trackbar(int, void *)
{
    low_r = min(high_r-1, low_r);
    setTrackbarPos("Low R","Object Detection", low_r);
}
void on_high_r_thresh_trackbar(int, void *)
{
    high_r = max(high_r, low_r+1);
    setTrackbarPos("High R", "Object Detection", high_r);
}
void on_low_g_thresh_trackbar(int, void *)
{
    low_g = min(high_g-1, low_g);
    setTrackbarPos("Low G","Object Detection", low_g);
}
void on_high_g_thresh_trackbar(int, void *)
{
    high_g = max(high_g, low_g+1);
    setTrackbarPos("High G", "Object Detection", high_g);
}
void on_low_b_thresh_trackbar(int, void *)
{
    low_b= min(high_b-1, low_b);
    setTrackbarPos("Low B","Object Detection", low_b);
}
void on_high_b_thresh_trackbar(int, void *)
{
    high_b = max(high_b, low_b+1);
    setTrackbarPos("High B", "Object Detection", high_b);
}

/*#include "opencv2/opencv.hpp"
#include "string.h"
using namespace cv;
using namespace std;

int main(int, char**)
{
    VideoCapture cap("project_video.mp4"); // open the default camera
    if (!cap.isOpened())  // check if we succeeded
        return -1;

    //Ptr<BackgroundSubtractor> pMOG = new BackgroundSubtractorMOG2();

    //Mat fg_mask;
    Mat frame;
    int count = -1;

    for (;;)
    {
        // Get frame
        cap >> frame; // get a new frame from camera

        // Update counter
        ++count;

        // Background subtraction
        //pMOG->operator()(frame, fg_mask);

        imshow("frame", frame);
        //imshow("fg_mask", fg_mask);

        // Save foreground mask
        string name = "img" + std::to_string(count) + ".png";
        imwrite(name, frame);

        if (waitKey(1) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}*/
