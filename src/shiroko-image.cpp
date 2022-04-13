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

	cv::Mat image = cv::imread(file_path);
	int renderWidth = CalcTermWidth(120, 30, image.cols, image.rows);
	std::string asciiImage = AsciiImage(ResizeImage(image, renderWidth));
	std::cout << asciiImage;
}
