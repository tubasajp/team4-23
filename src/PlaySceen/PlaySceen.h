#pragma once
#include"DxLib.h"

class PlaySceen
{
public:
	void Character_Hit_Map();
	void Character_Hit_Trap();
	void Character_Hit_Goal();
	void Map_erase();	//マップを消す
	void Step();
};
extern PlaySceen playSceen;