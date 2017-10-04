/*
 * circle_check.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: Sulabh Shrestha
 */
#include<opencv2/opencv.hpp>
#include<math.h>

#include "../parameters.hpp"
#include "../show_video.hpp"


void checkCircle(std::vector <CircleDetails> *output, Contours contours, const cv::Mat frame,
		float round_check=ROUND_CHECK, bool show=false, bool verbose=false ){

	// Temporary variable for saving contours to draw
	Contours circles;

	if(!verbose){
		// Iterating over each counter
		for(int i = 0; i < int(contours.size()); i++){
			CircleDetails details;
			details.contour = contours[i];

			// Calculating roundness
			details.area = cv::contourArea(contours[i]);
			details.length = cv::arcLength(contours[i], true);
			details.roundness = 4.0 * M_PI * details.area/pow(details.length, 2);

			// Checking roundness of contour
			if(details.roundness >= ROUND_CHECK){
				// Calculating the center (cx, cy)
				details.moments = cv::moments(contours[i]);
				details.cx = details.moments.m10/details.moments.m00;
				details.cy = details.moments.m01/details.moments.m00;

				// Appending to the vector of circle details of circles
				output->push_back(details);

				// Saving contours to draw
				circles.push_back(contours[i]);
			}

		}
	}
	else{
		std::cout<<"\nCHECKING ROUNDNESS......."<<std::endl;
		// Iterating over each counter
		for(int i = 0; i < int(contours.size()); i++){
			CircleDetails details;
			details.contour = contours[i];

			// Calculating roundness
			details.area = cv::contourArea(contours[i]);
			details.length = cv::arcLength(contours[i], true);
			details.roundness = (4.0 * M_PI * details.area)/pow(details.length, 2);

			// Checking roundness of contour
			if(details.roundness >= ROUND_CHECK){
				std::cout<<"Roundness passed with value "<<details.roundness<<std::endl;


				// Calculating the center (cx, cy)
				details.moments = cv::moments(contours[i]);
				details.cx = details.moments.m10/details.moments.m00;
				details.cy = details.moments.m01/details.moments.m00;

				// Appending to the vector of circle details of circles
				output->push_back(details);

				// Saving contours to draw
				circles.push_back(contours[i]);
			}
		}
		std::cout<<"Total circles found: "<<circles.size()<<std::endl;
	}

	if(show){
		cv::Mat drawing_frame = frame.clone();
		cv::Scalar color = cv::Scalar(255, 0, 0);
		cv::drawContours(drawing_frame, circles, -1, color, 3, 8);
		show_video(drawing_frame, "Circles found", WIN_X, WIN_Y, WIN_X, WIN_Y);
	}
};


