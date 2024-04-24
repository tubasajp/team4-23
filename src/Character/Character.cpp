#include"DxLib.h"
#include"Character.h"
#include"../Input/Input.h"
const int MOVE_SPEED = 5;	//�ړ��X�s�[�h
const int JUNP_POWER = 20;	//�W�����v��
const int GRAVITY = 1;		//��ɂ�����d��
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
	GravitySpeed += GRAVITY;
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
