#include "Game.h"

Game::Game()
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

void Game::start()
{
	load();
	bool run = true;
	SDL_Event event;
	uint32_t previousTime = SDL_GetTicks();
	uint32_t frameSkip = 1000 / 60;
	int fps = 0;
	while (run)
	{
		if (previousTime + frameSkip < SDL_GetTicks())
		{
			previousTime = SDL_GetTicks();
			if (fps < 60) fps++;
			else fps = 0;
			//cout << fps << endl;
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT /*|| event.key.keysym.sym == SDLK_ESCAPE*/)
				{
					//cout << run << endl;
					run = false;
				}
				else
					eventsMoues(event);
			}
			loop();
			render();
			SDL_RenderPresent(ren);
		}
	}
	cout << endl << run << endl;
}

/*void Game::eventsMoues(SDL_Event& event)
{
	//player.moveHull(1, 0);
	switch (event.type)
	{
	case SDL_KEYDOWN:
	{¸	ô
		//TipyTile = -1;
		flagRMap = 0;
		switch (event.key.keysym.sym)
		{

		case SDLK_0: TipyTile = 0;  break;

		case SDLK_1: TipyTile = 1;  break;

		case SDLK_LEFT: flagRMap = 1;  cout << "LEFT" << endl;  break;

		case SDLK_RIGHT: flagRMap = 1; cout << "RIGHT" << endl;  break;

		case SDLK_UP: flagRMap = 1; cout << "UP" << endl; break;

		case SDLK_DOWN: flagRMap = 1; cout << "DOWN" << endl; break;

		case SDLK_w: player.flagVTurret = true; player.moveHull(0, -5);  break;

		case SDLK_d: player.flagGTurret = true; player.moveHull(1, 0);  break;

		case SDLK_s: player.flagVTurret = true; player.moveHull(0, 5);  break;

		case SDLK_a: player.flagGTurret = true; player.moveHull(-1, 0);  break;

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

			case SDLK_w: camera.ChangeMap(0, 0); player.flagVTurret = false; player.moveHull(0, 0);  break;

			case SDLK_d: camera.ChangeMap(0, 0); player.flagGTurret = false; player.moveHull(0, 0);  break;

			case SDLK_s: camera.ChangeMap(0, 0);  player.flagVTurret = false; player.moveHull(0, 0);  break;

			case SDLK_a: camera.ChangeMap(0, 0);  player.flagGTurret = false; player.moveHull(0, 0);  break;

		}
		break;
	}
	case SDL_MOUSEBUTTONDOWN:
	{
		cout << event.motion.x << ' ' << event.motion.y << endl;
		player.moveTurret(event.motion.x, event.motion.y);
		//cout << event.motion.x << ' ' << event.motion.y << endl;
		break;
	}
	case SDL_MOUSEBUTTONUP:
	{
		//cout << event.motion.x << " " << event.motion.y << endl;
		break;
	}
	case SDL_MOUSEMOTION:
	{
		player.moveTurret(event.motion.x, event.motion.y);
		break;
	}
	}

}*/

void Game::eventsMoues(SDL_Event& event)
{
	const  Uint8* state = SDL_GetKeyboardState(NULL);

	switch (event.type)
	{
	case SDL_KEYDOWN:
	{
		//TipyTile = -1;
		flagRMap = 0;
		if (state[SDL_SCANCODE_W]) { player.moveHullY(-5); } //player.moveTurret(event.motion.x, event.motion.y);}

		if (state[SDL_SCANCODE_D]) { player.moveHullX(1); } //player.moveTurret(event.motion.x, event.motion.y);}

		if (state[SDL_SCANCODE_A]) { player.moveHullX(-1); } //player.moveTurret(event.motion.x, event.motion.y);}

		if (state[SDL_SCANCODE_S]) { player.moveHullY(5); } //player.moveTurret(event.motion.x, event.motion.y);}

		//player.moveTurret(event.motion.x, event.motion.y);
		cout << endl;
		break;
	}
	case SDL_KEYUP:
	{
		/*if (!state[SDL_SCANCODE_W]) { player.moveHull(0, 0);  cout << "the key w is down "; }

		if (!state[SDL_SCANCODE_D]) { player.moveHull(0, 0);  cout << "the key d is down ";}

		if (!state[SDL_SCANCODE_A]) { player.moveHull(0, 0);  cout << "the key a is down "; }

		if (!state[SDL_SCANCODE_S]) { player.moveHull(0, 0);  cout << "the key s is down "; }*/

		/*if (!state[SDL_SCANCODE_W] && !state[SDL_SCANCODE_S]) { player.moveHull(0, 0);  cout << "the key w and s is down "; }

		if (!state[SDL_SCANCODE_A] && !state[SDL_SCANCODE_D]) { player.moveHull(0, 0);  cout << "the key a and d is down "; }*/

		if (!state[SDL_SCANCODE_W] && !state[SDL_SCANCODE_S]) player.moveHullY(0);

		if (!state[SDL_SCANCODE_A] && !state[SDL_SCANCODE_D]) player.moveHullX(0);

		//player.moveTurret(event.motion.x, event.motion.y);
		cout << endl;
		break;
	}
	case SDL_MOUSEBUTTONDOWN:
	{
		player.shot(event.motion.x, event.motion.y);
		//player.moveTurret(event.motion.x, event.motion.y);
		cout << event.motion.x << ' ' << event.motion.y << endl;
		break;
	}
	case SDL_MOUSEBUTTONUP:
	{
		//cout << event.motion.x << " " << event.motion.y << endl;
		break;
	}
	case SDL_MOUSEMOTION:
	{
		player.moveTurret(event.motion.x, event.motion.y, ren);
		break;
	}
	}
}

void Game::load()
{
	tcache.TileLoad(ren);
	map.OnLoad("map/generatorGlobal.txt");
	map.texture_Load(ren);
	map.OnRender(ren, 0, 0);
	/*bot.load(ren, tcache);
	bot.render(ren);*/
	player.load(ren, tcache);
	player.render(ren);
}

void Game::loop()
{
	player.loopTurret();
	if(player.collision(map))
	//player.collision(map);
		player.loopHull();
	player.loopShot(map);
}

void Game::render()
{
	//cout << camera.GetX() << " " << camera.GetY() << endl;
	//if (flagRMap == 1)
	//{
		SDL_RenderClear(ren);
		map.OnRender(ren, player.camera.GetX(), player.camera.GetY());
		player.render(ren);
		bot.render(ren);
		flagRMap = 0;
	//}
	//else
	//	SDL_Delay(0.000015);
}