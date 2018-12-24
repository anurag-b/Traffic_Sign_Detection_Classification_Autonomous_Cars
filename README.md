# TrafficSign_ADAS
## Overview
The objective of this project was to design and develop a traffic sign recognition algorithm  for autonomous vehicles applications. The self driving car market is growing at a very fast pace. Many companies are working in this problem trying to solve every aspect of it, so that autonomous cars can drive safely on the roads.

This project is focused mainly in the computer vision aspect of it, a crucial module. If an automated car is going to drive around unpredictable environments, it has to be able to perceive and detect every small detail that surrounds it.

The project was developed using C++, CMake and the OpenCV library. The input images and training images were taken from Self-Driving Car Engineer Nanodegree. The following section will explain the pipeline of the algorithm step by step.

## Algorithm
A Support Vector Machine (SVM) was used to classify the signs, so the first activity diagram corresponds to the training of the SVM.

#### Training and testing traffic signs
 To train the SVM, numerous and different images from the Belgian dataset were used. More types of signs can be added to the training stage easily for future work. Two examples of the type of images that were used can be seen below.

 ![train1]()