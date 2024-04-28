#include "Trap.h"
#include <DXLib.h>
#include"../Character/Character.h"
Trap  trap[TRAP_MAX];

void trapInit()
{ 
	for (int i = 0; i < TRAP_MAX; i++)
	{																		   //3番目は横画像
		trap[0].trapPosX = 448, trap[1].trapPosX = 576, trap[2].trapPosX = 768, trap[3].trapPosX = 1024, trap[4].trapPosX = 448, trap[5].trapPosX = 608, trap[6].trapPosX = 768, trap[7].trapPosX = 960, trap[8].trapPosX = 1279, trap[9].trapPosX = 1311, trap[10].trapPosX =1343, trap[11].trapPosX = 1375;
		trap[0].trapPosY = 608, trap[1].trapPosY = 608, trap[2].trapPosY = 608, trap[3].trapPosY = 640, trap[4].trapPosY = 384, trap[5].trapPosY = 384, trap[6].trapPosY = 384, trap[7].trapPosY = 384, trap[8].trapPosY = 896, trap[9].trapPosY = 896, trap[10].trapPosY = 896, trap[11].trapPosY = 896;
		trap[i].x = trap[i].trapPosX;
		trap[i].y = trap[i].trapPosY;
		trap[i].handle = LoadGraph("Data/Map/トゲ.png");
		trap[i].h = 32;
		trap[i].w = 32;
		trap[i].IsUse = true;
		trap[i].sitaIsMove = false;	//下から上
		trap[i].ueIsMove = false;	//上から下
		trap[i].hidariIsMove = false;//左から右
		trap[i].migiIsMove = false;	 //右から左

	}
}

void trapStep()
{

}
void trapDraw()
{
	for (int i = 0; i < TRAP_MAX; i++)
	{
		if (trap[i].IsUse == true)
		{
			DrawGraph(trap[i].x - character.GetScreenX(), trap[i].y - character.GetScreenY(), trap[i].handle, true);
		}
		
	}
	
}
void TrapMove()
{
	if (character.GetPosX() > 1290 && character.GetPosX() < 1400 && character.GetPosY() < 630)
	{
		DrawFormatString(100, 220, GetColor(255, 0, 0), "来るぞー");
		trap[8].sitaIsMove = true, trap[9].sitaIsMove = true, trap[10].sitaIsMove = true, trap[11].sitaIsMove = true;
	}
	for (int i = 0; i < TRAP_MAX; i++)
	{
		if (trap[i].sitaIsMove == true)
		{
			trap[i].y -= 20;
		}
	}
}
