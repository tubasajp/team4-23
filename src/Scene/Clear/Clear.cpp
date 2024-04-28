#include"DxLib.h"
#include"Clear.h"
#include"../../Input/Input.h"
#include"../../Scene/Scene.h"
CLEAR Clear;

void CLEAR::Init()
{
	x = 0;
	y = 0;
	handle = LoadGraph("Data/TitleImage/BackGround.png");
}
void CLEAR::Draw()
{
	DrawGraph(x, y, handle, true);
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		sceneID = SCENE_ID_INIT_PLAY;
	}
}