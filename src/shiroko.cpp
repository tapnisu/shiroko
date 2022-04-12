#include "shiroko.h"

using namespace std;
using namespace cv;

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

Mat ResizeImage(Mat image, float newWidth = 0, float newHeight = 0)
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

	Mat resizedImage;

	resize(image, resizedImage, Size(newWidth, newHeight), INTER_LINEAR);

	return resizedImage;
}

float GetBrightness(int r, int g, int b)
{
	float brightness = ((0.21 * r) + (0.72 * g) + (0.07 * b)) / 255;

	return brightness;
}

string AsciiImage(Mat image)
{
	string asciiString = " .'`^\",:;Il!i ><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	int asciiString_length = size(asciiString) - 2;
	string result = "";

	uint8_t *pixelPtr = (uint8_t *)image.data;
	int cn = image.channels();
	Scalar_<uint8_t> bgrPixel;

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

int main(int argc, char **argv)
{
	string filePath;

	if (argc > 1)
	{
		filePath = argv[1];
	}
	else
	{
		cout << "Input path of file: ";
		cin >> filePath;
	}

	VideoCapture capture(filePath);
	Mat image;

	float frameLength = 1 / capture.get(CAP_PROP_FPS);

	while (capture.isOpened())
	{
		capture >> image;
		if (image.empty())
			break;

		int renderWidth = CalcTermWidth(256, 256, image.cols, image.rows);
		string asciiImage = AsciiImage(ResizeImage(image, renderWidth));

		printf("%c[%d;%df", 0x1B, 0, 0);

		cout << asciiImage;
	}
}
