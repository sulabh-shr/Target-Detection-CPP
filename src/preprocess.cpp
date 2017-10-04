/*
 * preprocess.cpp
 *
 *  Created on: Sep 26, 2017
 *      Author: Sulabh Shrestha
 */
#include <opencv2/opencv.hpp>
#include "parameters.hpp"
#include "utils/helper.hpp"
#include "utils/helper.hpp"

void filterHLS(cv::Mat img, cv::Mat *out_img_ptr, bool show=false){
	// Getting threshold values from track bars
	int l_threshold[2];
	l_threshold[0] = cv::getTrackbarPos(TRACKBAR_LOW_L, WIN_TRACKBAR);
	l_threshold[1] = cv::getTrackbarPos(TRACKBAR_HIGH_L, WIN_TRACKBAR);

	cv::Mat img2, hls[3];
	cv::cvtColor(img, img2, cv::COLOR_BGR2HLS);

	// Getting HLS channels
	cv::split(img2, hls);
	// Thresholding on L channel
	cv::inRange(hls[1], l_threshold[0], l_threshold[1], *out_img_ptr);

	if(show){
		showVideo(*out_img_ptr, "HLS Filtered", 2*WIN_X, 0, WIN_X, WIN_Y);
	}
}
