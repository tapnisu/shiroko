#include "shiroko.hpp"

cv::Mat ResizeImage(cv::Mat image, int newWidth = 0, int newHeight = 0)
{
	float imageAttitude = (float)image.cols / image.rows;
	float pixelAspect = 24.0f / 11.0f;

	if (newHeight == 0)
	{
		newHeight = (int)(newWidth / imageAttitude / pixelAspect);
	}
	else if (newWidth == 0)
	{
		newWidth = (int)(newHeight * imageAttitude * pixelAspect);
	}
	else
	{
		return image;
	}

	cv::Mat resizedImage;

	cv::resize(image, resizedImage, cv::Size(newWidth, newHeight), cv::INTER_LINEAR);

	return resizedImage;
}

float GetBrightness(int r, int g, int b)
{
	float max = std::max(std::max(r, g), b);
	float min = std::min(std::min(r, g), b);

	return (max + min) / 510;
}

std::string AsciiImage(cv::Mat image)
{
	std::string asciiString = " .,:;+*?\%S#@";
	int asciiString_length = (int)std::size(asciiString) - 2;
	std::string result = "";

	uint8_t *pixelPtr = (uint8_t *)image.data;
	int cn = image.channels();
	cv::Scalar_<uint8_t> bgrPixel;

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			bgrPixel.val[0] = pixelPtr[i * image.cols * cn + j * cn + 0];
			bgrPixel.val[1] = pixelPtr[i * image.cols * cn + j * cn + 1];
			bgrPixel.val[2] = pixelPtr[i * image.cols * cn + j * cn + 2];

			int symbolIndex = (int)(asciiString_length * GetBrightness(bgrPixel.val[2], bgrPixel.val[1], bgrPixel.val[0]));

			result += asciiString[symbolIndex];
		}

		result += '\n';
	}

	return result;
}
