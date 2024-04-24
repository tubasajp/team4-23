#include"DxLib.h"
#include"Character.h"
#include"../Input/Input.h"
const int MOVE_SPEED = 5;	//移動スピード
const int JUNP_POWER = 20;	//ジャンプ力
const int GRAVITY = 1;		//常にかかる重力
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
	GravitySpeed += GRAVITY;
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

	DrawBox(x ,y,x+w,y+h, GetColor(255, 255, 255), false);
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
