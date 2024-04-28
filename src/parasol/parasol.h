#pragma once
#define PARASOL_GAZOU	(4)		//パラソルの枚数
struct Parasol
{
	int x, y, handle,parasolFramecount;
};
void Initparasol();	//初期化
void Stepparasol();	//パラソル情報を入れる
void Drawparasol();	//パラソルを描画
extern int parasolchaeng;	//パラソルを切り替える