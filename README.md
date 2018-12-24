# TrafficSign_ADAS
## Overview
The objective of this project was to design and develop a traffic sign recognition algorithm  for autonomous vehicles applications. The self driving car market is growing at a very fast pace. Many companies are working in this problem trying to solve every aspect of it, so that autonomous cars can drive safely on the roads.

This project is focused mainly in the computer vision aspect of it, a crucial module. If an automated car is going to drive around unpredictable environments, it has to be able to perceive and detect every small detail that surrounds it.

The project was developed using C++, CMake and the OpenCV library. The input images and training images were taken from Self-Driving Car Engineer Nanodegree. The following section will explain the pipeline of the algorithm step by step.

## Algorithm
A Support Vector Machine (SVM) was used to classify the signs, so the first activity diagram corresponds to the training of the SVM.

#### Training and testing traffic signs
 To train the SVM, numerous and different images from the Belgian dataset were used. More types of signs can be added to the training stage easily for future work. Two examples of the type of images that were used can be seen below.

 ![train1](https://github.com/anurag-b/TrafficSign_ADAS/blob/master/test_img/train_1.png)
 ![train1](https://github.com/anurag-b/TrafficSign_ADAS/blob/master/test_img/train_2.png)

## Result
Video to be added

The code can be found in the src folder.

## Dependencies
The only dependency for this project is OpenCV 3.1.0. To install it, follow the next steps:

```
sudo apt-get install build-essential
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
cd ~/<my_working_directory>
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
cd ~/opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
make -j$(nproc)
sudo make install
sudo /bin/bash -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
```

## How to build, run the demo and run the tests
To build and run the demo, follow the next steps (`project_video.mp4` is the video for the demo.):

* To build:
```
git clone https://github.com/anurag-b/Lane_Detection_ADAS.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
```
* Run the demo. The argument of the executable `lanes` is the input video with its full path:
```
cd build
./traffic_sign
```
(The saved output .avi demo video is in the output_video folder)

## Doxygen Documentation
To generate Doxygen Documentation in HTML and LaTEX, follow the next steps:

```
cd <path to repository>
mkdir <documentation_folder_name>
cd <documentation_folder_name>
doxygen -g <config_file_name>
```
Inside the configuration file, update:
```
PROJECT_NAME = 'your project name'
INPUT = ../src ../include
```
Run and generate the documents by running the next command:
```
doxygen <config_file_name>
```
## License

MIT License

Copyright (c) 2017 Anurag Bansal

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.