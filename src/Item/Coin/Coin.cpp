#include"DxLib.h"
#include"Coin.h"

Coin coin[COIN_MAX];

void InitCoin()
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		coin[i].x = 600;
		coin[i].y = 50;
		coin[i].h = 64;
		coin[i].w = 64;
		coin[i].handle = LoadGraph("data/02_Playimage/coin.png");
	}
	
}

void DrawCoin()
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		DrawBox(coin[i].x, coin[i].y, coin[i].x + coin[i].w, coin[i].y + coin[i].h, GetColor(255, 255, 255), false);
		DrawRotaGraph(coin[i].x+32, coin[i].y+32, 1.0f, 0.0f, coin[i].handle, true);
	}
}