#include"DxLib.h"
#include"Clear.h"
#include"../../Input/Input.h"
#include"../../Scene/Scene.h"
CLEAR Clear;

void CLEAR::Init()
{
	x = 0;
	y = 0;
	handle = LoadGraph("Data/ClearImage/ClearImage2.png");
	namehandle = LoadGraph("Data/ClearImage/Clear.png");
	namex = 230;
	namey = -50;

	soundhandle = LoadSoundMem("Data/BGM/ClearSound1.m4a");
	PlaySoundMem(soundhandle, DX_PLAYTYPE_BACK, true);
}
void CLEAR::Draw()
{
	DrawGraph(x, y, handle, true);
	DrawGraph(namex, namey,namehandle, true);
	namey += 1;
	if (namey > 100)
	{
		namey = 100;
	}

	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		DeleteSoundMem(soundhandle);
		sceneID = SCENE_ID_INIT_PLAY;
	}
}