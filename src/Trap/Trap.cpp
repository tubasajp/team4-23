#include "Trap.h"
#include <DXLib.h>
const int TRAP_MAX=10;
Trap  trap[TRAP_MAX];

void Init()
{ 
	for (int i = 0; i < TRAP_MAX; i++)
	{
		trap[i].handle = LoadGraph("Data/Map/ƒgƒQ.png");
	}
}

void Step()
{

}
void Draw()
{
	for (int i = 0; i < TRAP_MAX; i++)
	{
		DrawGraph(trap[i].x, trap[i].y, trap[i].handle, true);
	}
	
}
