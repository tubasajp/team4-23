#include"Title.h"
#include"DxLib.h"
#include"../../Input/Input.h"
#include"../scene.h"
Title title;
void Title::InitTitle()
{
	x = 0;
	y = 0;
	handle = LoadGraph("Data/TitleImage/BackGround.png");
}
void Title::DrawTitle()
{
	DrawGraph(x, y, handle,true);
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		sceneID = SCENE_INIT_PLAY;
	}
}