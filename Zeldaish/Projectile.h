#pragma once
#include "ZeldaishObject.h"
class Projectile :
	public ZeldaishObject
{
public:
	Projectile(std::string aSFX);
	~Projectile();

	void Update();
	void Display(SDL_Renderer* aRenderer) override;
	bool isFired();
	void FireProjectile(Directions aDirection);
	void setFired(bool aState);
private:
	bool gFired;
	Directions gCurrentDirection;
	Mix_Chunk* gSFX;
};

