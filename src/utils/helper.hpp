/*
 * helper.hpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Kshitiz Mandal
 */

#ifndef SRC_UTILS_HELPER_HPP_
#define SRC_UTILS_HELPER_HPP_

#include <opencv2/opencv.hpp>


/** @brief: Calculates the Root Mean Square Error (RMSE).
 *
 * @param calcualted_values values for the
 * @param actual_values standard values to compare to.
 *
 * @return RMSE of the values.
 * */
double rootMeanSquaredError(std::vector<double> calculated_values, std::vector<double> actual_values);


/** @brief: Display a window for the input image.
 *
 * @param frame input
 * @param name name of the window
 * @param pos_x x location for the window position.
 * @param pos_y y location for the window position.
 * @param x_size width of the window.
 * @param y_size height of the window.
 * */
void showVideo(cv::Mat frame, const std::string name, int pos_x = -1, int pos_y = -1, int x_size=712, int y_size=400);


/** @brief: Calculates the transformation matrix.
 *
 * @param image input image to use as a reference for viewing the result of transformation.
 * */
void perspectiveTrasnsform(cv::Mat image);


#endif /* SRC_UTILS_HELPER_HPP_ */
