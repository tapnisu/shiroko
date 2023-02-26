#include "shiroko.hpp"

int main(int argc, char **argv)
{
	std::string file_path;
	int renderWidth;

	if (argc > 1)
	{
		file_path = argv[1];
	}
	else
	{
		std::cout << "Input path of file: ";
		std::cin >> file_path;
	}

	if (argc > 2)
	{
		renderWidth = atoi(argv[2]);
	}
	else
	{
		std::cout << "Input target width: ";
		std::cin >> renderWidth;
	}

	cv::Mat image = cv::imread(file_path);
	std::string asciiImage = AsciiImage(ResizeImage(image, renderWidth));
	std::cout << asciiImage;
}
