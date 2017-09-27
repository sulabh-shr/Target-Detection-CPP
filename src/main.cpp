/*
 * main.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: Sulabh Shrestha
 */
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

#include "show_video.hpp"
#include "parameters.hpp"
#include "detection.hpp"
#include "preprocess.hpp"

void on_low_l_threshold(int, void *);
void on_high_l_threshold(int, void *);

int low_l = l_thresh[0];
int high_l = l_thresh[1];

int main(int argc, char** argv){

	bool IMAGE = false;

	if(!IMAGE){
		cv::VideoCapture cap(VIDEO_SOURCE_INPUT);
		// Checking if Camera is working or not
		if(!cap.isOpened())
			return -1;

		// Creating track bars
		cv::namedWindow(WIN_TRACKBAR, cv::WINDOW_NORMAL);
		cv::resizeWindow(WIN_TRACKBAR, WIN_X, WIN_Y);
		cv::moveWindow(WIN_TRACKBAR, 0, 0);
		cv::createTrackbar(TRACKBAR_LOW_L, WIN_TRACKBAR, &low_l, 255, on_low_l_threshold);
		cv::createTrackbar(TRACKBAR_HIGH_L, WIN_TRACKBAR, &high_l, 255, on_high_l_threshold);

		std::cout<<WIN_X;
		while(1){
			cv::Mat frame, hls_filtered;
			cap >> frame;

			show_video(frame, "video", WIN_X, 0, WIN_X, WIN_Y);
			filterHLS(frame, &hls_filtered, true);

			int key = cv::waitKey(1);
			if(key == 27)	// Stop if 'Escape' key is pressed
				break;
			else if(key == 99)	// Capture if 'c' key is pressed
				cv::imwrite("capture.jpg", frame);
		}
	}
		else{
			cv::Mat img;
			img = cv::imread("t.jpg", 1);

			const std::string name = "My Image";

			//std::cout<<img.size();

			cv::Mat hls[3];		// Array of Matrices
			cv::split(img, hls);
			cv::Mat output;
			cv::inRange(img, cv::Scalar(100), cv::Scalar(255), output);

			cv::namedWindow(name, cv::WINDOW_NORMAL);
			cv::imshow(name, output);
			cv::waitKey(0);
		}

}


void on_low_l_threshold(int, void *)
{
    cv::setTrackbarPos(TRACKBAR_LOW_L, WIN_TRACKBAR, low_l);
}

void on_high_l_threshold(int, void *)
{
    cv::setTrackbarPos(TRACKBAR_HIGH_L, WIN_TRACKBAR, high_l);
}

