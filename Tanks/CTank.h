#ifndef _CTANK_H_
#define _CTANK_H_

#include <iostream>
#include <fstream>

#include <SDL.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795

#include "TextureCache.h"
#include "CMap.h"
#include "CCamera.h"
#include "Define.h"

class CTank
{	
	public:
		SDL_Texture* tank;
		SDL_Texture* tankHull;
		SDL_Texture* tankTurret;
	public:
		//bool flag = true;
		double Xhull;
		double Yhull;

		double WidthHull;
		double HeightHull;

		int XTurret;
		int YTurret;

		int WTurret;
		int HTurret;

		SDL_Point center;

		double angleTurret;
		double angleHull;
		double angleCollision;

		SDL_RendererFlip flip;
	public:
		CTank();
		//void LoadImg();
		void load();
		void renderer(SDL_Renderer* ren, int X, int Y);
		void setCenterTurret();
		bool collision(double X, double Y, CMap& map, CCamera& camera);
};

#endif