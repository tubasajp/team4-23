#pragma once
#include "DxLib.h"
#define CHARACTER_PARASOL_MAX	(1)				//プレイヤーの人数を決める
struct  Character
{
	int x,				//横
		y,				//縦
		h,	
		w,
		handleUP,			//画像ハンドル
		handleDown,			//
		Gravity;		//重力
	bool parasol;		
	
};
void InitCharacter();		//キャラクターの初期化
void StepCharacter();		//キャラクターの移動処理
void StepCharacterDraw();	//キャラクターの描画処理
void StepCharacterGravity();//キャラクターの重力処理
extern Character character[CHARACTER_PARASOL_MAX];