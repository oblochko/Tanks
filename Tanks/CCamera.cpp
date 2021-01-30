#include "CCamera.h"

int CCamera::currentPointX;
int CCamera::currentPointY;

CCamera::CCamera()
{
	currentPointX = 0;
	currentPointY = 0;

	indentX = 0;
	indentY = 0;
}

void CCamera::ChangeMap(int x, int y)
{
	//y = 9;
	//if ( )
	cout << x << " " << y << endl;
	if (!(currentPointX + x < 0 || currentPointX + x > LEVEL_WIDTH - SCREEN_WIDTH))
		currentPointX += x;
	if (!(currentPointY + y < 0 || currentPointY + y > LEVEL_HEIGHT - SCREEN_HEIGHT))
		currentPointY += y;

	int dX = (int)currentPointX / TILE_SIZE * TILE_SIZE;
	int dY = (int)currentPointY / TILE_SIZE * TILE_SIZE;

	indentX = dX - currentPointX;
	indentY = dY - currentPointY;
}

void CCamera::ChangeMap(int x, int y, double angle)
{
	/*angle += x;
	currentPointY += y * sin((angle + 90) * PI / 180);
	currentPointX += y * cos((angle + 90) * PI / 180);*/
	//if (!(currentPointX + x < 0 || currentPointY + y < 0))
	//	if (!(currentPointX + x > LEVEL_WIDTH - SCREEN_WIDTH || currentPointY + y >= LEVEL_HEIGHT - SCREEN_HEIGHT))
	//	{
	//		currentPointX += x;
	//		currentPointY += y;
	//		/*angle += x;
	//		currentPointY += y * sin((angle + 90) * PI / 180);
	//		currentPointX += y * cos((angle + 90) * PI / 180);*/
	//	}
	if (!(currentPointX + x < 0 && currentPointX + x > LEVEL_WIDTH - SCREEN_WIDTH))
		currentPointX += x;
	if (!(currentPointY + y < 0 && currentPointY + y >= LEVEL_HEIGHT - SCREEN_HEIGHT))
		currentPointX += y;

	int dX = (int)currentPointX / TILE_SIZE * TILE_SIZE;
	int dY = (int)currentPointY / TILE_SIZE * TILE_SIZE;

	indentX = dX - currentPointX;
	indentY = dY - currentPointY;
}

/*void CCamera::renderingMap(SDL_Renderer* ren, float X)
{
	
}*/

int CCamera::GetX()
{
	return currentPointX;
}

int CCamera::GetY()
{
	return currentPointY;
}

