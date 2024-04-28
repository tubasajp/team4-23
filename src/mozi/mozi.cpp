#include"mozi.h"
#include"DxLib.h"
Mozi mozi;
int moziPath[5];
void Mozi::Init()
{
	x = 0;
	y = 0;
	Framecount = 0;
	IsUse = true;
	handle = LoadGraph("Data/TitleImage/PushImage20.png");
	moziPath[0]= LoadGraph("Data/TitleImage/PushImage20.png");
	moziPath[1] = LoadGraph("Data/TitleImage/PushImage40.png");
	moziPath[2] = LoadGraph("Data/TitleImage/PushImage60.png");
	moziPath[3] = LoadGraph("Data/TitleImage/PushImage80.png");
	moziPath[4] = LoadGraph("Data/TitleImage/PushImage100.png");
}
void Mozi::Step()
{
	if (IsUse ==true)
	{
		Framecount++;
	}
	if (IsUse ==false)
	{
		Framecount--;
	}
	if (Framecount == 30)
	{
		handle = moziPath[1];
		IsUse = true;
	}
	if (Framecount == 50)
	{
		handle = moziPath[2];
	}
	if (Framecount == 70)
	{
		handle = moziPath[3];
	}
	if (Framecount == 90)
	{
		handle = moziPath[4];
		IsUse = false;
	}

}
void Mozi::Draw()
{
	DrawGraph(x, y, handle, true);
}