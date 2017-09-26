/*
 * detection.hpp
 *
 *  Created on: Sep 26, 2017
 *      Author: lt-134
 */

#ifndef SRC_DETECTION_HPP_
#define SRC_DETECTION_HPP_


#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

void findContours(cv::Mat img, cv::Mat frame, int points=50, bool show=false);


#endif /* SRC_DETECTION_HPP_ */
