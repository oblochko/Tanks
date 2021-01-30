#include "CTank.h"

CTank::CTank()
{
	tank = NULL;
	tankHull = NULL;
	tankTurret = NULL;

	Xhull = 196; 
	Yhull = 186 - 69; // -8 // 186 

	WidthHull = 150;
	HeightHull = 352 + 10 + 3; // 301

	XTurret = 13;
	YTurret = -172 + 69; // +3


	WTurret = 119; // -7
	HTurret = 580 - 6;

	center.x = Xhull + WidthHull / 2; //+ 74;
	center.y = Yhull + HeightHull / 2; //+ 117;

	angleTurret = 0;
	angleHull = 0;
	angleCollision = 0;

	flip = SDL_FLIP_NONE;
}

void CTank::load()
{
	Xhull = 196;
	Yhull = 186; // -8 // 186 

	WidthHull = 150;
	HeightHull = 297 + 12; // 301

	XTurret = 13;
	YTurret = -143 - 22; // +3

	WTurret = 113; // -7
	HTurret = 656;

	center.x = Xhull + WidthHull / 2; //+ 74;
	center.y = Yhull + HeightHull / 2; //+ 117;

	angleTurret = 0;
	angleHull = 0;
	angleCollision = 0;

	flip = SDL_FLIP_NONE;
}

//void CTank::renderer(SDL_Renderer* ren, int X, int Y)
//{
//	CSurface::onDrawEX(ren, tankHull, Xhull, Yhull, WidthHull, HeightHull, angleHull, NULL);
//	CSurface::onDrawEX(ren, tankTurret, Xhull + XTurret, Yhull + YTurret, WTurret, HTurret, angleTurret + 90, NULL);
//}

void CTank::renderer(SDL_Renderer* ren, int X, int Y)
{
	CSurface::onDrawEX(ren, tankHull, Xhull, Yhull, WidthHull, HeightHull, angleHull, NULL);
	CSurface::onDrawEX(ren, tankTurret, Xhull + XTurret, Yhull + YTurret, WTurret, HTurret, angleTurret + 90, NULL);


	//CSurface::onDraw(ren, tank, Xhull + 300, Yhull - 176 + 12, 150, 472);
}

void CTank::setCenterTurret()
{
	center.x = Xhull + WidthHull / 2; //+ 74;
	center.y = Yhull + HeightHull / 2;
}

bool CTank::collision(double X, double Y, CMap& map, CCamera& camera)
{
	setCenterTurret();
	double x1 = center.x + Y * cos((angleHull + 90 + X) * PI / 180) + 122.332 * cos((-123.69 + angleHull + X) * PI / 180) + camera.GetX();
	double y1 = center.y + Y * sin((angleHull + 90 + X) * PI / 180) + 122.332 * sin((-123.69 + angleHull + X) * PI / 180) + camera.GetY();
	double x2 = x1 + 128 * cos((0 + angleHull + X) * PI / 180);
	double y2 = y1 + 128 * sin((0 + angleHull + X) * PI / 180);
	double stepX = (x2 - x1) / 50, stepY = (y2 - y1) / 50;
	if (x1 < 0 || x1 > LEVEL_WIDTH || y1 < 0 || y1 > LEVEL_HEIGHT)
		return false;
	if (x2 < 0 || x2 > LEVEL_WIDTH || y2 < 0 || y2 > LEVEL_HEIGHT)
		return false;
	for (int i=0; i<=50; x1 += stepX, y1 += stepY, i++)
	{
		if (map.TileList[(int)(y1 / 64)][(int)(x1 / 64)].TileID == 1)
		{
			Y = 0;
			//flag = false;
			return false;
		}
	}
	x1 = center.x + Y * cos((angleHull + 90 + X) * PI / 180) + 122.332 * cos((-123.69 + angleHull + X) * PI / 180) + camera.GetX();
	y1 = center.y + Y * sin((angleHull + 90 + X) * PI / 180) + 122.332 * sin((-123.69 + angleHull + X) * PI / 180) + camera.GetY();
	x2 = x1 + 255 * cos((90 + angleHull + X) * PI / 180);
	y2 = y1 + 255 * sin((90 + angleHull + X) * PI / 180);
	stepX = (x2 - x1) / 250; stepY = (y2 - y1) / 250;
	if (x2 < 0 || x2 > LEVEL_WIDTH || y2 < 0 || y2 > LEVEL_HEIGHT)
		return false;
	for (int i = 0; i < 250; x1 += stepX, y1 += stepY, i++)
	{
		if (map.TileList[(int)(y1 / 64)][(int)(x1 / 64)].TileID == 1)
		{
			X = 0;
			//flag = false;
			return false;
		}
	}
	x1 = center.x + Y * cos((angleHull + 90 + X) * PI / 180) + 163.049 * cos((68.7859 + angleHull + X) * PI / 180) + camera.GetX();
	y1 = center.y + Y * sin((angleHull + 90 + X) * PI / 180) + 163.049 * sin((68.7859 + angleHull + X) * PI / 180) + camera.GetY();
	x2 = x1 + 255 * cos((-90 + angleHull + X) * PI / 180);
	y2 = y1 + 255 * sin((-90 + angleHull + X) * PI / 180);
	stepX = (x2 - x1) / 250; stepY = (y2 - y1) / 250;
	if (x1 < 0 || x1 > LEVEL_WIDTH || y1 < 0 || y1 > LEVEL_HEIGHT)
		return false;
	if (x2 < 0 || x2 > LEVEL_WIDTH || y2 < 0 || y2 > LEVEL_HEIGHT)
		return false;
	for (int i = 0; i < 250; x1 += stepX, y1 += stepY, i++)
	{
		if (map.TileList[(int)(y1 / 64)][(int)(x1 / 64)].TileID == 1)
		{
			X = 0;
			//flag = false;
			return false;
		}
	}
	x1 = center.x + Y * cos((angleHull + 90 + X) * PI / 180) + 163.049 * cos((68.7859 + angleHull + X) * PI / 180) + camera.GetX();
	y1 = center.y + Y * sin((angleHull + 90 + X) * PI / 180) + 163.049 * sin((68.7859 + angleHull + X) * PI / 180) + camera.GetY();
	x2 = x1 + 128 * cos((180 + angleHull + X) * PI / 180);
	y2 = y1 + 128 * sin((180 + angleHull + X) * PI / 180);
	stepX = (x2 - x1) / 50; stepY = (y2 - y1) / 50;
	if (x2 < 0 || x2 > LEVEL_WIDTH || y2 < 0 || y2 > LEVEL_HEIGHT)
		return false;
	for (int i = 0; i <= 50; x1 += stepX, y1 += stepY, i++)
	{
		if (map.TileList[(int)(y1 / 64)][(int)(x1 / 64)].TileID == 1)
		{
			Y = 0;
			//flag = false;
			return false;
		}
	}
	return true;
} // 0x5606F2F6




