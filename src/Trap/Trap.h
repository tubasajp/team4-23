#pragma once
const int TRAP_MAX = 15;
struct Trap
{
	int x, y, h, w, handle, trapPosX, trapPosY;
	bool IsUse,sitaIsMove, ueIsMove, hidariIsMove, migiIsMove;
};
void trapInit();						// 初期化
void trapStep();						// 通常
void trapDraw();						// 描画
void TrapMove();
extern Trap  trap[TRAP_MAX];