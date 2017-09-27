/*
 * find_contours.hpp
 *
 *  Created on: Sep 27, 2017
 *      Author: lt-134
 */

#ifndef SRC_DETECTION_FIND_CONTOURS_HPP_
#define SRC_DETECTION_FIND_CONTOURS_HPP_

#include <opencv2/opencv.hpp>

typedef std::vector<std::vector<cv::Point> > Contours;
typedef std::vector<cv::Vec4i> Hierarchy;

void findContours(cv::Mat frame, cv::Mat binary_img, Contours* contours, Hierarchy hierarchy, bool show=false);


#endif /* SRC_DETECTION_FIND_CONTOURS_HPP_ */
