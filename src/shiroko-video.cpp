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

	cv::VideoCapture capture(file_path);
	cv::Mat image;

	float frame_length = 1 / (float)capture.get(cv::CAP_PROP_FPS) / 2;

	while (capture.isOpened())
	{
		float timeDelta = 0;
		clock_t clk = clock(), temp;

		capture >> image;
		if (image.empty())
			break;

		std::string asciiImage = AsciiImage(ResizeImage(image, renderWidth));

		while (timeDelta <= frame_length)
		{
			temp = clock() - clk;
			clk = clock();
			timeDelta += (float)((float)temp / CLOCKS_PER_SEC);
		}

		printf("%c[%d;%df", 0x1B, 0, 0);
		std::cout << asciiImage;
	}
}
