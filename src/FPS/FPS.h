#pragma once

//設定フレームレート（60FPS）
#define FRAME_RATE (60)

//1フレームの時間（ミリ秒）
#define FRAME_TIME (1000/FRAME_RATE)

void CalcFPS();
void DrawFPS();
void TimeFPS();

//フレームレート情報
struct FrameRateInfo
{
	int currentTime;		//現在の時間
	int lastFrameTime;		//前回のフレーム実行時の時間
	int count;				//フレームカウント用
	int calcFpsTime;		//FPSを計算下時間
	float fps;				//計測したFPS（表示用）
};

extern FrameRateInfo frameRateInfo;