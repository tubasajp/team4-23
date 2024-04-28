#include"Gameover.h"
#include"../Scene.h"
#include"../../Input/Input.h"
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
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		sceneID = SCENE_ID_INIT_PLAY;
	}
}
