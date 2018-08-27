class TrafficSign{
private:
	cv::Mat red_sign, blue_sign, red_blue;
	float traffic_sign;
	cv::Mat color_hsl(cv::Mat src);
	void loadTrainingData(std::vector<cv::Mat> &train_imgs, std::vector<int> &train_labels);
	void SVMTraining(cv::Ptr<cv::ml::SVM> &svm, cv::Mat train_HOG, std::vector<int> train_labels);
public:
	TrafficSign(){}
	int startTrainingStage(cv::HOGDescriptor &hog, cv::Ptr<cv::ml::SVM> &svm, std::vector<cv::Mat> &train_imgs, std::vector<int> &train_labels);
	cv::Mat preprocess(cv::Mat img);
	cv::Mat regionOfInterest(cv::Mat src);
	std::vector<cv::Mat> interestRegionDetection(cv::Mat img, cv::Mat og);
	cv::Mat getHogFeatures(cv::HOGDescriptor hog, std::vector<cv::Mat> mserImgs);
	float SVMTesting(cv::Ptr<cv::ml::SVM> &svm, cv::Mat test_HOG);
	
};
