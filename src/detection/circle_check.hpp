/*
 * circle_check.hpp
 *
 *  Created on: Oct 4, 2017
 *      Author: lt-134
 */

#ifndef SRC_DETECTION_CIRCLE_CHECK_HPP_
#define SRC_DETECTION_CIRCLE_CHECK_HPP_


#include<opencv2/opencv.hpp>
#include<math.h>

#include "../parameters.hpp"
#include "../show_video.hpp"

void checkCircle(std::vector <CircleDetails> *output, Contours contours, const cv::Mat frame,
		float round_check=ROUND_CHECK, bool show=false, bool verbose=false );



#endif /* SRC_DETECTION_CIRCLE_CHECK_HPP_ */
