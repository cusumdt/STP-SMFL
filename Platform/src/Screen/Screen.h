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
	void setWidth(const int width);
	void setHeight(const int height);
	int getWidth() const { return _width; }
	int getHeight() const { return _height; }
};

#endif // !SCREEN_H


