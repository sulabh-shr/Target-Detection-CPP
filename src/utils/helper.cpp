/*
 * helper.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Kshitiz Mandal
 */

#include <opencv2/opencv.hpp>

double rootMeanSquaredError(std::vector<double> calculated_values, std::vector<double> actual_values){
	double error = 0;

	for (unsigned i = 0; i < calculated_values.size(); i++ ){
		error += pow((calculated_values.at(i) - actual_values.at(i)), 2);
	}
	error = error/calculated_values.size();
	return pow(error, 0.5);
}


void showVideo(cv::Mat frame,const std::string name, int pos_x = -1, int pos_y = -1, int x_size = 712, int y_size = 400){
	cv::namedWindow(name, cv::WINDOW_NORMAL);
	cv::resizeWindow(name, x_size, y_size);
	if(pos_x!=-1 && pos_y!=-1)
		cv::moveWindow(name, pos_x, pos_y);
	cv::imshow(name, frame);
}
