#include "DxLib.h"
#include "SceneTitle.h"
#include "../Scene/scene.h"
#include "../Input/Input.h"

SceneTitle scenetitle;

SceneTitle::SceneTitle() 
{
	// タイトル背景ハンドル
	TitleBGHandle = 0;
	TitlePushHandle = 0;
	TitleNameHandle = 0;

	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		CloudImageHandle1[i] = 0;
		CloudImageHandle2[i] = 0;
	}
	

	//TitleSoundPath = 0;
}
SceneTitle::~SceneTitle() { FinTitle(); }

// タイトルの初期化
void SceneTitle::InitTitle()
{
	SetMouseDispFlag(true);

	// タイトル背景ハンドル
	TitleBGHandle = LoadGraph(TITLE_BG_PATH);
	//タイトルボタンハンドル
	TitlePushHandle = LoadGraph(TITLE_PUSH_IMAGE_PATH);
	
	ChangeCnt = 100;

	//タイトル名ハンドル
	TitleNameHandle = LoadGraph(TITLE_NAME_PATH);

	//雲ハンドル
	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		CloudImageHandle1[i] = LoadGraph(TITLE_CLOUD_HANDLE1);
		CloudImageHandle2[i] = LoadGraph(TITLE_CLOUD_HANDLE2);

		//雲の初期座標
		CloudPosX[i] = GetRand(1080);
		CloudPosY[i] = GetRand(350);

		CloudPosX2[i] = GetRand(1080);
		CloudPosY2[i] = GetRand(350);
	}

	//サウンドハンドル
	TitleSoundPath = LoadSoundMem(TITLE_BGM_PATH);
	PushSEPath = LoadSoundMem(BUTTON_SE_PATH);

	PlaySoundMem(TitleSoundPath, DX_PLAYTYPE_BACK, true);

	NextSceneCnt = 255;
	SceneFlag = false;

	// タイトルループへ
	sceneID = SCENE_LOOP_TITLE;
}

// タイトル通常処理
void SceneTitle::StepTitle()
{
	GetMousePoint(&mouseX, &mouseY);

	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		CloudPosX[i] -= 2;
		CloudPosX2[i] -= 1;

		if (CloudPosX[i] < -64)
		{
			CloudPosX[i] = 1080 + GetRand(128);
			CloudPosY[i] = GetRand(350);
		}

		if (CloudPosX2[i] < -32)
		{
			CloudPosX2[i] = 1080 + GetRand(32*3);
			CloudPosY2[i] = GetRand(350);
		}

	}

	// Enterを押したら
	//if(InputKey::Push(KEY_INPUT_RETURN))
	//{
	//	// タイトルシーンを終了
	//	FinTitle();
	//}

	//タイトルボタンを押したら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		PlaySoundMem(PushSEPath, DX_PLAYTYPE_BACK,true);

		SceneFlag = true;
	}
	if (NextSceneCnt == 0)
	{
		//タイトルシーンを終了
		FinTitle();
	}

	if (SceneFlag == true)
	{
		NextSceneCnt-=4;
		if (NextSceneCnt < 0)
		{
			SceneFlag = false;
			NextSceneCnt = 0;
		}
	}
	
}

// タイトル描画処理
void SceneTitle::DrawTitle()
{
	// タイトル背景描画
	DrawGraph(0, 0, TitleBGHandle, true);

	//タイトルボタン描画
	DrawGraph(270, 300, TitlePushHandle, true);
	
	
	//タイトル名描画
	DrawGraph(250, 100, TitleNameHandle, true);

	//雲描画
	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		DrawRotaGraph(CloudPosX2[i], CloudPosY2[i], 1.0f, 0.0f, CloudImageHandle2[i], true);
		DrawRotaGraph(CloudPosX[i], CloudPosY[i], 1.0f, 0.0f, CloudImageHandle1[i], true);
	}


	if (NextSceneCnt == 0)
	{
		SetDrawBright(255, 255, 255);
	}
	else
	{
		SetDrawBright(NextSceneCnt, NextSceneCnt, NextSceneCnt);
	}
	
	
		
	
	
	//座標確認用
   /* DrawFormatString(0, 55, GetColor(0, 0, 255),
		"マウス座標:X:%d\nマウス座標:Y:%d"
		, mouseX, mouseY);*/
}

// タイトル終了処理
void SceneTitle::FinTitle()
{
	// タイトル背景ハンドル
	DeleteGraph(TitleBGHandle);

	//タイトルボタンハンドル
	DeleteGraph(TitlePushHandle);
	
	
	//BGMハンドル
	DeleteSoundMem(TitleSoundPath);
	DeleteSoundMem(PushSEPath);
	
	// プレイシーンに移動
	sceneID = SCENE_INIT_PLAY;
}
