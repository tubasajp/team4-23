#include "DxLib.h"
#include "FPS.h"

//フレームレート情報変数
FrameRateInfo frameRateInfo = { 0 };


//FPS計算
void CalcFPS()
{
	//前回のFPSを計算した時間から経過時間を求める
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//前回のFPSを計算下時間から
	//１秒以上経過していたらFPSを計算する
	if (difTime > 1000)
	{
		//フレーム回数をミリ秒に合わせる
		//小数まで出したいのでfloatにキャスト
		float frameCount = (float)(frameRateInfo.count * 1000.0f);

		//FPSを求める
		//理想の数値は60000/1000で60　となる
		frameRateInfo.fps = frameCount / difTime;

		//フレームレートカウントをクリア
		frameRateInfo.count = 0;

		//FPSを計算した時間を更新
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

//FPS表示（デバッグ用）
void DrawFPS()
{
	unsigned int color = GetColor(255, 30, 30);
	DrawFormatString(1180, 700, color, "FPS[%.2f]", frameRateInfo.fps);
}

void TimeFPS()
{
	Sleep(1);  //システム二処理を返す	

	//現在の時間を取得
	frameRateInfo.currentTime = GetNowCount();

	//最初のループなら
	//現在の時間を、FPSの計算をした時間に設定
	if (frameRateInfo.calcFpsTime == 0.0f)
	{
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
		frameRateInfo.fps = (float)FRAME_RATE;
	}

	
}