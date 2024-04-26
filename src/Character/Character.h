#pragma once
#include"DxLib.h"
class Character
{
private:
	int x, y, h, w, handle,GravitySpeed,Next_x,Next_y, ScreenX, ScreenY, ScreenPosX, ScreenPosY;
	bool Isuse;
	bool JunpIsUse;
public:
	void Init();		//初期化
	void Move();		//移動
	void Gravity();		//重力
	void GetMoveDirection(bool* _dirArray);		//左右上下の当たり判定
	void UpdatePos();	//座標のアップデート
	void Draw();		//描画
	void Step();		//ここでまとめる
	void InitScreen();						//スクリーン座標の初期化
	void StepScreen();						//スクリーンのワールド座標
	int  GetPosX() { return x; }
	int  GetPosY() { return y; }
	int  GetPosH() { return h; }
	int  GetPosW() { return w; }
	int GetNextPosX() { return Next_x; }
	int GetNextPosY() { return Next_y; }
	int SetNextPosX(int a) { Next_x = a; return Next_x; }
	int SetNextPosY(int a) { Next_y = a; return Next_y; }
	int GetScreenX() { return ScreenX; }
	int GetScreenY() { return ScreenY; }
};
extern Character character;