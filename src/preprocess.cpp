/*
 * preprocess.cpp
 *
 *  Created on: Sep 26, 2017
 *      Author: Sulabh Shrestha
 */
#include <opencv2/opencv.hpp>
#include "show_video.hpp"
#include "parameters.hpp"

cv::Mat filterHLS(cv::Mat img, bool show=false){
	// Getting threshold values from track bars
	int l_threshold[2];
	l_threshold[0] = cv::getTrackbarPos(TRACKBAR_LOW_L, WIN_TRACKBAR);
	l_threshold[1] = cv::getTrackbarPos(TRACKBAR_HIGH_L, WIN_TRACKBAR);

	cv::Mat img2, hls[3], output;
	cv::cvtColor(img, img2, cv::COLOR_BGR2HLS);

	// Getting HLS channels
	cv::split(img2, hls);
	// Thresholding on L channel
	cv::inRange(hls[1], l_threshold[0], l_threshold[1], output);

	if(show){
		show_video(output, "HLS Filtered", 2*WIN_X, 0, WIN_X, WIN_Y);
	}

	return output;
}
