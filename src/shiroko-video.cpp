#include "shiroko.h"
#include "asciiFunctions.hpp"

int main(int argc, char **argv)
{
	std::string file_path;

	if (argc > 1)
	{
		file_path = argv[1];
	}
	else
	{
		std::cout << "Input path of file: ";
		std::cin >> file_path;
	}

	cv::VideoCapture capture(file_path);
	cv::Mat image;

	float frameLength = 1 / capture.get(cv::CAP_PROP_FPS);

	while (capture.isOpened())
	{
		capture >> image;
		if (image.empty())
			break;

		int renderWidth = CalcTermWidth(120, 30, image.cols, image.rows);
		std::string asciiImage = AsciiImage(ResizeImage(image, renderWidth));

		printf("%c[%d;%df", 0x1B, 0, 0);

		std::cout << asciiImage;
	}
}
