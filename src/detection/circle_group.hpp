/*
 * circle_group.hpp
 *
 *  Created on: Oct 6, 2017
 *      Author: Sulabh Shrestha
 */

#ifndef SRC_DETECTION_CIRCLE_GROUP_HPP_
#define SRC_DETECTION_CIRCLE_GROUP_HPP_

Groups groupCircles(std::vector<CircleDetails> circles_details, const cv::Mat frame, float tolerance=20,
		bool show=false, bool verbose=false);



#endif /* SRC_DETECTION_CIRCLE_GROUP_HPP_ */
