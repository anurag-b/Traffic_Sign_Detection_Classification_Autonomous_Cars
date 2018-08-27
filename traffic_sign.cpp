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

void TrafficSign::loadTrainingData(std::vector<cv::Mat> &train_imgs, std::vector<int> &train_labels){
	cv::String folder;
	cv::Size size(64, 64);
	for(int i = 0; i < 62; i++){
		if(i < 10)
			folder = "0000" + std::to_string(i);
		else
			folder = "000" + std::to_string(i);
		std::cout<<"Loading data for class"<<folder<<std::endl;
		cv::String pathname = "Training/" + folder; //Replace this with your local address
		std::vector<cv::String> filenames;
		glob(pathname, filenames);

		for (cv::String j : filenames) {
			cv::Mat src = imread(j);
			if(!src.empty()){
				cv::resize(src, src, size);
				train_imgs.push_back(src);
				train_labels.push_back(i);
			}
		}
	}
}

void TrafficSign::SVMTraining(cv::Ptr<cv::ml::SVM> &svm, cv::Mat train_HOG, std::vector<int> train_labels){
	//Set parameters of the SVM
	svm->setGamma(0.01);
	svm->setC(1);
	svm->setKernel(cv::ml::SVM::RBF);//RBF
	svm->setType(cv::ml::SVM::C_SVC);

	//Train SVM with all the labeled data
	cv::Ptr<cv::ml::TrainData> train_data = cv::ml::TrainData::create(train_HOG, cv::ml::ROW_SAMPLE, train_labels);
	svm->train(train_data);
}

int TrafficSign::startTrainingStage(cv::HOGDescriptor &hog, cv::Ptr<cv::ml::SVM> &svm, std::vector<cv::Mat> &train_imgs, std::vector<int> &train_labels){
	std::cout<<"SVM Training stage started"<<std::endl;
	//Load training data and resize
	loadTrainingData(train_imgs, train_labels);

	//HOG features of training images
	cv::Mat train_HOG = getHogFeatures(hog, train_imgs);

	//Train SVM and save model
	SVMTraining(svm, train_HOG, train_labels);
	std::cout<<"Training Completed"<<std::endl;

	//Return 1 as success
	return 1;
}

cv::Mat TrafficSign::color_hsl(cv::Mat src){
	cv::Mat output;
	cv::cvtColor(src,output,CV_RGB2HLS);
	return output;
}

cv::Mat TrafficSign::preprocess(cv::Mat img){
	cv::Mat denoised;
	//remove the noise using the gaussian 5x5 filter kernel
	cv::GaussianBlur(img, denoised, cv::Size(5,5), 0, 0);
	//convert the image to hsl channel
	cv::Mat img_hsl = color_hsl(denoised);
	
	////Thresholding Method////
	//Detect the red signs
	//cv::inRange(img_hsl, cv::Scalar(103,35,0), cv::Scalar(138,120,135), red_sign);

	//Detect the blue signs
	//cv::inRange(img_hsl, cv::Scalar(0,50,45), cv::Scalar(42,146,214), blue_sign);	

	//Or the white and yellow lanes
	//cv::bitwise_or(red_sign,blue_sign,red_blue);
	//cv::imshow("red blue",red_blue);
	//cv::waitKey(0);


	////Normalization part////
	//split multi-channel image into single channel
	cv::Mat split_img[denoised.channels()];//destination
	cv::Mat norm_img[denoised.channels()];
	cv::split(denoised,split_img);

	//Normalise/Contrast streching over each channel
	cv::normalize(split_img[0], norm_img[0], 0, 255, CV_MINMAX );
	cv::normalize(split_img[1], norm_img[1], 0, 255, CV_MINMAX );
	cv::normalize(split_img[2], norm_img[2], 0, 255, CV_MINMAX );

	//RGB Nomalization/Enhancing Method 1
	/*cv::Mat red_norm = 255*(norm_img[2]/(norm_img[0]+norm_img[1]+norm_img[2]));
	cv::imshow("red norm",red_norm);
	cv::waitKey(0);
	cv::Mat blue_norm = 255*(norm_img[0]/(norm_img[0]+norm_img[1]+norm_img[2]));
	cv::imshow("blue norm",blue_norm);
	cv::waitKey(0);*/


	//RGB Normalization/Enhancing Method 2
	//For red channel and red signs
	cv::Mat red_enhance, blue_enhance, total_enhance, temp1, temp2, temp3;
	cv::subtract(norm_img[2],norm_img[0], temp1);
	cv::subtract(norm_img[2],norm_img[1], temp2);
	cv::min(temp1,temp2,temp3);

	cv::Mat normImg = 255*(temp3/(norm_img[0]+norm_img[1]+norm_img[2]));
	cv::max(0,normImg,red_enhance);

	//For blue channel and blue signs
	cv::subtract(norm_img[0],norm_img[2],temp1); //reusing the temp1 variable
	normImg = 255*(temp1/(norm_img[0]+norm_img[1]+norm_img[2])); 
	cv::max(0,normImg,blue_enhance);	

	//cv::Mat rb_binary;
	cv::max(red_enhance, blue_enhance, total_enhance);
	//cv::normalize(total_enhance,total_enhance,0,255,CV_MINMAX);
	//cv::threshold(total_enhance, total_enhance, 50, 255, cv::THRESH_BINARY);
	//cv::imshow("red channel",total_enhance);
	//cv::waitKey(0);
	return total_enhance;
}

