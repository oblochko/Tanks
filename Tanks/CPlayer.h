#ifndef _CPLAYER_H_
#define _CPLAYER_H_

#include <SDL.h>
#include <list>

#define PI 3.1415926535897932384626433832795

#include <cmath>

#include "CTank.h"
#include "CBullet.h"
#include "CMap.h"
#include "CCamera.h"

class CPlayer
{
	private:
		list <CBullet> Vbullet;
	private:
		SDL_Texture* bullet;
	private:
		CTank tank;
	public:
		CCamera camera;
	private:
		double deltaX = 0;
		double deltaY = 0;
		double defX = 0;
		double defY = 0;
		double angle = 0;
		int delayBeforeFiring = 0;
	private:
		bool flagTurret = false;
	public:
		bool flagVTurret = false;
		bool flagGTurret = false;
	public:
		void load(SDL_Renderer* ren, TextureCache& tcache);
		void moveTurret(double X, double Y, SDL_Renderer* ren);
		void loopTurret();
		void moveHull(int X, int Y);
		void moveHullX(int X);
		void moveHullY(int Y);
		void shot(int X, int Y);
		void loopShot(CMap& map);
		void loopHull();
		void render(SDL_Renderer* ren);
		bool collision(CMap& map);
		void help();
};

#endif 