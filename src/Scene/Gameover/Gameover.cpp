#include"Gameover.h"
#include"../Scene.h"
#include"../../Input/Input.h"
#include"DxLib.h"

Gameover gameover;
void Gameover::Init()
{
	x = 0;
	y = 0;
	handle = LoadGraph("Data/GameoverImage/GameoverImage2.png");

	soundhandle = LoadSoundMem("Data/BGM/GameoverSound.mp3");
	PlaySoundMem(soundhandle, DX_PLAYTYPE_LOOP, true);

}
void Gameover::Draw()
{
	DrawGraph(x, y, handle, true);
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		DeleteSoundMem(soundhandle);
		sceneID = SCENE_ID_INIT_PLAY;
	}
}
