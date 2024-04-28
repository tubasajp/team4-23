#include "Trap.h"
#include <DXLib.h>
#include"../Character/Character.h"
Trap  trap[TRAP_MAX];

void trapInit()
{ 
	for (int i = 0; i < TRAP_MAX; i++)
	{																		   //3”Ô–Ú‚Í‰¡‰æ‘œ
		trap[0].trapPosX = 448, trap[1].trapPosX =576, trap[2].trapPosX = 768, trap[3].trapPosX = 1024;
		trap[0].trapPosY = 608, trap[1].trapPosY =608, trap[2].trapPosY = 608, trap[3].trapPosY = 640;
		trap[i].x = trap[i].trapPosX;
		trap[i].y = trap[i].trapPosY;
		trap[i].handle = LoadGraph("Data/Map/ƒgƒQ.png");
		trap[i].h = 32;
		trap[i].w = 32;
	}
}

void trapStep()
{

}
void trapDraw()
{
	for (int i = 0; i < TRAP_MAX; i++)
	{
		DrawGraph(trap[i].x-character.GetScreenX(), trap[i].y - character.GetScreenY(), trap[i].handle, true);
	}
	
}
