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

void findContours(Contours* contours, Hierarchy* hierarchy, const cv::Mat frame, const cv::Mat binary_img,
		bool show=false, bool verbose=false);

#endif /* SRC_DETECTION_FIND_CONTOURS_HPP_ */
