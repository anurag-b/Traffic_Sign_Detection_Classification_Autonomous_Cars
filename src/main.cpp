#include <iostream>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/ml/ml.hpp"
#include "traffic_sign.h"

int main(){
	//Create lane_detect object for the class
	TrafficSign obj;
	//Declare the Hog descriptor constructor to store the parameters
	cv::HOGDescriptor hog(cv::Size(64, 64),
			cv::Size(16, 16),
			cv::Size(8, 8),
			cv::Size(8, 8),
			16, 1, -1, 0, 0.2,
			1, 64, 1);

	//SVM declaration
	std::vector<cv::Mat> train_imgs;
	std::vector<int> train_labels;
	cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
	int trained = obj.startTrainingStage(hog,svm,train_imgs,train_labels);


	cv::Mat img = cv::imread("../input/image.033527.jpg",CV_LOAD_IMAGE_COLOR);//033527//032721//033542//033429
	cv::Mat processed_img = obj.preprocess(img);
	cv::Mat roi_img = obj.regionOfInterest(processed_img);
	std::vector<cv::Mat> detected_regions = obj.interestRegionDetection(roi_img, img);
	if(!detected_regions.empty()){
		cv::Mat hog_feature_vector = obj.getHogFeatures(hog, detected_regions);
		float detected_sign = obj.SVMTesting(svm, hog_feature_vector);
		std::cout<<detected_sign<<std::endl;
		detected_regions.clear();
	}
	cv::imshow("Input image",img);
	cv::waitKey(0);
	/*cv::VideoCapture cap("project_video.mp4");
	//cv::VideoCapture cap("challenge_video.mp4");
	if(!cap.isOpened()){
		std::cout<<"Error opening video stream"<<std::endl;
		return -1;
	}
	while(1){
		cv::Mat frame;
		cap>>frame;
		if(frame.empty())
			continue;
		char c = (char)cv::waitKey(25);
		if(c==27)
			break;
	}
	cap.release();
	cv::destroyAllWindows();*/
	return 0;
}