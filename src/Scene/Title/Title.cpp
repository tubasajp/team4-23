#include"Title.h"
#include"DxLib.h"
#include"../../Input/Input.h"
#include"../Scene.h"
Title title;
void Title::InitTitle()
{
	x = 0;
	y = 0;
	handle = LoadGraph("Data/TitleImage/TitleImage3.png");
	TitleNameHandle = LoadGraph("Data/TitleImage/NameImage.png");

	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		cloudHandle[i] = LoadGraph("Data/TitleImage/cloud1.png");

		cloudx[i] = GetRand(1280);
		cloudy[i] = GetRand(720 / 2);
	}
	//TitleButtonHandle = LoadGraph("Data/TitleImage/PushImage100.png");

	soundhandle = LoadSoundMem("Data/BGM/TitleSound1.mp3");
	PlaySoundMem(soundhandle, DX_PLAYTYPE_BACK, true);

	ButtonSEPath = LoadSoundMem("Data/SE/ButtonSound.mp3");

	NextSceneCnt = 255;
	SceneFlag = false;

	// タイトルループへ
	//sceneID = SCENE_ID_LOOP_TITLE;
}
void Title::DrawTitle()
{
	DrawGraph(x, y, handle,true);
	DrawGraph(320, 0, TitleNameHandle, true);

	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		cloudx[i] -= 3;

		DrawRotaGraph(cloudx[i], cloudy[i], 1.0f, 0.0f, cloudHandle[i], true);

		if (cloudx[i] < 0 - 64)
		{
			cloudx[i] = 1280 + GetRand(128+64);
			cloudy[i] = GetRand(720 / 2);
		}
	}

	//DrawGraph(0, 350, TitleButtonHandle, true);

	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		SceneFlag = true;
		PlaySoundMem(ButtonSEPath, DX_PLAYTYPE_BACK, true);
	}
	if (NextSceneCnt == 0)
	{
		sceneID = SCENE_ID_INIT_PLAY;
		DeleteSoundMem(soundhandle);
		DeleteSoundMem(ButtonSEPath);
		DeleteGraph(handle);

		for (int i = 0; i < CLOUD_MAX_NUM; i++)
		{
			DeleteGraph(cloudHandle[i]);
		}
	}

	if (SceneFlag == true)
	{
		NextSceneCnt -= 4;
		if (NextSceneCnt < 0)
		{
			SceneFlag = false;
			NextSceneCnt = 0;
		}
	}

	if (NextSceneCnt == 0)
	{
		SetDrawBright(255, 255, 255);
	}
	else
	{
		SetDrawBright(NextSceneCnt, NextSceneCnt, NextSceneCnt);
	}
}