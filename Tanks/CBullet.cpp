#include "CBullet.h"

CBullet::CBullet()
{
	bulletX = 0;
	bulletY = 0;
	targetX = 0;
	targetY = 0;
	targetW = 0;
	targetH = 0;
	TAngle = 0;
	flag = true;
}

CBullet::~CBullet()
{

}

void CBullet::load(int X, int Y, int Width, int Height, double angle)
{
	targetX = X;
	targetY = Y;
	targetW = Width;
	targetH = Height;
	TAngle = angle;
	bulletX = CCamera::GetX();
	bulletY = CCamera::GetY();
}

void CBullet::render(SDL_Renderer* ren, SDL_Texture* texture)
{
	CSurface::onDrawEX(ren, texture, targetX + bulletX - CCamera::GetX(), targetY + bulletY - CCamera::GetY(), targetW, targetH, TAngle, NULL);
}

bool CBullet::loop(CMap& map)
{
	if (targetX < 0 || targetX > LEVEL_WIDTH || targetY < 0 || targetY > LEVEL_HEIGHT) return false;
	if (map.TileList[(targetY + bulletY) / 64][(targetX + bulletX) / 64].TileID == 1)
	{
		map.TileList[(targetY + bulletY) / 64][(targetX + bulletX) / 64].TileID = 0;
		//map.vectorShow();
		return false;
	}
	else
	{
		targetX += 10 * cos((TAngle)* PI / 180);
		targetY += 10 * sin((TAngle)* PI / 180);
		return true;
	}
}

void CBullet::collision()
{
	/*double dx = 64 - (targetX - targetX / TILE_SIZE * TILE_SIZE);
	double dy = targetY - targetY / TILE_SIZE * TILE_SIZE;
	double xIntercent = targetX + dx + dy / tan(TAngle);
	double yIntercent = targetY + dy + dx / tan(TAngle);
	while (yIntercent < LEVEL_WIDTH || yIntercent > 0)
	{
		if (CMap::TileList[][].TileID == 1) break;

	}
	while (xIntercent < LEVEL_HEIGHT || yIntercent > 0)
	{
		if (CMap::TileList[][].TileID == 1) break;
	}*/
}