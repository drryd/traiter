#pragma once

#include <opencv2/imgproc/imgproc.hpp>

namespace utility
{
	//////////////////////////////////////////////////////////////////////////////////
	// OcvUtilities
	//
	// Helper functions for common computations related to OpenCV.
	//////////////////////////////////////////////////////////////////////////////////
	class OcvUtilities final
	{
	public:
		static std::vector<cv::Point> keepOnlyLargestContour(cv::Mat& originalImage);
		static int getLargestContourIndex(const std::vector<std::vector<cv::Point>>& contours);

		static bool isPointInImage(const cv::Mat& image, const cv::Point& point);
		static bool isPointWhite(const cv::Mat& image, const cv::Point& point);

		static std::vector<cv::Point> OcvUtilities::getNeighboringPixels(const cv::Mat& image, const cv::Point& point);

		static void padImage(const cv::Mat& sourceImage, cv::Mat& destinationImage, const int padAmount = 1);
		static void removePadding(const cv::Mat& sourceImage, cv::Mat& destinationImage, const int padAmount = 1);
	private:
		template<typename T> static bool isPointExpectedColor(const cv::Mat& image, const cv::Point& point, const T color);

		OcvUtilities();
	};
}
