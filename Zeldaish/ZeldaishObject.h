#pragma once

class ZeldaishObject
{
public:
	ZeldaishObject(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH);
	~ZeldaishObject();

	int getX();
	int getY();
	int getW();
	int getH();

	void setX(int aLocation);
	void setY(int aLocation);
	void setH(int aSize);
	void setW(int aSize);
private:

protected:
	std::string name;

	SDL_Surface* image;
	SDL_Rect* imageArea;
};

