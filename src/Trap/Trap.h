#pragma once
const int TRAP_MAX = 10;
struct Trap
{
	int x, y, h, w, handle, trapPosX, trapPosY;
	bool IsUse;
};
void trapInit();						// 初期化
void trapStep();						// 通常
void trapDraw();						// 描画
extern Trap  trap[TRAP_MAX];