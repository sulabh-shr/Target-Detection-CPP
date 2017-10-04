/*
 * preprocess.hpp
 *
 *  Created on: Sep 26, 2017
 *      Author: lt-134
 */

#ifndef SRC_PREPROCESS_HPP_
#define SRC_PREPROCESS_HPP_

#include <opencv2/opencv.hpp>
//#include "show_video.hpp"
#include "parameters.hpp"
#include "utils/helper.hpp"

void filterHLS(cv::Mat img, cv::Mat *out_img_ptr, bool show=false);



#endif /* SRC_PREPROCESS_HPP_ */
