#pragma once

struct Trap
{
	int x, y, h, w, handle;
	bool IsUse;
};
void Init();						// 初期化
void Step();						// 通常
void Draw();						// 描画