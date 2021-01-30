#ifndef _CBOT_H_
#define _CBOT_H_

#include <SDL.h>
#include <list>

#define PI 3.1415926535897932384626433832795

#include <cmath>

#include "CTank.h"
#include "CBullet.h"
#include "CMap.h"
#include "CCamera.h"

class CBot
{
private:
	list <CBullet> Vbullet;
private:
	SDL_Texture* bullet;
private:
	CTank tank;
public:
	void load(SDL_Renderer* ren, TextureCache& tcache);
	void render(SDL_Renderer* ren);
	bool collision(CMap& map);
	void help();
};

#endif 
