#ifndef _CMAP_H_
    #define _CMAP_H_

#include <SDL.h>
#include <vector>
#include <fstream>
#include <iostream>

#include "CTile.h"
#include "CCamera.h"
#include "CSurface.h"
#include "Define.h"

using namespace std;

class CMap {
	//private 
    public:
        //static CMap MapControl;

        SDL_Surface* Surf_Tileset;

		SDL_Texture* texture_wall;
		SDL_Texture* texture_earth;

    public:
        static std::vector<vector <CTile>> TileList;
		static vector <CTile> Help;
    public:
        CMap();

    public:
        bool OnLoad(void);
        bool OnLoad(const char* File);
        //void OnRender(SDL_Surface* Surf_Display, int MapX, int MapY);
        void OnRender(SDL_Renderer* ren, int MapX, int MapY);

        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);

        int GetTileType (float cX, float cY);
        int GetTileID (float cX, float cY);
        void vectorShow ();

		void texture_Load(SDL_Renderer* ren);
		void tile_draw(SDL_Renderer* ren, int ID, int X, int Y);

		void writeToFile();
};

#endif

