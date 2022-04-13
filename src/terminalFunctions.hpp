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