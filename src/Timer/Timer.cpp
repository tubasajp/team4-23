#include "DxLib.h"
#include "Timer.h"


Timer::Timer()
{
	//タイマーの座標
	timePosX = 555; 
	timePosY = 10;

	flameCount = 0;		//フレームのカウント
	tensPlace = 0;		//十の位
	tensPlaceC = 0;		//十の位用のカウント変数
	oncePlace = 0;		//一の位
	oncePlaceC = 0;		//一の位用のカウント変数
}

void Timer::Init()
{
	flameCount = 0;		//フレームのカウント
	tensPlace = 0;		//十の位
	tensPlaceC = 0;		//十の位用のカウント変数
	oncePlace = 0;		//一の位
	oncePlaceC = 0;		//一の位用のカウント変数

	tensPlaceC = 7900;	//残り100フレーム回ったら十の位の3が2になる//ここで秒数を変更★★★
}

//読み込み
void Timer::Load()
{
	//LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img100);//百の位担当
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img10);//十の位担当
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img01);//一の位担当
}

//処理
void Timer::CountDown()
{
	flameCount++;

	//十の位
	tensPlaceC++;
	tensPlace = (tensPlaceC / 1000) % 1000;
	if (tensPlace > 9) {
		tensPlaceC = 0;
	}
	
	//一の位
	oncePlaceC++;
	oncePlace = (oncePlaceC / 100) % 1000;
	if (oncePlace > 9) {
		oncePlaceC = 0;
	}
}

void Timer::Draw()
{	
	//十の位
	DrawGraph(timePosX, timePosY, img10[tensPlace], true);

	//一の位
	DrawGraph(timePosX + 70 , timePosY, img01[oncePlace], true);

	DrawFormatString(0, 60, GetColor(255, 0, 0), "ジュノくらい%d", tensPlace);
	DrawFormatString(0, 80, GetColor(255, 0, 0), "一の位%d", oncePlace);
	DrawFormatString(0, 100, GetColor(255, 0, 0), "??の位%d", tensPlaceC);
	DrawFormatString(0, 120, GetColor(255, 0, 0), "?の位%d", oncePlaceC);

}

