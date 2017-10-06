/*
 * circle_group.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Sulabh Shrestha, Kshitiz Mandal
 */

#include <opencv2/opencv.hpp>
//#include <array>
#include <map>
#include "../show_video.hpp"
#include "../parameters.hpp"

typedef Groups::const_iterator It;

Groups groupCircles(std::vector<CircleDetails> circles_details, const cv::Mat frame, float tolerance=20,
		bool show=false, bool verbose=false){

	//std::map<Key, Contours> groups;
	Groups groups;
	//		groups::iterator it;	// Iterator of group used to iteration

	// Initializing groups with 1st circle values
	CircleDetails first_circle = circles_details[0];
	Key key1 = {first_circle.cx, first_circle.cy};
	Contours first_group;
	first_group.push_back(first_circle.contour);
	groups[key1] = first_group;


	if(!verbose){
		int a =6;
	}else{
		std::cout<<"\nGROUPING CIRCLES..........";
		for(int i = 1; i < circles_details.size(); i++){

			bool found = false;
			Key found_key;

			for(It it = groups.begin(); it != groups.end(); it++){
				if((it->first.x - circles_details[i].cx <= tolerance)
						and (it->first.y - circles_details[i].cy <= tolerance )){
					found = true;
					found_key = it->first;
					break;
				}
			}

			if(found){
				std::cout<<"Found existing group"<<std::endl;
				groups[found_key].push_back(circles_details[i].contour);
			}else{
				std::cout<<"Creating a new group with center (";
				Key new_key = {circles_details[i].cx, circles_details[i].cy};
				std::cout<<new_key.x<<", "<<new_key.y<<")"<<std::endl;
				Contours value;
				value.push_back(circles_details[i].contour);
				groups[new_key] = value;
			}
		}
		std::cout<<"Total groups of circles found: "<<groups.size()<<std::endl;
	}

	if(show){
		cv::Mat drawing_frame = frame.clone();
		for(It it = groups.begin(); it != groups.end(); it++){
			cv::RNG rng(12345);
			cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//			cv::Scalar color = cv::Scalar(0, 255, 0);
			cv::drawContours(drawing_frame, groups[it->first], -1, color, 3, 8);
		}
		show_video(drawing_frame, "Grouped Circles", 2*WIN_X, WIN_Y, WIN_X, WIN_Y);
	}

	return groups;
}
