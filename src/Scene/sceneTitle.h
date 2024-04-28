#pragma once

// 画像パス
// タイトル背景
#define TITLE_BG_PATH "Data/TitleImage/TitleImage2.png"
#define TITLE_PUSH_IMAGE_PATH "Data/TitleImage/PushImage100.png"

#define TITLE_NAME_PATH "Data/TitleImage/仮置きタイトル.png"

#define TITLE_CLOUD_HANDLE1 "Data/TitleImage/cloud1.png"
#define TITLE_CLOUD_HANDLE2 "Data/TitleImage/cloud2.png"

//タイトルBGM
#define TITLE_BGM_PATH "Data/Sound/TitleSceneBGM.mp3"
#define BUTTON_SE_PATH "Data/Sound/ButtonSound.mp3"

#define CLOUD_MAX_NUM (4)

class SceneTitle 
{
private:
	// タイトル背景ハンドル
	int TitleBGHandle;

	int TitlePushHandle;
	int ChangeCnt;

	int TitleNameHandle;

	int CloudImageHandle1[CLOUD_MAX_NUM];
	int CloudImageHandle2[CLOUD_MAX_NUM];

	int CloudPosX[CLOUD_MAX_NUM], CloudPosY[CLOUD_MAX_NUM];
	int CloudPosX2[CLOUD_MAX_NUM], CloudPosY2[CLOUD_MAX_NUM];

	int mouseX, mouseY;

	int TitleSoundPath;
	int PushSEPath;

	int NextSceneCnt;

	bool SceneFlag;

public:
	SceneTitle();
	~SceneTitle();
	
	// タイトルの初期化
	void InitTitle();

	// タイトル通常処理
	void StepTitle();

	// タイトル描画処理
	void DrawTitle();

	// タイトル終了処理
	void FinTitle();
};

extern SceneTitle scenetitle;