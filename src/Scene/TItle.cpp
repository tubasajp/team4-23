#include "DxLib.h"
#include "Scene.h"
#include "Title.h"

#define TITLE_BACKGROUND_PATH "data/01_TitleImage/title.png"

SceneTitle::SceneTitle()
{
	BackGround = 0;		//画像の初期化
}

SceneTitle::~SceneTitle() {}

//タイトルの初期化
void SceneTitle::Init()
{
	//画像の読み込み
	BackGround = LoadGraph(TITLE_BACKGROUND_PATH);
	//キーの初期化
	InitInput();
	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;

}

// タイトル通常処理
void SceneTitle::Step()
{
	//キー
	StepInput();

	//スペースキーを押したら画面移動
 	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void SceneTitle::Draw()
{
	DrawGraph(0, 0, BackGround, true);
}

// タイトル終了処理
void SceneTitle::Fin()
{
	// プレイシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}