#include <iostream>
#include <fstream>

#include <SDL.h>

#include "CMap.h"
#include "CSurface.h"
#include "CCamera.h"
#include "TextureCache.h"
#include "CTank.h"
#include "Define.h"

class RMap
{
	private:
		CMap map;
		CCamera camera;
		TextureCache tcache;
		CTank tank;
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
	private:
		int TipyTile;
		bool flagRMap;
	public:
		RMap();
		void create();
		void eventsMoues(SDL_Event& event);
		//void drawTile(float X, float Y);
		void load();
		void render();
}; 
