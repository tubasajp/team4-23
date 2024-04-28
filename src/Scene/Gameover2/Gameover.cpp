#include"../Gameover/Gameover.h"
#include"../Scene.h"
#include"DxLib.h"

Gameover gameover;
void Gameover::Init()
{
	x = 0;
	y = 0;
	handle = LoadGraph("Data/TitleImage/BackGround.png");
}
void Gameover::Draw()
{
	DrawGraph(x, y, handle, true);
}
