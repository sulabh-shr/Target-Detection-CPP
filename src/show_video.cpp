/*
 * show_video.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: Sulabh Shrestha
 */

#include <opencv2/opencv.hpp>

void show_video(cv::Mat frame,const std::string name, int pos_x=-1, int pos_y=-1, int x_size=712, int y_size=400){

	cv::namedWindow(name, cv::WINDOW_NORMAL);
	cv::resizeWindow(name, x_size, y_size);
	if(pos_x!=-1 && pos_y!=-1)
		cv::moveWindow(name, pos_x, pos_y);
	cv::imshow(name, frame);
}



