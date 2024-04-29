#pragma once
#include"DxLib.h"
class CLEAR
{
	int x, y, handle;
	int namex,namey,namehandle;

	int soundhandle;
public:
	void Init();
	void Draw();
};
extern CLEAR Clear;