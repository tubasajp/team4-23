#pragma once
#include"DxLib.h"

class PlaySceen
{
public:
	void Character_Hit_Map();
	void Character_Hit_Trap();
	void Character_Hit_Goal();
	void Character_Hit_Enemykumo();
	void Map_erase();	//ƒ}ƒbƒv‚ğÁ‚·
	void Step();
};
extern PlaySceen playSceen;