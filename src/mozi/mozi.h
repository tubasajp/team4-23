#pragma once
#include"DxLib.h"
class Mozi
{
	int x, y, handle,Framecount;
	bool IsUse;
public:
	void Init();
	void Step();
	void Draw();
};
extern Mozi mozi;