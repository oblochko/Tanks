#include "RedactorMap.h"

RMap::RMap()
{
	int TipyTile = -1;

	win = NULL;
	ren = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Can't init SDL: " << SDL_GetError() << endl;
	}

	//win = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	win = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL) {
		cout << "Can't create window: " << SDL_GetError() << endl;
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (ren == NULL) {
		cout << "Can't create renderer: " << SDL_GetError() << endl;
	}

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0xFF);

	cout << "Init Good" << endl;
}

void RMap::create()
{
	load();
	bool run = true;
	SDL_Event event;
	while (run)
	{
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT /*|| event.key.keysym.sym == SDLK_ESCAPE*/)
			{
				cout << run << endl;
				map.writeToFile();
				run = false;
			}
			else
				eventsMoues(event);
		}
		render();
		SDL_RenderPresent(ren);
	}
	cout << endl << run << endl;
}

void RMap::eventsMoues(SDL_Event& event)
{
	
	switch (event.type)
	{
		case SDL_KEYDOWN:
		{
			//TipyTile = -1;
			flagRMap = 0;
			switch (event.key.keysym.sym)
			{
				
				case SDLK_0: TipyTile = 0;  break;

				case SDLK_1: TipyTile = 1;  break;

				case SDLK_LEFT: camera.ChangeMap(-15, 0); flagRMap = 1;  cout << "LEFT" << endl;  break;

				case SDLK_RIGHT: camera.ChangeMap(15, 0); flagRMap = 1; cout << "RIGHT" << endl;  break;

				case SDLK_UP: camera.ChangeMap(0, -15); flagRMap = 1; cout << "UP" << endl; break;

				case SDLK_DOWN: camera.ChangeMap(0, 15); flagRMap = 1; cout << "DOWN" << endl; break;

			}
			break;
		}
		case SDL_KEYUP:
		{
			//TipyTile = -1;
			flagRMap = 0;
			switch (event.key.keysym.sym)
			{
			case SDLK_0: TipyTile = 0; break;

			case SDLK_1: TipyTile = 1; break;

			case SDLK_LEFT: camera.ChangeMap(0, 0); flagRMap = 0;  cout << "LEFT" << endl;  break;

			case SDLK_RIGHT: camera.ChangeMap(0, 0); flagRMap = 0; cout << "RIGHT" << endl;  break;

			case SDLK_UP: camera.ChangeMap(0, 0); flagRMap = 0; cout << "UP" << endl; break;

			case SDLK_DOWN: camera.ChangeMap(0, 0); flagRMap = 0; cout << "DOWN" << endl; break;

			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			cout << event.motion.x << ' ' << event.motion.y << endl;
			if (TipyTile != -1)
			{
				flagRMap = 1;
				//int ID = map.GetTileID(event.motion.x, event.motion.y);
				int x = ((int)event.motion.x + camera.GetX()) / TILE_SIZE;
				int y = ((int)event.motion.y + camera.GetY()) / TILE_SIZE;
				map.TileList[y][x].TileID = TipyTile;
				//map.TileList[y][x].OnDraw_Rend(ren, x, y);
				//cout << x << " " << y << endl;
				//map.tile_draw(ren, TipyTile, x*64, y*64);
			}
		}
		case SDL_MOUSEBUTTONUP:
		{
			//cout << event.motion.x << " " << event.motion.y << endl;
			break;
		}
		/*case SDL_MOUSEMOTION:
		{
			cout << "definer mouse " << endl;
			cout << event.motion.x << " " << event.motion.y << endl;
			break;
		}*/
	}

}

void RMap::load()
{
	tcache.TileLoad(ren);
	map.OnLoad("map/generatorGlobal.txt");
	map.texture_Load(ren);
	map.OnRender(ren, 0, 0);
	tank.tank = tcache.ReturnTexture(2);
	tank.tankHull = tcache.ReturnTexture(3);
	tank.tankTurret = tcache.ReturnTexture(4);
	tank.renderer(ren, 196 - camera.currentPointX, 117 - camera.currentPointY);
}

void RMap::render()
{
	//cout << camera.GetX() << " " << camera.GetY() << endl;
	if (flagRMap == 1)
	{
		SDL_RenderClear(ren);
		map.OnRender(ren, camera.GetX(), camera.GetY());
		tank.renderer(ren, 196 - camera.currentPointX, 117 - camera.currentPointY);
		flagRMap = 0;
	}
	else
	SDL_Delay(0.000015);	
}