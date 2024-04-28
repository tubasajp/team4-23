#include"DxLib.h"
#include"parasol.h"
#include"../Cracter/Character.h"
Parasol parasol[CHARACTER_PARASOL_MAX];
int ParasolHandle[4];	//画像パスを入れる変数
int parasolchaeng = 0;;	//パラソルを切り替える
void Initparasol()	//初期化
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		parasol[i].x = 0;
		parasol[i].y = 0;
		parasol[i].parasolFramecount = 0;
	}
	ParasolHandle[0] = LoadGraph("data/02_Playimage/parasol.png");
	ParasolHandle[1] = LoadGraph("data/02_Playimage/parasol2.png");
	ParasolHandle[2] = LoadGraph("data/02_Playimage/parasol3.png");
	ParasolHandle[3] = LoadGraph("data/02_Playimage/parasol4.png");
	
}
void Stepparasol()	//キャラクターにパラソル情報を入れる
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		parasol[i].x = character[i].x+20;
		parasol[i].y = character[i].y;
	}
}
void Drawparasol()	//パラソルを描画
{
	

	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		DrawFormatString(0, 300, GetColor(255, 0, 0), "Parasol time%d", parasol[i].parasolFramecount);
		if (character[i].parasol == true)	//パラソルが開いてるか確認
		{
			//フレームカウントで画像を切り替える
			if (parasol[i].parasolFramecount == 0)
			{
				parasolchaeng = ParasolHandle[3];
			}
			if (parasol[i].parasolFramecount == 1)
			{
				parasolchaeng = ParasolHandle[2];
			}
			if (parasol[i].parasolFramecount == 2)
			{
				parasolchaeng = ParasolHandle[1];
			}
			if (parasol[i].parasolFramecount == 3)
			{
				parasolchaeng = ParasolHandle[0];
			}
			if (parasol[i].parasolFramecount <3)
			{
				parasol[i].parasolFramecount++;
			}
			DrawRotaGraph(parasol[i].x, parasol[i].y, 1.0f, 0.0f, parasolchaeng, true);
		}
	}
}