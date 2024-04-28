#include"DxLib.h"
#include"Character.h"
#include"../Input/Input.h"
#include"../Common.h"
const int MOVE_SPEED = 5;	//�ړ��X�s�[�h
const int JUNP_POWER = 20;	//�W�����v��
const int GRAVITY_SPEED = 1;		//��ɂ�����d��
const int SCREEN_SPEED = 10;	//�X�N���[���̈ړ���
const int GRAVITY_MAX = 8;	//�d�͂̏��
Character character;
void Character::Init()
{
	x = 550;		
	y = 800;					//�����l
	h = 32;			
	w = 32;
	GravitySpeed = 0;			//�d�͂̃X�s�[�h
	Next_x = x;					//���̍��W
	Next_y = y;					//���̍��W
	HitSquareX = 0;				//�}�b�v�ƃL�����̓����蔻���C�ӂɒ�������X
	HitSquareY = 0;				//�}�b�v�ƃL�����̓����蔻���C�ӂɒ�������Y
	handle = LoadGraph("Data/");
	Isuse = false;				
	Junpcount = 0;			//�W�����v�g�p�t���O
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
	
	//x��155�܂ōs�����瑀��s�\
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
	if (GravitySpeed >= GRAVITY_MAX)	//�d�͂̏�������߂�
	{
		GravitySpeed = GRAVITY_MAX;
		Next_y += GravitySpeed;
	}
	else	//����s���܂œ���
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
	character.Move();
	character.Gravity();
	character.StepScreen();
}
void Character::GetMoveDirection(bool* _dirArray) 		//���E�㉺�̓����蔻��
{
	// �E�����̃`�F�b�N
	if (Next_x > x) {
		_dirArray[3] = true;
	}
	// �������̃`�F�b�N
	if (Next_x < x) {
		_dirArray[2] = true;
	}
	// �������̃`�F�b�N
	if (Next_y > y) {
		_dirArray[1] = true;
	}
	// �������̃`�F�b�N
	if (Next_y < y) {
		_dirArray[0] = true;
	}
}
void Character::InitScreen() 						//�X�N���[�����W�̏�����
{
	ScreenX = x - SCREEN_SIZE_X / 2;
	ScreenY = 226;
	ScreenPosX = ScreenX;
	ScreenPosY = ScreenY;
}
void Character::StepScreen()						//�X�N���[���̃��[���h���W
{
	ScreenPosX = x - SCREEN_SIZE_X / 2;						//X���W�̃X�N���[��X���W��r
	ScreenPosY = y - SCREEN_SIZE_Y / 2;						//Y���W�̃X�N���[��Y���W��r

	DrawFormatString(100, 140, GetColor(255, 0, 0), "ScreenX=%d", ScreenX);
	DrawFormatString(100, 160, GetColor(255, 0, 0), "Screen=%d", ScreenY);
	////�X�N���[��X�����Ă��铮��������
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
void Character::StepHitSquare()					//�����蔻��𒲐߂���ʒu
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