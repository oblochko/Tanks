#include "CMap.h"

//CMap CMap::MapControl;
/*SDL_Texture* CMap::texture_earth = NULL;
SDL_Texture* CMap::texture_wall = NULL;*/

vector<vector <CTile>> CMap::TileList;
vector <CTile> CMap::Help;

CMap::CMap()
{
	texture_earth = NULL;
	texture_wall = NULL;
}

bool CMap::OnLoad(void)
{
	ifstream fin("map/level1.txt");
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			CTile tempTitle;
			fin >> tempTitle.TileID;
			Help.push_back(tempTitle);
		}
		TileList.push_back(Help);
		Help.clear();
	}
	/*for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++)
	{
		CTile tempTitle;
		fin >> tempTitle.TileID;
		cout << tempTitle.TileID << endl;
		TileList.push_back(tempTitle);
	}*/
	return true;
}

bool CMap::OnLoad(const char* File)
{
	ifstream fin(File);
	//ifstream fin("map/level2.txt");
	if (!fin.is_open()) // если файл не открыт
		cout << "File not open" << endl;
	else
		cout << "File open" << endl;
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			CTile tempTitle;
			fin >> tempTitle.TileID;
			cout << tempTitle.TileID << " ";
			Help.push_back(tempTitle);
		}
		cout << endl;
		TileList.push_back(Help);
		Help.clear();
	}
	return true;
}

void CMap::OnRender(SDL_Renderer* ren, int MapX, int MapY) {
	//int ID = 0;
	//cout << "map" << endl;

	float TimeStart, TimeStop, TimeFinal;

	int dX = MapX / TILE_SIZE * TILE_SIZE;
	int dY = MapY / TILE_SIZE * TILE_SIZE;

	//int y = dY / TILE_SIZE;
	//int x = dX / TILE_SIZE;

	int SH = SCREEN_HEIGHT + dY - MapY;
	int SY = SCREEN_WIDTH + dX - MapX;

	int height = SCREEN_HEIGHT / TILE_SIZE + 1 + dY / TILE_SIZE;  // SCREEN_HEIGHT / TILE_SZIE + 1
	int width = SCREEN_WIDTH / TILE_SIZE + dX / TILE_SIZE;

	TimeStart = SDL_GetTicks();

	for (int Y = dY - MapY, y = dY / TILE_SIZE; /*Y < SH*/y < height; Y += 64, y++) {
		for (int X = dX - MapX, x = dX / TILE_SIZE; /*X < SY*/ x < width; X += 64, x++) {
			/*if (TileList[ID].TileID == TILE_TYPE_NONE) {
				ID++;
				continue;
			}*/
			//TileList[y][x].OnDraw_Rend(ren, X, Y);
			//cout << TileList[y][x].TileID << " ";
			tile_draw(ren, TileList[y][x].TileID, X, Y);
		}
		//cout << endl;
		//cout << "line draw" << endl;
		//y++;
	}
	//cout << endl << endl << endl;

	TimeStop = SDL_GetTicks();

	TimeFinal = TimeStop - TimeStart;
	//cout << "current render time "  << TimeFinal << endl;
}

int CMap::GetTileType(float cX, float cY)
{
	/*int X = cX / TILE_SIZE;
	int Y = cY / TILE_SIZE;

	int ID = X + Y * MAP_WIDTH;
	int K = TileList[ID].TileID;
	printf("%d", K);
	return TileList[ID].TileID;*/
	return 3;
}


int CMap::GetTileID(float cX, float cY)
{
	/*int X = cX / TILE_SIZE;
	int Y = cY / TILE_SIZE;

	int ID = X + Y * MAP_WIDTH;
	return ID;*/
	return 3;
}

void CMap::vectorShow()
{
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			cout << TileList[i][j].TileID << " ";
		}
		cout << endl;
		Help.clear();
	}
}

void CMap::texture_Load(SDL_Renderer* ren)
{
	texture_earth = CSurface::onLoad("texture/loka/earth.bmp", ren);
	texture_wall = CSurface::onLoad("texture/loka/wall.bmp", ren);
}

void CMap::tile_draw(SDL_Renderer* ren, int ID, int X, int Y)
{
	switch (ID)
	{
	case 0: CSurface::onDraw(ren, texture_earth, X, Y, TILE_SIZE); break;
		
	case 1: CSurface::onDraw(ren, texture_wall, X, Y, TILE_SIZE); break;

	}
}

void CMap::writeToFile()
{
	ofstream fout("map/generatorGlobal.txt", ios_base::trunc);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			fout << TileList[i][j].TileID << " ";
		}
		fout << endl;
	}
	fout.close();
}