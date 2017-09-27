/*
 * preprocess.hpp
 *
 *  Created on: Sep 26, 2017
 *      Author: lt-134
 */

#ifndef SRC_PREPROCESS_HPP_
#define SRC_PREPROCESS_HPP_

#include <opencv2/opencv.hpp>
#include "show_video.hpp"
#include "parameters.hpp"

cv::Mat filterHLS(cv::Mat img, bool show=false);



#endif /* SRC_PREPROCESS_HPP_ */
