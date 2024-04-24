#pragma once
#include"DxLib.h"
class Character
{
private:
	int x, y, h, w, handle,GravitySpeed,Next_x,Next_y;
	bool Isuse;
	bool JunpIsUse;
public:
	void Init();		//初期化
	void Move();		//移動
	void Gravity();		//重力
	void UpdatePos();	//座標のアップデート
	void Draw();		//描画
	void Step();		//ここでまとめる
};
extern Character character;