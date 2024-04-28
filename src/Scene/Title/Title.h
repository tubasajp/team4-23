#pragma once
#include"DxLib.h"
class Title
{
private :
	int x, y, handle;
public:
	void InitTitle();
	void DrawTitle();
};
extern Title title;