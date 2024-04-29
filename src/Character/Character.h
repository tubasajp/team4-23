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
	void Init();		//������
	void Move();		//�ړ�
	void Gravity();		//�d��
	void GetMoveDirection(bool* _dirArray);		//���E�㉺�̓����蔻��
	void UpdatePos();	//���W�̃A�b�v�f�[�g
	void Draw();		//�`��
	void Step();		//�����ł܂Ƃ߂�
	void InitScreen();						//�X�N���[�����W�̏�����
	void StepScreen();						//�X�N���[���̃��[���h���W
	void StepHitSquare();					//�����蔻��𒲐߂���ʒu
	void DebugStep();
	void StepOnJunp();
	void SwitchDebug();
	void  Dead_or_Alive();					//���̖��O�Ȃ��Ȃ��ɃZ���X����
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