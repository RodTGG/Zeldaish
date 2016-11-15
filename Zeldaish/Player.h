#pragma once
#include "Character.h"
#include "MapNode.h"

class Player :
	public Character
{
public:
	Player(std::string aName, std::string aImgName);
	~Player();

	void Display(SDL_Renderer* aRenderer) override;
	void SetAnimation(int aNum);
	void PlayAnimation();

	bool isPlaying();
	void setPlay(bool aState);
	int getLives();

	void setMaptNode(MapNode* aNoe);
	MapNode* getMapNode();
private:
	int gScore;
	int gSteps;
	int gLives;
	int gXP;
	int gAnimation;

	bool gPlaying;

	SDL_Rect gCurrentClip;
	SDL_Rect gClips[16];

	MapNode* gMap;
};

