#include "Screen.h"



Screen::Screen()
{
	_width = 1920;
	_height = 1080;
}
Screen::Screen(int width, int height) 
{ 
	_width = width;
	_height = height;
}

Screen::~Screen()
{
}
void Screen::setWidth(const int width)
{
	_width = width;
}
void Screen::setHeight(const int height)
{
	_height = height;
}