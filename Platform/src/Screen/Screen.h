#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
	int _width;
	int _height;
public:
	Screen();
	Screen(int width, int height);
	virtual ~Screen();
};

#endif // !SCREEN_H


