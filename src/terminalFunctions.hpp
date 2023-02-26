#include "shiroko.hpp"

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

int calc_new_height(int new_width, int width, int height)
{
	return int(float(new_width) * float(height) / float(width) * (11.0 / 24.0));
}
