#pragma once
const int TRAP_MAX = 50;
struct Trap
{
	int x, y, h, w, handle, trapPosX, trapPosY,Framecount;
	float Rota, Size;
	bool IsUse,sitaIsMove, ueIsMove, hidariIsMove, migiIsMove, Once_again;
};
void trapInit();						// ‰Šú‰»
void trapStep();						// ’Êí
void trapDraw();						// •`‰æ
void TrapMove();
extern Trap  trap[TRAP_MAX];