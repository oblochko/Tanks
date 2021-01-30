#ifndef _CTILE_H_
#define _CTILE_H_

#include <iostream>
#include <map>
#include <string>

#include <SDL.h>

#include "CSurface.h"
#include "TextureCache.h"
//#include "CMap.h"

using namespace std;

enum
{
	TILE_TYPE_NONE = 0,

	TILE_TYPE_WALL,
	TILE_TYPE_BOX,
	TILE_TYPE_FINISHPOINT
};

class CTile {
public:
	int     TileID;
public:
	CTile();
	bool OnDraw_Rend(SDL_Renderer* ren, int X, int Y);
};

#endif