//for (double ang = 0; ang < 360; ang +=30)
	//double x1 = center.x + 122.332 * cos((-123.69 + angleHull) * PI / 180);
	//double y1 = center.y + 122.332 * sin((-123.69 + angleHull) * PI / 180);
	//double x2 = center.x + 163.049 * cos((68.7859 + angleHull) * PI / 180);
	//double y2 = center.y + 163.049 * sin((68.7859 + angleHull) * PI / 180);

/*SDL_RenderDrawLine(ren, center.x, center.y, center.x + 122.332 * cos((-123.69 + angleHull)* PI / 180), center.y + 122.332 * sin((-123.69 + angleHull)* PI / 180));
	SDL_RenderDrawLine(ren, center.x, center.y, center.x + 122.332 * cos((-59.9536) * PI / 180), center.y + 122.332 * sin((-59.9536) * PI / 180));
	SDL_RenderDrawLine(ren, center.x, center.y, center.x + 165.076 * cos((71.7871) * PI / 180), center.y + 165.076 * sin((71.7871) * PI / 180));
	SDL_RenderDrawLine(ren, center.x, center.y, center.x + 163.049 * cos((68.7859 + angleHull) * PI / 180), center.y + 163.049 * sin((68.7859 + angleHull) * PI / 180));*/
	//SDL_RenderDrawLine(ren, x1, y1, x1 + 128 * cos((0 + angleHull) * PI / 180), y1 + 128 * sin((0 + angleHull) * PI / 180));
	//SDL_RenderDrawLine(ren, x1, y1, x1 + 255 * cos((90 + angleHull) * PI / 180), y1 + 255 * sin((90 + angleHull) * PI / 180));
	//SDL_RenderDrawLine(ren, x1, y1 + 255, x1 + 128 * cos((0 + angleHull) * PI / 180), y1 + 128 * sin((0 + angleHull) * PI / 180));
	//SDL_RenderDrawLine(ren, x2, y2, x2 + 255 * cos((-90 + angleHull) * PI / 180), y2 + 255 * sin((-90 + angleHull) * PI / 180));
	//SDL_RenderDrawLine(ren, x2, y2, x2 + 128 * cos((180 + angleHull) * PI / 180), y2 + 128 * sin((180 + angleHull) * PI / 180));
	//SDL_RenderDrawLine(ren, center.x, center.y, center.x + 290*cos((angleTurret)*PI/180), center.y + 290 * sin((angleTurret) * PI / 180));
	//SDL_RenderDrawLine(ren, Xhull, Yhull + HeightHull, Xhull*cos((angleHull)*PI/180), (Yhull + HeightHull)* sin(angleHull+90) * PI / 180);
	//cout << "coordinates " << x1 << " " << y1 << " next " << x1 + 128 * cos((0 + angleHull) * PI / 180) << " "  << y1 + 128 * sin((0 + angleHull) * PI / 180) << endl;
	//cout << " render " << angleHull << endl;