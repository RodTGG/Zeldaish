#include "stdafx.h"
#include "Player.h"
#include "Projectile.h"


Player::Player(std::string aName, std::string aImgName) : Character(aName, aImgName)
{
	gScore = 0;
	gSteps = 0;
	gLives = 3;
	gXP = 0;
	gSpeed = 10;
	gPlaying = false;
	gMap = new MapNode("Home", "ground.png");

	gClips[0].x = 22;
	gClips[0].y = 97;
	gClips[0].w = 357;
	gClips[0].h = 456;

	gClips[1].x = 451;
	gClips[1].y = 124;
	gClips[1].w = 328;
	gClips[1].h = 427;

	gClips[2].x = 824;
	gClips[2].y = 99;
	gClips[2].w = 354;
	gClips[2].h = 452;

	gClips[3].x = 1222;
	gClips[3].y = 124;
	gClips[3].w = 329;
	gClips[3].h = 431;

	gClips[4].x = 25;
	gClips[4].y = 700;
	gClips[4].w = 352;
	gClips[4].h = 451;

	gClips[5].x = 449;
	gClips[5].y = 725;
	gClips[5].w = 327;
	gClips[5].h = 427;

	gClips[6].x = 825;
	gClips[6].y = 701;
	gClips[6].w = 352;
	gClips[6].h = 453;

	gClips[7].x = 1224;
	gClips[7].y = 724;
	gClips[7].w = 327;
	gClips[7].h = 426;

	gClips[8].x = 49;
	gClips[8].y = 1299;
	gClips[8].w = 303;
	gClips[8].h = 427;

	gClips[9].x = 449;
	gClips[9].y = 1326;
	gClips[9].w = 303;
	gClips[9].h = 400;

	gClips[10].x = 850;
	gClips[10].y = 1300;
	gClips[10].w = 301;
	gClips[10].h = 425;

	gClips[11].x = 1250;
	gClips[11].y = 1325;
	gClips[11].w = 302;
	gClips[11].h = 401;

	gClips[12].x = 49;
	gClips[12].y = 1925;
	gClips[12].w = 302;
	gClips[12].h = 402;

	gClips[13].x = 449;
	gClips[13].y = 1900;
	gClips[13].w = 303;
	gClips[13].h = 425;

	gClips[14].x = 850;
	gClips[14].y = 1924;
	gClips[14].w = 302;
	gClips[14].h = 402;

	gClips[15].x = 1249;
	gClips[15].y = 1900;
	gClips[15].w = 301;
	gClips[15].h = 426;

	SDL_Rect* gunRect = new SDL_Rect();
	gunRect->x = 16;
	gunRect->y = 16;
	gunRect->w = 50;
	gunRect->h = 38;

	Item* fRuger = new Item("Ruger", "guns.png", gunRect);
	gInventory->AddItem(fRuger);
	fRuger = nullptr;

	gAnimation = 0;
	gCurrentClip = gClips[0];

	gProjectile = new Projectile("laser.wav");
}


Player::~Player()
{
}

void Player::Attack() 
{
	gProjectile->SetPosition(getX(), getY());
	gProjectile->setFired(true);
	gProjectile->FireProjectile(gCurrentDirection);
}

void Player::PlayAnimation()
{
	while (gPlaying)
	{
		switch (gAnimation)
		{
		case 0:
			gCurrentClip = gClips[0];
			break;
		case 1:
			gCurrentClip = gClips[0];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[1];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[2];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[3];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			break;
		case 2:
			gCurrentClip = gClips[4];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[5];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[6];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[7];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			break;
		case 3:
			gCurrentClip = gClips[8];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[9];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[10];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[11];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			break;
		case 4:
			gCurrentClip = gClips[12];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[13];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[14];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			gCurrentClip = gClips[15];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			break;
		}
	}
}

void Player::SetAnimation(int aNum)
{
	gAnimation = aNum;
}

void Player::Display(SDL_Renderer* aRenderer)
{
	gMap->Display(aRenderer);

	if (gAlive) 
	{
		gTexture = ZeldaishFunctions::loadTexture(*aRenderer, gImagePath);
		SDL_RenderCopy(aRenderer, gTexture, &gCurrentClip, gImageArea);
		SDL_DestroyTexture(gTexture);
	}
}

bool Player::isPlaying()
{
	return gPlaying;
}

void Player::setPlay(bool aState)
{
	gPlaying = aState;
}

int Player::getLives()
{
	return gLives;
}

MapNode* Player::getMapNode()
{
	return gMap;
}

void Player::setMaptNode(MapNode* aNode)
{
	gMap = aNode;
}

void Player::setLives(int aLives)
{
	gLives = aLives;
}

void Player::Move(Directions aDirection)
{
	switch (aDirection)
	{
	case DIRECTION_UP:
		gCurrentDirection = DIRECTION_UP;
		SetPosition(getX(), getY() - gSpeed);
		SetAnimation(2);
		break;
	case DIRECTION_DOWN:
		gCurrentDirection = DIRECTION_DOWN;
		SetPosition(getX(), getY() + gSpeed);
		SetAnimation(1);
		break;
	case DIRECTION_LEFT:
		gCurrentDirection = DIRECTION_LEFT;
		SetPosition(getX() - gSpeed, getY());
		SetAnimation(3);
		break;
	case DIRECTION_RIGHT:
		gCurrentDirection = DIRECTION_RIGHT;
		SetPosition(getX() + gSpeed, getY());
		SetAnimation(4);
		break;
	}
}

void Player::Update(Directions aDir, Character* aCharacter) {}