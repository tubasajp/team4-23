#pragma once
#include"DxLib.h"
class Goal
{
	int x, y, w, h,handle;
private:
	
public:
	void Init();
	void Draw();
	int GetX() { return x; }
	int GetY() { return y; }
	int GetH() { return h; }
	int GetW() { return w; }
};
extern Goal goal;
