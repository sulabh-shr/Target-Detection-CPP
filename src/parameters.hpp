/*
 * parameters.hpp
 *
 *  Created on: Sep 25, 2017
 *      Author: lt-134
 */

#ifndef SRC_PARAMETERS_HPP_
#define SRC_PARAMETERS_HPP_
#include<opencv2/opencv.hpp>

const int VIDEO_SOURCE_INPUT = 0;
const int WIN_Y = 325;
const int WIN_X = WIN_Y * 4/3;
const int POS_X_OFFSET = int(WIN_X * 0.1);
const int POS_Y_OFFSET = 80;
const int MIN_CONTOUR_POINTS = 25;
const float ROUND_CHECK = 0.75;
const int GROUPING_DISTANCE = 20;



const std::string WIN_TRACKBAR = "Track Bars";
const std::string TRACKBAR_LOW_L = "Low L";
const std::string TRACKBAR_HIGH_L = "High L";

const int l_thresh[] = {190, 255};
const int RADII[] = {100, 150, 225, 350, 400, 575, 675};

typedef std::vector<cv::Point> Contour;
typedef std::vector<Contour> Contours;
typedef std::vector<cv::Vec4i> Hierarchy;
typedef struct{
	Contour contour;
	double area;
	double length;
	double roundness;
	cv::Moments moments;
	int cx;
	int cy;
} CircleDetails;


#endif /* SRC_PARAMETERS_HPP_ */
