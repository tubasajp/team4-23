#include "Trap.h"
#include <DXLib.h>
#include"../Character/Character.h"
Trap  trap[TRAP_MAX];
bool a = false;
void trapInit()
{ 
	for (int i = 0; i < TRAP_MAX; i++)
	{																		   //3番目は横画像																																																																																																																																																							//27以降はドット絵		
		trap[0].trapPosX = 448, trap[1].trapPosX = 576, trap[2].trapPosX = 768, trap[3].trapPosX = 1024, trap[4].trapPosX = 448, trap[5].trapPosX = 608, trap[6].trapPosX = 768, trap[7].trapPosX = 960, trap[8].trapPosX = 1279, trap[9].trapPosX = 1311, trap[10].trapPosX = 1343, trap[11].trapPosX = 1375, trap[12].trapPosX = 2112, trap[13].trapPosX = 2144, trap[14].trapPosX = 2172, trap[15].trapPosX = 2560, trap[16].trapPosX = 2560, trap[17].trapPosX = 2560, trap[18].trapPosX = 2432, trap[19].trapPosX = 2466, trap[20].trapPosX = 2496, trap[21].trapPosX = 2528, trap[22].trapPosX = 2496, trap[23].trapPosX = 2560, trap[24].trapPosX = 2560, trap[25].trapPosX = 2560, trap[26].trapPosX = 2560, trap[27].trapPosX =2656 ;
		trap[0].trapPosY = 608, trap[1].trapPosY = 608, trap[2].trapPosY = 608, trap[3].trapPosY = 640, trap[4].trapPosY = 384, trap[5].trapPosY = 384, trap[6].trapPosY = 384, trap[7].trapPosY = 384, trap[8].trapPosY = 896, trap[9].trapPosY = 896, trap[10].trapPosY = 896, trap[11].trapPosY = 896, trap[12].trapPosY = 642, trap[13].trapPosY = 642, trap[14].trapPosY = 642, trap[15].trapPosY = 576, trap[16].trapPosY = 608, trap[17].trapPosY = 640, trap[18].trapPosY = 672, trap[19].trapPosY = 672, trap[20].trapPosY = 672, trap[21].trapPosY = 672, trap[22].trapPosY = 672, trap[23].trapPosY = 672, trap[24].trapPosY = 544, trap[25].trapPosY = 544 + 32, trap[26].trapPosY = 514, trap[27].trapPosY =480 ;
		trap[i].x = trap[i].trapPosX;
		trap[i].y = trap[i].trapPosY;
		trap[i].handle = LoadGraph("Data/Map/トゲ.png");
		trap[i].h = 32;
		trap[i].w = 32;
		trap[i].Framecount = 0;
		trap[i].Rota = 0.0f;
		trap[i].IsUse = true;
		trap[i].sitaIsMove = false;	//下から上
		trap[i].ueIsMove = false;	//上から下
		trap[i].hidariIsMove = false;//左から右
		trap[i].migiIsMove = false;	 //右から左
		trap[i].Once_again = false;
	}
	trap[15].Rota = -1.6f, trap[16].Rota = -1.6f, trap[17].Rota = -1.6f, trap[24].Rota = -1.6f, trap[25].Rota = -1.6f, trap[26].Rota = -1.6f;
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
			DrawRotaGraph(trap[i].x - character.GetScreenX()+16, trap[i].y - character.GetScreenY()+16,1.0f, trap[i].Rota, trap[i].handle, true);
		}
	}
	
}
void TrapMove()
{
	if (character.GetPosX() > 1290 && character.GetPosX() < 1400 && character.GetPosY() < 550)
	{
		DrawFormatString(100, 220, GetColor(255, 0, 0), "来るぞー");
		trap[8].sitaIsMove = true, trap[9].sitaIsMove = true, trap[10].sitaIsMove = true, trap[11].sitaIsMove = true;
	}
	if (character.GetPosX() > 2070 && character.GetPosX() < 2200 && character.GetPosY() > 600 && character.GetPosY() < 660)
	{
		trap[12].sitaIsMove = true, trap[13].sitaIsMove = true, trap[14].sitaIsMove = true;
	}
	if (character.GetPosX() > 2190 && character.GetPosX() < 2230 && character.GetPosY() > 450 && character.GetPosY() < 630)
	{
		trap[15].migiIsMove = true, trap[16].migiIsMove = true, trap[17].migiIsMove = true, trap[24].migiIsMove = true, trap[25].migiIsMove = true, trap[26].migiIsMove = true;
	}
	
	for (int i = 0; i < TRAP_MAX; i++)
	{

		if (trap[i].ueIsMove == true)
		{
			trap[i].y += 20;
		}
		if (trap[i].sitaIsMove == true)
		{
			trap[i].y -= 20;
		}
		if (trap[i].migiIsMove == true)
		{
			trap[i].x -= 20;
		}
		if (trap[12].y < 256)
		{
			trap[12].sitaIsMove = false, trap[13].sitaIsMove = false, trap[14].sitaIsMove = false;
			trap[12].y = 256, trap[13].y = 256, trap[14].y = 256;
			trap[i].sitaIsMove = false;
		}
	}
}
