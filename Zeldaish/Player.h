#pragma once
#include "Character.h"
#include "MapNode.h"
#include "Projectile.h"

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
	int getLives();
	void Update(Directions aDir, Character* aCharacter) override;

	void Attack();
	void Move(Directions aDirection) override;
	void setMaptNode(MapNode* aNoe);
	void setLives(int aLives);
	void setPlay(bool aState);

	MapNode* getMapNode();
	Projectile* gProjectile;
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

