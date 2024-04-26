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
	x = 0;		
	y = 0;
	h = 32;			
	w = 32;
	GravitySpeed = 0;			//�d�͂̃X�s�[�h
	Next_x = 0;					//���̍��W
	Next_y - 0;					//���̍��W
	handle = LoadGraph("Data/");
	Isuse = false;				
	JunpIsUse = false;			//�W�����v�g�p�t���O
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
	ScreenPosX = x - SCREEN_SIZE_X / 2;						//X���W�̃X�N���[��X���W��r
	ScreenPosY = y - SCREEN_SIZE_Y / 2;						//Y���W�̃X�N���[��Y���W��r
	ScreenX = x - SCREEN_SIZE_X / 2;
	ScreenY = y - SCREEN_SIZE_Y / 2;
}
void Character::StepScreen()						//�X�N���[���̃��[���h���W
{
	ScreenX = x - SCREEN_SIZE_X / 2;						//X���W�̃X�N���[��X���W��r
	ScreenY = y - SCREEN_SIZE_Y / 2;						//Y���W�̃X�N���[��Y���W��r

	DrawFormatString(100, 140, GetColor(255, 0, 0), "ScreenX=%d", ScreenX);
	DrawFormatString(100, 160, GetColor(255, 0, 0), "Screen=%d", ScreenY);
	////�X�N���[��X�����Ă��铮��������
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