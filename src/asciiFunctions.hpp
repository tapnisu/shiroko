#include "shiroko.h"

int CalcTermWidth(int termWidth, int termHeight, int imageWidth, int imageHeight)
{
	float imageAttitude = (float)imageWidth / imageHeight;
	float termAttitude = (float)termWidth / termHeight;
	int newWidth;

	if (termWidth / imageAttitude < termHeight)
	{
		newWidth = termWidth;
	}
	else
	{
		newWidth = (int)(termHeight * termAttitude);
	}

	return newWidth;
}

cv::Mat ResizeImage(cv::Mat image, float newWidth = 0, float newHeight = 0)
{
	float imageAttitude = (float)image.cols / image.rows;
	float pixelAspect = 24.0f / 11.0f;

	if (newHeight == 0)
	{
		newHeight = newWidth / imageAttitude / pixelAspect;
	}
	else if (newWidth == 0)
	{
		newWidth = newHeight * imageAttitude * pixelAspect;
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
	float brightness = ((0.21 * r) + (0.72 * g) + (0.07 * b)) / 255;

	return brightness;
}

std::string AsciiImage(cv::Mat image)
{
	std::string asciiString = " .'`^\",:;Il!i ><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	int asciiString_length = std::size(asciiString) - 2;
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
