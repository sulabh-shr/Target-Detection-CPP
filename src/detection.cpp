/*
 * detection.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: Sulabh Shrestha
 */
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

typedef std::vector<cv::Vec4i> Contours;
typedef std::vector<cv::Vec4i> Hierarchy;


Contours findContours(cv::Mat img, cv::Mat frame, int points=50, bool show=false){
	// Finding all contours in the image
	Contours contours;
	Hierarchy hierarchy;
	/// Function header required for findContours
	void thresh_callback(int, void* );
    cv::findContours(img, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );

    return contours;
//    //Filtering contours based on their minimum points
//    filtered = []
//    for i in range(len(contours)):
//        if len(contours[i]) > points:
//            filtered.append(contours[i])
//
//    if show:
//        frame_copy = np.copy(frame)
//        cv2.drawContours(frame_copy, filtered, -1, (0, 0, 255), 3)
//        show_video(frame_copy, 'Points Filtered Contours', WIN_X, WIN_Y, 2*(WIN_X+POS_X_OFFSET), 0)
}


