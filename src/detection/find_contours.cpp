/*
 * find_contours.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: lt-134
 */

#include <opencv2/opencv.hpp>
#include "../parameters.hpp"
#include "../show_video.hpp"


void findContours(cv::Mat frame, cv::Mat binary_img, Contours* contours, Hierarchy hierarchy,
		bool show=false, bool verbose=false){

	if(verbose){
		// Finding all contours in the image
		std::cout<<"\nFinding contours\n";
		Contours temp_contours;
		cv::findContours(binary_img, temp_contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, cv::Point(0, 0) );
		std::cout<<"Contours Found: "<<temp_contours.size()<<"\n";

		// Checking if contours have minimum accepted number of points
		for(int i = 0; i < int(temp_contours.size()); i++){
			if(temp_contours[i].size() >= MIN_CONTOUR_POINTS){
				contours->push_back(temp_contours[i]);
			}
		}
	}

	if(show){
		cv::Mat drawing_img = frame;
		cv::Scalar color = cv::Scalar(255, 0, 0);
		cv::drawContours(drawing_img, *contours, -1, color, 3, 8);
		show_video(drawing_img, "Contours", 0, WIN_Y, WIN_X, WIN_Y);

	}
}



