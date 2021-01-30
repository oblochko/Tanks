#ifndef _CBULLET_H_
#define _CBULLET_H_

#include <SDL.h>
#include <vector>

#include "TextureCache.h"
#include "CSurface.h"
#include "CMap.h"
#include "Define.h"
#include "CCamera.h"

#define PI 3.1415926535897932384626433832795

class CBullet
{ 
	//private:
		//SDL_Texture* bullet;
	public:
		double bulletX;
		double bulletY;
		double targetX;
		double targetY;
		int targetW;
		int targetH;
		int borderX;
		int borderY;
		double TAngle;
		bool flag;
	public:
		CBullet();
		~CBullet();
		void load(int X, int Y, int Width, int Heighte, double angle);
		void render(SDL_Renderer* ren, SDL_Texture* texture);
		void collision();
		bool loop(CMap& map);
};

#endif