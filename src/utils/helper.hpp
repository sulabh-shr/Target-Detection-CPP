/*
 * helper.hpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Kshitiz Mandal
 */

#ifndef SRC_UTILS_HELPER_HPP_
#define SRC_UTILS_HELPER_HPP_

#include <opencv2/opencv.hpp>

double rootMeanSquaredError(std::vector<double>, std::vector<double>);

void showVideo(cv::Mat frame, const std::string name, int pos_x = -1, int pos_y = -1, int x_size=712, int y_size=400);

void perspectiveTransform(cv::Mat image);



#endif /* SRC_UTILS_HELPER_HPP_ */
