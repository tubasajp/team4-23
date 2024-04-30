#include "Trap.h"
#include <DXLib.h>
#include"../Character/Character.h"
Trap  trap[TRAP_MAX];
const float sitamuki = 3.14f;
const float hidarimuki = 1.6f;
bool a = false;
void trapInit()
{ 
	for (int i = 0; i < TRAP_MAX; i++)
	{																		   //3番目は横画像																																																																																																																																																							//27以降はドット絵		
		trap[0].trapPosX = 448, trap[1].trapPosX = 576, trap[2].trapPosX = 768, trap[3].trapPosX = 1024, trap[4].trapPosX = 448, trap[5].trapPosX = 608, trap[6].trapPosX = 768, trap[7].trapPosX = 960, trap[8].trapPosX = 1279, trap[9].trapPosX = 1311, trap[10].trapPosX = 1343, trap[11].trapPosX = 1375, trap[12].trapPosX = 2112, trap[13].trapPosX = 2144, trap[14].trapPosX = 2172, trap[15].trapPosX = 2560, trap[16].trapPosX = 2560, trap[17].trapPosX = 2560, trap[18].trapPosX = 2432, trap[19].trapPosX = 2466, trap[20].trapPosX = 2496, trap[21].trapPosX = 2528, trap[22].trapPosX = 2496, trap[23].trapPosX = 2560, trap[24].trapPosX = 2560, trap[25].trapPosX = 2560, trap[26].trapPosX = 2560, trap[27].trapPosX =2656, trap[28].trapPosX = 2688, trap[29].trapPosX = 2720, trap[30].trapPosX = 2752, trap[31].trapPosX = 2784, trap[32].trapPosX = 2815, trap[33].trapPosX = 2847, trap[34].trapPosX = 2879, trap[35].trapPosX =2912, trap[36].trapPosX = 2944, trap[37].trapPosX = 2976, trap[38].trapPosX = 3008, trap[39].trapPosX = 3040, trap[40].trapPosX = 3136, trap[41].trapPosX = 1246, trap[42].trapPosX = 1246-32;
		trap[0].trapPosY = 608, trap[1].trapPosY = 608, trap[2].trapPosY = 608, trap[3].trapPosY = 640, trap[4].trapPosY = 384, trap[5].trapPosY = 384, trap[6].trapPosY = 384, trap[7].trapPosY = 384, trap[8].trapPosY = 896, trap[9].trapPosY = 896, trap[10].trapPosY = 896, trap[11].trapPosY = 896, trap[12].trapPosY = 642, trap[13].trapPosY = 642, trap[14].trapPosY = 642, trap[15].trapPosY = 576, trap[16].trapPosY = 608, trap[17].trapPosY = 640, trap[18].trapPosY = 672, trap[19].trapPosY = 672, trap[20].trapPosY = 672, trap[21].trapPosY = 672, trap[22].trapPosY = 672, trap[23].trapPosY = 672, trap[24].trapPosY = 544, trap[25].trapPosY = 544 + 32, trap[26].trapPosY = 514,				 trap[27].trapPosY =480, trap[28].trapPosY = 480, trap[29].trapPosY = 480, trap[30].trapPosY = 480, trap[31].trapPosY = 480, trap[32].trapPosY = 480, trap[33].trapPosY = 480, trap[34].trapPosY = 480, trap[35].trapPosY = 480, trap[36].trapPosY = 480, trap[37].trapPosY = 480, trap[38].trapPosY = 480, trap[39].trapPosY = 480, trap[40].trapPosY = 554, trap[41].trapPosY = 896, trap[42].trapPosY = 896;
		trap[i].x = trap[i].trapPosX;
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
		trap[i].Size = 1.0f;
		if (i > 26 && i < 41)
		{
			trap[i].Size = 0.038f;
			trap[i].w = 3;
			trap[i].h = 3;
		}
	}
	//右
	trap[3].Rota = -hidarimuki, trap[15].Rota = -hidarimuki, trap[16].Rota = -hidarimuki, trap[17].Rota = -hidarimuki, trap[24].Rota = -hidarimuki, trap[25].Rota = -hidarimuki, trap[26].Rota = -hidarimuki;
	//下
	trap[0].Rota = -sitamuki, trap[1].Rota = -sitamuki, trap[2].Rota = -sitamuki;
	//左
	trap[4].Rota = hidarimuki, trap[5].Rota = hidarimuki, trap[6].Rota = hidarimuki;
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
			DrawRotaGraph(trap[i].x - character.GetScreenX()+16, trap[i].y - character.GetScreenY()+16, trap[i].Size, trap[i].Rota, trap[i].handle, true);
		}
	}
	
}
void TrapMove()
{
	int Ax = character.GetPosX();
	int Ay = character.GetPosY();
	if (Ax > 1280 && Ax < 1400 && Ay < 640)
	{
		DrawFormatString(100, 220, GetColor(255, 0, 0), "来るぞー");
		trap[8].sitaIsMove = true, trap[9].sitaIsMove = true, trap[10].sitaIsMove = true, trap[11].sitaIsMove = true, trap[41].sitaIsMove = true, trap[42].sitaIsMove = true;
	}
	if (Ax > 2070 && Ax < 2200 && Ay > 550 && Ay < 660)
	{
		trap[12].sitaIsMove = true, trap[13].sitaIsMove = true, trap[14].sitaIsMove = true;
	}
	if (Ax > 2190 && Ax < 2230 && Ay > 450 && Ay < 630)
	{
		trap[15].migiIsMove = true, trap[16].migiIsMove = true, trap[17].migiIsMove = true, trap[24].migiIsMove = true, trap[25].migiIsMove = true, trap[26].migiIsMove = true;
	}
	if (Ax > 2752 && Ax < 2940 && Ay > 880)
	{
		trap[27].ueIsMove = true;
		trap[28].ueIsMove = true;
		trap[31].ueIsMove = true;
		trap[32].ueIsMove = true;
		trap[33].ueIsMove = true;
		trap[34].ueIsMove = true;
		trap[35].ueIsMove = true;
		DrawFormatString(100, 240, GetColor(255, 0, 0), "上とげいきます！！");
	}
	for (int i = 0; i < TRAP_MAX; i++)
	{

		if (trap[i].ueIsMove == true)
		{
			trap[i].y += 12;
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
