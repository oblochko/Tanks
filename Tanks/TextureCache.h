#ifndef _TEXTURECACHE_H_
#define _TEXTURECACHE_H_

#include <iostream>
#include <map>
#include <string>

#include <SDL.h>

#include "CSurface.h"

using namespace std;

class TextureCache
{
	private:
		map <int, string> loadBlock;
	private:
		SDL_Texture* text_wall;
		SDL_Texture* text_earth;
		SDL_Texture* text_IS1;
		SDL_Texture* text_IS1Hull;
		SDL_Texture* text_IS1Turret;
		SDL_Texture* text_bullet;
		SDL_Texture* text_Tiger2;
		SDL_Texture* text_Tiger2Hull;
		SDL_Texture* text_Tiger2Turret;
	public:
		TextureCache();
		void TileCache();
		void TileLoad(SDL_Renderer* ren);
		string ReturnString(int value);
		SDL_Texture* ReturnTexture (int value);
};

#endif
