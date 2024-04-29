#include"DxLib.h"
#include"../MapChipGoal/MapChipGoal.h"
#include"../Character/Character.h"
Goal goal;
void Goal::Init()
{
	x = 3136;
	y = 896;
	h = 32;
	w = 32;
	handle = LoadGraph("Data/Map/Goal.png");
}
void Goal::Draw()
{
	DrawGraph(x-character.GetScreenX(), y - character.GetScreenY(), handle, true);
}