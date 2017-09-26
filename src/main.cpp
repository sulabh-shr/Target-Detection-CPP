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


int main(int argc, char** argv){
	bool IMAGE = false;
	if(IMAGE){
		cv::Mat img;
		img = cv::imread("t.jpg", 1);
		const std::string name = "My Image";
		cv::namedWindow(name, cv::WINDOW_NORMAL);
		cv::imshow(name, img);
		cv::waitKey(0);
	}
	else{
		cv::VideoCapture cap(1);
		if(!cap.isOpened())
			return -1;

		while(1){
			cv::Mat frame;
			cap >> frame;
			show_video(frame, "video", WIN_X, WIN_Y, 0, 0);
			int key = cv::waitKey(1);
			if(key == 27)	// Stop if 'Escape' key is pressed
				break;
			else if(key == 99)	// Capture if 'c' key is pressed
				cv::imwrite("capture.jpg", frame);
		}

	}




}



