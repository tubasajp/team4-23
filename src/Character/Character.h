#pragma once
#include"DxLib.h"
class Character
{
private:
	int x, y, h, w, handle,GravitySpeed,Next_x,Next_y;
	bool Isuse;
	bool JunpIsUse;
public:
	void Init();		//������
	void Move();		//�ړ�
	void Gravity();		//�d��
	void UpdatePos();	//���W�̃A�b�v�f�[�g
	void Draw();		//�`��
	void Step();		//�����ł܂Ƃ߂�
};
extern Character character;