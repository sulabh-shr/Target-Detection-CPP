/*
 * find_contours.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: lt-134
 */

#include <opencv2/opencv.hpp>
#include "../parameters.hpp"
#include "../show_video.hpp"


void findContours(Contours* contours, Hierarchy* hierarchy,const cv::Mat frame, const cv::Mat binary_img,
		bool show=false, bool verbose=false){

	if(not verbose){
		// Finding all contours in the image
		Contours temp_contours;
		cv::findContours(binary_img, temp_contours, *hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, cv::Point(0, 0) );

		// Checking if contours have minimum accepted number of points
		for(int i = 0; i < int(temp_contours.size()); i++){
			if(temp_contours[i].size() >= MIN_CONTOUR_POINTS){
				contours->push_back(temp_contours[i]);
			}
		}
	}
	else{
		// Finding all contours in the image
		std::cout<<"\nFINDING CONTOURS......"<<std::endl;
		Contours temp_contours;
		cv::findContours(binary_img, temp_contours, *hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, cv::Point(0, 0) );
		std::cout<<"Contours Found: "<<temp_contours.size()<<"\n";

		// Checking if contours have minimum accepted number of points
		for(int i = 0; i < int(temp_contours.size()); i++){
			if(temp_contours[i].size() >= MIN_CONTOUR_POINTS){
				contours->push_back(temp_contours[i]);
			}
		}

		std::cout<<"Contours with appropriate points: "<<contours->size()<<std::endl;
	}

	if(show){
		cv::Mat drawing_frame = frame.clone();
		cv::Scalar color = cv::Scalar(255, 0, 0);
		cv::drawContours(drawing_frame, *contours, -1, color, 3, 8);
		show_video(drawing_frame, "Contours", 0, WIN_Y, WIN_X, WIN_Y);

	}
}



