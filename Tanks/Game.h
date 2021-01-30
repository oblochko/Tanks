#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>

#include "CMap.h"
#include "CSurface.h"
#include "CCamera.h"
#include "TextureCache.h"
#include "CTank.h"
#include "CPlayer.h"
#include "Define.h"
#include "CBot.h"

class Game
{
	private:
		CMap map;
		//CCamera camera;
		TextureCache tcache;
		CPlayer player;
		CBot bot;
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
	private:
		int TipyTile;
		bool flagRMap;
	public:
		Game();
		void start();
	private:
		void eventsMoues(SDL_Event& event);
		void load();
		void loop();
		void render();
};

#endif