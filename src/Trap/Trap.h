#pragma once
const int TRAP_MAX = 10;
struct Trap
{
	int x, y, h, w, handle, trapPosX, trapPosY;
	bool IsUse;
};
void trapInit();						// ‰Šú‰»
void trapStep();						// ’Êí
void trapDraw();						// •`‰æ
extern Trap  trap[TRAP_MAX];