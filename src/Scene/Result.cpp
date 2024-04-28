#include "DxLib.h"
#include "Scene.h"
#include "Result.h"

#define TITLE_BACKGROUND_PATH "data/03_ClearImage/result.png"

SceneResult::SceneResult()
{
	BackGround = 0;		//画像の初期化
}

SceneResult::~SceneResult() {}

//初期化
void SceneResult::Init()
{
	//画像の読み込み
	BackGround = LoadGraph(TITLE_BACKGROUND_PATH);
	//キーの初期化
	InitInput();
	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;

}

// 通常処理
void SceneResult::Step()
{
	//キー
	StepInput();
	//スペースキーを離したら画面移動
	if (IsKeyRelease(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}
}

// 描画処理
void SceneResult::Draw()
{
	DrawGraph(0, 0, BackGround, true);
}

// 終了処理
void SceneResult::Fin()
{
	//タイトル移動
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}