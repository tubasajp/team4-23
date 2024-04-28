//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include"Scene/Scene.h"
#include"../src/parasol/parasol.h"
#include"../src/Cracter/Character.h"
#include"../src/Input_struct/input.h"
#include"../src/Item/Coin/Coin.h"
#include"../src/Play/Play.h"
//#include"src/Character.h"
//#include"src/input.h"


// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode( WINDOW_WIDTH, WINDOW_HEIGHT ,32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く
	
	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//エスケープキーが押されたら終了
			break;
		}

		//画面に表示されたものを初期化
		ClearDrawScreen();

		//-----------------------------------------
		//ここからゲームの本体を書くことになる
		//-----------------------------------------
		
		switch (g_CurrentSceneID)
		{
		case SCENE_ID_INIT_PLAY:
		{
			InitInput();		//入力の初期化
			InitCharacter();	//キャラクターの初期化
			InitCoin();			//コインの初期化
			Initparasol();		//パラソルの初期化
			g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
		}
		break;
		case SCENE_ID_LOOP_PLAY:
		{
			StepInput();				//キーの記憶
			StepCharacter();			//キャラクターの移動
			StepCharacterGravity();		//キャラクターの重力
			Stepparasol();
			Character_Hit_Coin();		//キャラクターとコインの当たり判定
			StepCharacterDraw();		//キャラクターの描画
			DrawCoin();					//コインの描画
			Drawparasol();				//パラソルの描画
		}
		break;
		}
		//-----------------------------------------
		//ループの終わりに
		//フリップ関数
		ScreenFlip();

	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

