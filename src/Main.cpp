//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include"Scene/Scene.h"
#include"../src/Play/Play.h"
#include"Input/Input.h"
#include"Character/Character.h"
#include"Map/Map.h"
#include"PlaySceen/PlaySceen.h"
#include"Trap/Trap.h"


#define FRAME_RATE (60)


#define FRAME_TIME (1000/FRAME_RATE)

struct FrameRateInfo
{
	int currentTime;    
	int lastFrameTime;  
	int count;          
	int calcFpsTime;   
	float fps;         
};


FrameRateInfo frameRateInfo;


void CalcFPS();


void DrawFPS();
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
	SCENE_ID sceneID= SCENE_ID_INIT_TITLE;
	CTrap trap;
	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{

		Sleep(1);  //?V?X?e???????????

		//??????????擾
		frameRateInfo.currentTime = GetNowCount();

		//???????[?v???
		//??????????AFPS??v?Z?????????????
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}


		//??????????A?O???t???[???????
		//1000/60?~???b(1/60?b)???o?????????珈???????s????
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//?t???[?????s?????????X?V
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//?t???[???????J?E???g
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//?G?X?P?[?v?L?[??????????I??
				break;
			}

			//????\?????????????????
			ClearDrawScreen();

			StepInput();

			//-----------------------------------------
			//????????Q?[????{??????????????
			switch (sceneID)
			{
				//-----------------------------------------
			case SCENE_ID_INIT_TITLE:
			{
				character.Init();
				character.InitScreen();
				map.ReadFilemap();
				map.InitMap();
				trap.Init();
				sceneID = SCENE_ID_LOOP_TITLE;
			}
			break;

			case SCENE_ID_LOOP_TITLE:
			{
				character.Step();
				trap.Step();
				playSceen.Character_Hit_Map();
				character.UpdatePos();
				character.Draw();
				trap.Draw();
				map.DrawMap();
			}
			break;

			case SCENE_ID_INIT_PLAY:
			{

			}
			break;

			case SCENE_ID_LOOP_PLAY:
			{

			}
			break;

			default:
				break;

			}


			//-----------------------------------------

			//FPS?v?Z
			CalcFPS();

			//FPS?\??
			DrawFPS();


			//???[?v??I????
			//?t???b?v???
			ScreenFlip();
		}
	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

void CalcFPS()
{

	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;


	if (difTime > 1000)
	{

		float frameCount = (float)(frameRateInfo.count * 1000.0f);


		frameRateInfo.fps = frameCount / difTime;


		frameRateInfo.fps = frameCount / difTime;


		frameRateInfo.count = 0;


		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

void DrawFPS()
{
	unsigned int color = GetColor(255, 30, 30);
	DrawFormatString(0, 0, color, "FPS[%.2f]", frameRateInfo.fps);

}