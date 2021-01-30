#include "CTile.h"

CTile::CTile() {
	TileID = 0;
	//TileCache();
}

bool CTile::OnDraw_Rend(SDL_Renderer* ren, int X, int Y)
{
	/*//cout << X << " " << Y << endl;
	TextureCache TCache;
	SDL_Texture* texture;
	int x = X , y = Y;
	string str;
	
	/*switch (TileID)
	{
	case 0: str = loadBlock[0]; break;
	case 1: str = loadBlock[1]; break;
	case 2: str = loadBlock[2]; break;
	case 3: str = loadBlock[3]; break;
	case 4: str = loadBlock[4]; break;
	}*
	//str = TCache.ReturnString(TileID);
	if (TileID == 0)
	{
		//texture = texture_earth;
		//str = "texture/loka/RBox.bmp";
	}
	else
	{
		//texture = texture_wall;
		//str = "texture/loka/BBox.bmp";
	}

	CSurface::onDraw(ren, texture, x, y, 64);

	SDL_DestroyTexture(texture);

	//SDL_Surface* Surf_Dest = SDL_LoadBMP(str.c_str());

	//SDL_BlitSurface(Surf_Dest, NULL, Surf_Src, &DestR);

	//SDL_Flip(Surf_Src);

	return true;*/
	return NULL;

}


