/*
 * circle_group.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Sulabh Shrestha
 */

#include <opencv2/opencv.hpp>
#include <array>
#include <map>

#include "../parameters.hpp"

void groupCircles(int* output, std::vector<CircleDetails> circles_details, const cv::Mat frame, float tolerance=20,
		bool show=false, bool verbose=false){
	if(!verbose){
		int a =6;
	}else{
		typedef std::array<int, 2> Key;
		std::map<Key, Contours> groups;
		groups::iterator it;	// Iterator of group used to iteration

		// Initializing groups with 1st circle values
		CircleDetails first_circle = circles_details[0];
		Key key1 = {first_circle.cx, first_circle.cy};
		groups[key1] = first_circle.contour;

		for(int i = 1; i < circles_details.size(); i++){

			bool found = false;
			Key found_key;

			for(it = groups.begin(); it != groups.end(); it++){
				if((it->first[0] - circles_details[i].cx <= tolerance) and (it->first[1] - circles_details[i].cy <= tolerance )){
					found = true;
					found_key = it->first;
					break;
				}
			}

			if(found){
				std::cout<<"Found a group"<<std::endl;
				groups[found_key].push_back(circles_details[i]);
			}else{
				std::cout<<"Creating a new group"<<std::endl;
				Key new_key = {circles_details[i].cx, circles_details[i].cy};
				Contours value;
				value.push_back(circles_details[i].contour);
				groups[new_key] = value;
			}
		}



	}
}
