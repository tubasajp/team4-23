#include "DxLib.h"
#include"../Cracter/Character.h"
#include"../Item/Coin/Coin.h"
#include"../Collision/Collision.h"
void Character_Hit_Coin()
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX;i++)
	{

		for (int i = 0; i < COIN_MAX; i++)
		{
			if (IsHitRect(character[i].x, character[i].y, character[i].w, character[i].h, coin[i].x, coin[i].y, coin[i].w, coin[i].h))
			{
				DrawFormatString(100, 240, GetColor(255, 0, 0), "ƒqƒbƒg");

			}
		}
	}
}
