#ifndef _CCAMERA_H_
#define _CCAMERA_H_

#include "CMap.h"
#include "Define.h"
#define PI 3.1415926535897932384626433832795

class CCamera
{
	public:
		static int currentPointX;
		static int currentPointY;
	private:
		int indentX;
		int indentY;
	public:
		CCamera();
		void ChangeMap(int x, int y); 
		void ChangeMap(int x, int y, double angle);
		//void renderingMap(SDL_Renderer* ren);
		static int GetX();
		static int GetY();
};

#endif
