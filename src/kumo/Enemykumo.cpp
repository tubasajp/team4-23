#include"DxLib.h"
#include"Enemykumo.h"
#include"../Character/Character.h"
Kumo kumo[KUMO_MAX];
void kumoInit()
{
	kumo[0].PosX = 1200;
	kumo[0].PosY = 300;
	for (int i = 0; i < KUMO_MAX; i++)
	{
		kumo[i].x = kumo[i].PosX;
		kumo[i].y = kumo[i].PosY;
		kumo[i].handle = LoadGraph("Data/TitleImage/cloud1.png");
	}
	
}
void kumoDraw()
{
	for (int i = 0; i < KUMO_MAX; i++)
	{
		DrawRotaGraph(kumo[i].x - character.GetScreenX(), kumo[i].y - character.GetScreenY(), 2.0f, 0.0f, kumo[i].handle,true);
	}
	
}