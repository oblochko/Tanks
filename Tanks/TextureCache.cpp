#include "TextureCache.h"

TextureCache::TextureCache()
{
	text_wall = NULL;
	text_earth = NULL;
	text_IS1 = NULL;
	text_IS1Hull = NULL;
	text_IS1Turret = NULL;
	text_bullet = NULL;
	text_Tiger2 = NULL;
	text_Tiger2Hull = NULL;
	text_Tiger2Turret = NULL;
}

void TextureCache::TileCache()
{
	loadBlock[1] = "texture/loka/wall.bmp";
	loadBlock[0] = "texture/loka/earth.bmp";
	loadBlock[2] = "texture/tanks/IS1.bmp";
	loadBlock[3] = "texture/tanks/IS1HullV2.bmp";
	loadBlock[4] = "texture/tanks/IS1TurretV2.bmp";
	loadBlock[5] = "texture/tanks/bullet.bmp";
	loadBlock[6] = "texture/tanks/Tiger2.bmp";
	loadBlock[7] = "texture/tanks/Tiger2Hull.bmp";
	loadBlock[8] = "texture/tanks/Tiger2Turret.bmp";
}

string TextureCache::ReturnString(int value)
{
	return loadBlock[value];
}

void TextureCache::TileLoad(SDL_Renderer* ren)
{
	text_wall = CSurface::onLoad("texture/loka/wall.bmp", ren);
	text_earth = CSurface::onLoad("texture/loka/earth.bmp", ren);
	text_IS1 = CSurface::onLoad("texture/tanks/IS1.bmp", ren);
	text_IS1Hull = CSurface::onLoad("texture/tanks/IS1HullV2.bmp", ren);
	text_IS1Turret = CSurface::onLoad("texture/tanks/IS1TurretV2.bmp", ren);
	text_bullet = CSurface::onLoad("texture/tanks/bullet.bmp", ren);
	text_Tiger2 = CSurface::onLoad("texture/tanks/Tiger2.bmp", ren);
	text_Tiger2Hull = CSurface::onLoad("texture/tanks/Tiger2Hull.bmp", ren);
	text_Tiger2Turret = CSurface::onLoad("texture/tanks/Tiger2Turret.bmp", ren);
}

SDL_Texture* TextureCache::ReturnTexture(int value)
{
	switch (value)
	{
		case 1: return text_wall;

		case 0: return text_earth;

		case 2: return text_IS1;

		case 3: return text_IS1Hull;

		case 4: return text_IS1Turret;

		case 5: return text_bullet;

		case 6: return text_Tiger2;

		case 7: return text_Tiger2Hull;

		case 8: return text_Tiger2Turret;

		default:
			break;
	}
}