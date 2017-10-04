/*
 * show_video.h
 *
 *  Created on: Sep 25, 2017
 *      Author: lt-134
 */

#ifndef SRC_SHOW_VIDEO_HPP_
#define SRC_SHOW_VIDEO_HPP_

#include <opencv2/opencv.hpp>

void show_video(cv::Mat frame,const std::string name, int pos_x=-1, int pos_y=-1,
		int x_size=712, int y_size=400);

#endif /* SRC_SHOW_VIDEO_HPP_ */
