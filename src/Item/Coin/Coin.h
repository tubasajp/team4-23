#pragma once
#define COIN_MAX	(1)
struct Coin
{
	int x, y, h, w,handle;
};
void InitCoin();	//コインの初期化
void DrawCoin();	//コインの描画
extern Coin coin[COIN_MAX];