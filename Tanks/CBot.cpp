#include "CBot.h"

void CBot::load(SDL_Renderer* ren, TextureCache& tcache)
{
	tank.tank = tcache.ReturnTexture(6);
	tank.tankHull = tcache.ReturnTexture(7);
	tank.tankTurret = tcache.ReturnTexture(8);
	bullet = tcache.ReturnTexture(5);
	tank.load();
}

void CBot::render(SDL_Renderer* ren)
{
	tank.renderer(ren, 0, 0);
	for (auto& bull : Vbullet)
	{
		bull.render(ren, bullet);
	}
}

bool CBot::collision(CMap& map)
{
	//return tank.collision(defX, defY, map, camera);
	return true;
}

void CBot::help()
{
	/*if (angle < 90) angle += 90;
	else angle -= 270;*/
	if (tank.angleTurret > 180)
	{
		tank.angleTurret -= 180;
		tank.angleTurret = -180 - tank.angleTurret;
	}
	if (tank.angleTurret < -180)
	{
		tank.angleTurret += 180;
		tank.angleTurret = 180 + tank.angleTurret;
	}
	/*if (angle < 90)
	{
		angle *= -1;
		angle += 180;
	}*/
}