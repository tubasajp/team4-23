#include"DxLib.h"
#include"Character.h"
#include"../Input/Input.h"
#include"../Common.h"
const int MOVE_SPEED = 5;	//移動スピード
const int JUNP_POWER = 20;	//ジャンプ力
const int GRAVITY_SPEED = 1;		//常にかかる重力
const int SCREEN_SPEED = 10;	//スクリーンの移動力
const int GRAVITY_MAX = 8;	//重力の上限
Character character;
void Character::Init()
{
	x = 0;		
	y = 0;
	h = 32;			
	w = 32;
	GravitySpeed = 0;			//重力のスピード
	Next_x = 0;					//次の座標
	Next_y - 0;					//次の座標
	handle = LoadGraph("Data/");
	Isuse = false;				
	JunpIsUse = false;			//ジャンプ使用フラグ
}
void Character::Move()
{
	if (IsKeyPush(KEY_INPUT_W))
	{
		GravitySpeed -= JUNP_POWER;
	}
	if (IsKeyKeep(KEY_INPUT_A))
	{
		Next_x-= MOVE_SPEED;
	}
	if (IsKeyKeep(KEY_INPUT_D))
	{
		Next_x += MOVE_SPEED;
	}
}
void Character::Gravity()
{
	GravitySpeed += GRAVITY_SPEED;
	if (GravitySpeed >= GRAVITY_MAX)	//重力の上限を決める
	{
		GravitySpeed = GRAVITY_MAX;
		Next_y += GravitySpeed;
	}
	else	//上限行くまで入る
	{
		Next_y += GravitySpeed;
	}

}
void Character::Draw()
{
	DrawFormatString(100, 50, GetColor(255, 0, 0), "x = %d  y = %d", x,y);

	/*DrawBox(x-ScreenX ,y - ScreenY,x+w - ScreenX,y+h - ScreenY, GetColor(255, 255, 255), false);*/
	DrawRotaGraph(x, y, 1.0, 0.0, handle, true);
}
void Character::UpdatePos()
{
	x = Next_x;
	y = Next_y;
}
void Character::Step()
{
	character.Move();
	character.Gravity();
	character.StepScreen();
}
void Character::GetMoveDirection(bool* _dirArray) 		//左右上下の当たり判定
{
	// 右方向のチェック
	if (Next_x > x) {
		_dirArray[3] = true;
	}
	// 左方向のチェック
	if (Next_x < x) {
		_dirArray[2] = true;
	}
	// 下方向のチェック
	if (Next_y > y) {
		_dirArray[1] = true;
	}
	// 左方向のチェック
	if (Next_y < y) {
		_dirArray[0] = true;
	}
}
void Character::InitScreen() 						//スクリーン座標の初期化
{
	ScreenPosX = x - SCREEN_SIZE_X / 2;						//X座標のスクリーンX座標比較
	ScreenPosY = y - SCREEN_SIZE_Y / 2;						//Y座標のスクリーンY座標比較
	ScreenX = x - SCREEN_SIZE_X / 2;
	ScreenY = y - SCREEN_SIZE_Y / 2;
}
void Character::StepScreen()						//スクリーンのワールド座標
{
	ScreenX = x - SCREEN_SIZE_X / 2;						//X座標のスクリーンX座標比較
	ScreenY = y - SCREEN_SIZE_Y / 2;						//Y座標のスクリーンY座標比較

	DrawFormatString(100, 140, GetColor(255, 0, 0), "ScreenX=%d", ScreenX);
	DrawFormatString(100, 160, GetColor(255, 0, 0), "Screen=%d", ScreenY);
	////スクリーンXをついてくる動かす処理
	//
	///*if (x > 365 && x < 4500)*/
	//{
	//	if (ScreenX > ScreenPosX + 100)
	//	{
	//		ScreenX -= SCREEN_SPEED;
	//	}
	//	if (ScreenX < ScreenPosX - 200)
	//	{
	//		ScreenX += SCREEN_SPEED;
	//	}
	//}
	//
}