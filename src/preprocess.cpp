/*
 * preprocess.cpp
 *
 *  Created on: Sep 26, 2017
 *      Author: Sulabh Shrestha
 */
#include <opencv2/opencv.hpp>
#include "show_video.hpp"
#include "parameters.hpp"

void filterHLS(cv::Mat img, bool show=false){
	// Getting threshold values from track bars
	int l_threshold[2];
	l_threshold[0] = cv::getTrackbarPos(TRACKBAR_LOW_L, WIN_TRACKBAR);
	l_threshold[1] = cv::getTrackbarPos(TRACKBAR_HIGH_L, WIN_TRACKBAR);

	cv::Mat img2, hls[3], zero_channel, output;
	std::vector<cv::Mat> v;
	cv::cvtColor(img, img2, cv::COLOR_BGR2HLS);

	cv::split(img2, hls);	// Getting HLS channels
	cv::inRange(hls[1], l_threshold[0], l_threshold[1], output);


//	zero_channel = cv::Mat::zeros(cv::Size(img2.rows, img2.cols), CV_8UC1);
//	v.push_back(zero_channel);
//	v.push_back();
//	v.
//	cv::
//	cv::Mat hls[3], channels[3], output;
//	channels[0] = cv::Mat::zeros(cv::Size(img.rows, img.cols), CV_8UC1);
//	channels[2] = cv::Mat::zeros(cv::Size(img.rows, img.cols), CV_8UC1);
//
////	cv::inRange(img2, cv::Scalar(0, l_threshold[0],0), cv::Scalar(255, l_threshold[1], 255), channel);
////	cv::inRange(hls[2], cv::Scalar(l_threshold[0], cv::Scalar(l_threshold[1], output));
////	cv::threshold(hls[1], channels[1], l_threshold[0], 255, 1);
//	cv::inRange(hls[1], cv::Scalar(l_threshold[0]), cv::Scalar(l_threshold[1]), channels[1]);
//	cv::mixChannels(channels, 3, output);

	if(show){
		show_video(output, "HLS Filtered", 2*WIN_X, 0, WIN_X, WIN_Y);
	}

}
