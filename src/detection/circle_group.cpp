/*
 * circle_group.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Sulabh Shrestha
 */

#include <opencv2/opencv.hpp>
//#include <array>
#include <map>

#include "../parameters.hpp"

typedef std::map<Key, Contours> Groups;
typedef Groups::const_iterator It;

void groupCircles(int* output, std::vector<CircleDetails> circles_details, const cv::Mat frame, float tolerance=20,
		bool show=false, bool verbose=false){
	if(!verbose){
		int a =6;
	}else{
//		std::map<Key, Contours> groups;
		Groups groups;
//		groups::iterator it;	// Iterator of group used to iteration

		// Initializing groups with 1st circle values
		CircleDetails first_circle = circles_details[0];
		Key key1 = {first_circle.cx, first_circle.cy};
		Contours first_group;
		first_group.push_back(first_circle.contour);
//		groups[key1] = first_group;

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
				std::cout<<"Found a group"<<std::endl;
				groups[found_key].push_back(circles_details[i].contour);
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
