#pragma once
#include"DxLib.h"
class Character
{
private:
	int x, y, h, w, handle,GravitySpeed,Next_x,Next_y, ScreenX, ScreenY, ScreenPosX, ScreenPosY,HitSquareX, HitSquareY,Junpcount,OnJunp,Hp, walkLeftFramecount, walkrightFramecount;
	bool Isuse,DebugMode;
	bool gazousyokik = false;
	int backhandle;
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
	void StepHitSquare();					//当たり判定を調節する位置
	void DebugStep();
	void StepOnJunp();
	void SwitchDebug();
	void  Dead_or_Alive();					//この名前なかなかにセンスある
	void Dead_Line();
	void Stepwalk();
	void DrawPlayHaikei();
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
	int GetHitSquareX() { return HitSquareX; }
	int GetHitSquareY() { return HitSquareY; }
	int SetHitSquareX(int a) { HitSquareX = a; return HitSquareX; }
	int SetHitSquareY(int a) { HitSquareY = a; return HitSquareY;  }
	int SetJunpcount(int a) { Junpcount = a; return Junpcount; }
	int GetJunpcount() { return Junpcount; }
	int SetGravitySpeed(int a) { GravitySpeed = a; return GravitySpeed; }
	int GetHp() { return Hp; }
	int SetHp(int a) { Hp = a;  return Hp; }
};
extern Character character;