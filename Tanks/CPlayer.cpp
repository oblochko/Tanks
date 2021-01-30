#include "CPlayer.h"

void CPlayer::load(SDL_Renderer* ren, TextureCache& tcache)
{
	tank.tank = tcache.ReturnTexture(2);
	tank.tankHull = tcache.ReturnTexture(3);
	tank.tankTurret = tcache.ReturnTexture(4);
	bullet = tcache.ReturnTexture(5);
}

void CPlayer::moveHull(int X, int Y)
{
	defX = X;
	defY = Y;
	/*if (defX < 3 && defX > -3)
	{
		//cout << "X = " << X;
		if (X == 0)
		{
			if (defX == 1 || defX == -1) defX = 0;
			if (defX > 0)
				moveHull(-1, 0);
			if (defX < 0)
				moveHull(1, 0);
		}
		else
			defX += X;
	}
	else
	{
		if (defX > 0)
			defX = 1;
		else
			defX = -1;
	}*/
	//tank.angleHull += defX;
}

void CPlayer::moveHullX(int X)
{
	defX = X;
}

void CPlayer::moveHullY(int Y)
{
	defY = Y;
}

void CPlayer::moveTurret(double X, double Y, SDL_Renderer* ren)
{
	deltaX = X;
	deltaY = Y;
	flagTurret = true;
	tank.setCenterTurret();
	
}

void CPlayer::shot(int X, int Y)
{
	if (SDL_GetTicks() > delayBeforeFiring + 3000)
	{
		tank.setCenterTurret();
		/*cout << (atan2(Y - tank.center.y, X - tank.center.x) * 180) / PI << endl;
		cout << sqrt((X - tank.center.x) * (X - tank.center.x) + (Y - tank.center.y) * (Y - tank.center.y)) << endl;
		cout << (atan2(197-452, 0) * 180) / PI << " " << sqrt((197 - 452) * (197 - 452)) << endl;*/
		delayBeforeFiring = SDL_GetTicks();
		CBullet bullet;
		bullet.load(tank.center.x + 290 * cos((tank.angleTurret) * PI / 180), tank.center.y + 290 * sin((tank.angleTurret) * PI / 180), 15, 30, tank.angleTurret);
		Vbullet.push_back(bullet);
	}
}

void CPlayer::loopShot(CMap& map)
{
	int i = 0;
	/*for (auto bull : Vbullet)
	{
		if (!((*bull)->loop(map)))
		{
			bull = Vbullet.erase(bull);
		}
		else
			bull++
	}*/
	for (auto it = Vbullet.begin(); it != Vbullet.end();)
	{
		if (!((*it).loop(map)))
		{
			it = Vbullet.erase(it);
		}
		else
			it++;
	}
	/*for (int i = 0; i < Vbullet.size(); i++)
	{
		Vbullet[i].loop(map);
	}*/
}

void CPlayer::loopTurret()
{
	if (flagTurret == true || flagTurret == false)
	{
		double finalX, finalY;
		finalX = deltaX - tank.center.x;
		finalY = deltaY - tank.center.y;
		angle = (atan2(finalY, finalX) * 180) / PI;
		//cout << angle << " " << tank.angleTurret << endl;
		help();
		if (tank.angleTurret > 0)
		{
			if (tank.angleTurret > angle && angle > tank.angleTurret - 180)
			{
				//cout << "1" << endl;
				if (abs(angle - tank.angleTurret) < 3)
					tank.angleTurret = angle;
				else
					tank.angleTurret -= 1;
			}
			else
			{
				//cout << "2" << endl;
				if (abs(angle - tank.angleTurret) < 3)
					tank.angleTurret = angle;
				else
				{
					if (tank.angleTurret < 179)
						tank.angleTurret += 1;
					else
						tank.angleTurret = -179;

				}
			}
		}
		else
		{
			if (tank.angleTurret < angle && angle < tank.angleTurret + 180)
			{
				//cout << "3" << endl;
				if (abs(angle - tank.angleTurret) < 3)
					tank.angleTurret = angle;
				else
					tank.angleTurret += 1;
			}
			else
			{
				//cout << "4" << endl;
				if (abs(tank.angleTurret - angle) < 3)
					tank.angleTurret = angle;
				else
					tank.angleTurret -= 1;
			}
			help();
		}
		flagTurret = false;
	}

}

void CPlayer::loopHull()
{
	//cout << defX << endl;
	/*if (defX > 1) defX = 1;
	if (defX < -1) defX = -1;
	if (defY > 5) defY = 5;
	if (defY < -5) defY = -5;*/
	tank.angleHull += defX;
	tank.Yhull += defY* sin((tank.angleHull + 90) *PI/180);
	tank.Xhull += defY * cos((tank.angleHull + 90) *PI/180);
	camera.ChangeMap(defY * cos((tank.angleHull + 90) * PI / 180), defY * sin((tank.angleHull + 90) * PI / 180));
	cout << defY * sin((tank.angleHull + 90) * PI / 180) << " " << defY * cos((tank.angleHull + 90) * PI / 180) << endl;
	//camera.ChangeMap(defX, defY, tank.angleHull);
	//cout << sin(60 * PI / 180) << " " << cos((60) * PI / 180) << endl;
}

void CPlayer::help()
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

bool CPlayer::collision(CMap& map)
{
	return tank.collision(defX, defY, map, camera);
}

void CPlayer::render(SDL_Renderer* ren)
{
	tank.renderer(ren, 0, 0);
	for (auto& bull : Vbullet)
	{
		bull.render(ren, bullet);
	}
	/*for (auto it = Vbullet.begin(); it != Vbullet.end(); it++)
	{
		it.render(ren, it);
	}*/

	//SDL_RenderDrawLine(ren, tank.center.x, tank.center.y, tank.center.x + 1000 * cos((tank.angleTurret) * PI / 180), tank.center.y + 1000 * sin((tank.angleTurret) * PI / 180));
}