cv::Mat TrafficSign::regionOfInterest(cv::Mat src){
	cv::Mat output;
  	cv::Mat mask = cv::Mat::zeros(src.size(), src.type());
  	//std::cout<<src.size()<<std::endl;
  	//cv::Point pts[4] = { cv::Point(0, 0),
    // 					 cv::Point(0, src.rows*(2/3)),
    // 					 cv::Point(src.cols, src.rows*(2/3)),
    // 					 cv::Point(src.cols, 0)
  	//					};
  	// Create a binary polygon mask
  	//cv::fillConvexPoly(mask, pts, 4, cv::Scalar(255, 255, 255));
  	cv::rectangle(mask,cv::Point(0, 0), cv::Point(src.cols,0.5*src.rows),cv::Scalar(255,255,255),-1,8);
  	// Multiply the edges image and the mask to get the output
  	cv::bitwise_and(src, mask, output);
  	//std::string name = "test/roi.png";
  	//cv::imwrite(name, output);
  	//cv::imshow("ROI image",output);
  	//cv::waitKey(0);
  	return output;
}

std::vector<cv::Mat> TrafficSign::interestRegionDetection(cv::Mat img, cv::Mat og){
	std::vector<std::vector<cv::Point>> regions;
	std::vector<cv::Rect> mser_bboxes;
	std::vector<cv::Rect> final_boxes;
	std::vector<cv::Mat> mserImgs;
	cv::Mat detection;
	cv::Size size(64, 64);
	cv::Ptr<cv::MSER> ms = cv::MSER::create(10, 250, 27300, 0.5,0.2, 200, 1.01, 0.1, 1);
	ms->detectRegions(img, regions, mser_bboxes);
	// For every bounding box in the image
	for (cv::Rect i : mser_bboxes) {
		// Ratio filter of detected regions
		double ratio = (static_cast<double>(i.height) /
				static_cast<double>(i.width));

		if (ratio > 0.8 && ratio < 1.4) {
			// Crop bounding boxes to get new images
			detection = img(i);
			double area = static_cast<double>(i.height) * static_cast<double>(i.width);

			// Resize images  to fit the trained data
			cv::resize(detection, detection, size);

			// Output the vector of images
			mserImgs.push_back(detection);
			final_boxes.push_back(i);
		}
	}	
	for( int i = 0; i<final_boxes.size(); i++ ){
         cv::rectangle(og, final_boxes[i], CV_RGB(0, 255, 0)); 
    }
    cv::imshow("mser", og);
    cv::waitKey(0);
    return mserImgs;
}

cv::Mat TrafficSign::getHogFeatures(cv::HOGDescriptor hog, std::vector<cv::Mat> mserImgs){
	std::vector<std::vector<float> > HOG;

	// For all of the images of the vector, compute HOG features
	for (cv::Mat i : mserImgs) {
		std::vector<float> descriptor;
		hog.compute(i, descriptor);
		HOG.push_back(descriptor);
	}
	/*for (const auto &row : HOG){
   		for (const auto &s : row) 
   			std::cout << s << ' ';
   			std::cout << std::endl;
	}*/
	// Convert HOG features vector to Matrix for the SVM
	cv::Mat sign_mat(HOG.size(), HOG[0].size(), CV_32FC1);
	auto i = 0;
	while (i < HOG.size()) {
		auto j = 0;
		while (j < HOG[0].size()) {
			sign_mat.at<float>(i, j) = HOG[i][j];
			j++;
		}
		i++;
	}
	//cv::imshow("Hog feature", sign_mat);
	//cv::waitKey(0);
	return sign_mat;
}

float TrafficSign::SVMTesting(cv::Ptr<cv::ml::SVM> &svm, cv::Mat test_HOG){
	cv::Mat answer;
	 //Give HOG features from detections to SVM and label it
	svm->predict(test_HOG, answer);

	//Return the label of the detection
	auto i = 0;
	while(i<answer.rows){
		traffic_sign = answer.at<float>(i,0);
		i++;
		return traffic_sign;
	}
}

