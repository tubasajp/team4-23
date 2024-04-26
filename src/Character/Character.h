#pragma once
#include"DxLib.h"
class Character
{
private:
	int x, y, h, w, handle,GravitySpeed,Next_x,Next_y, ScreenX, ScreenY, ScreenPosX, ScreenPosY;
	bool Isuse;
	bool JunpIsUse;
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