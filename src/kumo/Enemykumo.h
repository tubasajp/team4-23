#pragma once
#include"DxLib.h"
const int KUMO_MAX = 1;
struct Kumo
{
	int x, y, w, h, handle,PosX,PosY;
};
void kumoInit();
void kumoDraw();
extern Kumo kumo[KUMO_MAX];