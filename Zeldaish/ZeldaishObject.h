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
	SDL_Rect getRectangle();

	void setX(int aLocation);
	void setY(int aLocation);
	void setH(int aSize);
	void setW(int aSize);
private:

protected:
	std::string gName;

	SDL_Surface* gImage;
	SDL_Rect* gImageArea;
};

