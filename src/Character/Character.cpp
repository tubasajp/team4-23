#include"DxLib.h"
#include"Character.h"
#include"../Input/Input.h"
#include"../Common.h"
#include"../Scene/Scene.h"
const int MOVE_SPEED = 5;	//移動スピード
const int JUNP_POWER = 20;	//ジャンプ力
const int GRAVITY_SPEED = 1;		//常にかかる重力
const int SCREEN_SPEED = 10;	//スクリーンの移動力
const int GRAVITY_MAX = 8;	//重力の上限
const int Deth_Line = 950;	
Character character;
void Character::Init()
{
	x = /*1900*/384;		
	y = /*608*/800;					//初期値
	h = 32;			
	w = 32;
	GravitySpeed = 0;			//重力のスピード
	Next_x = x;					//次の座標
	Next_y = y;					//次の座標
	HitSquareX = 0;				//マップとキャラの当たり判定を任意に調整するX
	HitSquareY = 0;				//マップとキャラの当たり判定を任意に調整するY
	Hp = 1;
	handle = LoadGraph("Data/");
	Isuse = false;
	DebugMode = true;
	Junpcount = 0;			//ジャンプ使用フラグ
}
void Character::Move()
{
	DrawFormatString(100, 70, GetColor(255, 0, 0), "GravitySpeed %d ",GravitySpeed);
	if (IsKeyPush(KEY_INPUT_W))
	{
		if (Junpcount < 3)
		{
			Junpcount++;
		}
		
		if (Junpcount == 2)
		{
			GravitySpeed = -12;
		}
	}
	
	//xが155まで行ったら操作不能
	if (x > 155)
	{
		if (IsKeyKeep(KEY_INPUT_A))
		{
			Next_x -= MOVE_SPEED;
		}
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
	DrawRotaGraph(x- ScreenX, y- ScreenY, 1.0, 0.0, handle, true);
}
void Character::UpdatePos()
{
	x = Next_x;
	y = Next_y;
}
void Character::Step()
{
	SwitchDebug();
	if (DebugMode == false)
	{
		character.Move();
		character.Gravity();
	}
	else
		DebugStep();

	character.StepScreen();
	Dead_Line();
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
	ScreenX =310;
	ScreenY = 216;
	ScreenPosX = ScreenX;
	ScreenPosY = ScreenY;
}
void Character::StepScreen()						//スクリーンのワールド座標
{
	ScreenPosX = x - SCREEN_SIZE_X / 2;						//X座標のスクリーンX座標比較
	ScreenPosY = y - SCREEN_SIZE_Y / 2;						//Y座標のスクリーンY座標比較

	DrawFormatString(100, 140, GetColor(255, 0, 0), "ScreenX=%d", ScreenX);
	DrawFormatString(100, 160, GetColor(255, 0, 0), "Screen=%d", ScreenY);
	////スクリーンXをついてくる動かす処理
	if(ScreenX>0)
	{
		if (ScreenX > ScreenPosX + 400)
		{
			ScreenX -= 10;
		}
		if (ScreenX < ScreenPosX + 150)
		{
			ScreenX += 10;
		}
	}
}
void Character::StepHitSquare()					//当たり判定を調節する位置
{
	HitSquareX = x / 32;
	HitSquareY = y / 32;
}
void Character::StepOnJunp()
{
	if (IsKeyPush(KEY_INPUT_W))
	{
		if (Junpcount < 3)
		{
			Junpcount++;
		}
		
		if (Junpcount == 1)
		{
			GravitySpeed -= JUNP_POWER;
		}
	}
}
void Character::DebugStep()
{
	int a = 0;
	if (IsKeyKeep(KEY_INPUT_LSHIFT))
	{
		 a= 4;
	}
	if (IsKeyKeep(KEY_INPUT_W))
	{
		Next_y -= MOVE_SPEED-a;
	}
	if (IsKeyKeep(KEY_INPUT_S))
	{
		Next_y += MOVE_SPEED - a;
	}
	if (IsKeyKeep(KEY_INPUT_A))
	{
		Next_x -= MOVE_SPEED - a;
	}

	if (IsKeyKeep(KEY_INPUT_D))
	{
		Next_x += MOVE_SPEED - a;
	}
}
void Character::SwitchDebug()
{
	if (IsKeyPush(KEY_INPUT_1))
	{
		DebugMode = true;
		
	}
	if (IsKeyPush(KEY_INPUT_2))
	{
		DebugMode = false;
	}
}
void  Character::Dead_or_Alive()
{
	if (Hp == 0)
	{
		sceneID = SCENE_ID_INIT_GAMEOVER;
	}
}
void Character::Dead_Line()
{
	if (y > Deth_Line)
	{
		sceneID = SCENE_ID_INIT_GAMEOVER;
	}
}