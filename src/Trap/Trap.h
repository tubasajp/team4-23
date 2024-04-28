#pragma once
const int TRAP_MAX = 15;
struct Trap
{
	int x, y, h, w, handle, trapPosX, trapPosY;
	bool IsUse,sitaIsMove, ueIsMove, hidariIsMove, migiIsMove;
};
void trapInit();						// ‰Šú‰»
void trapStep();						// ’Êí
void trapDraw();						// •`‰æ
void TrapMove();
extern Trap  trap[TRAP_MAX];