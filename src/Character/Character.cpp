#include"DxLib.h"
#include"Character.h"
#include"../Input/Input.h"
#include"../Common.h"
#include"../Scene/Scene.h"
const int MOVE_SPEED = 5;	//�ړ��X�s�[�h
const int JUNP_POWER = 20;	//�W�����v��
const int GRAVITY_SPEED = 1;		//��ɂ�����d��
const int SCREEN_SPEED = 10;	//�X�N���[���̈ړ���
const int GRAVITY_MAX = 8;	//�d�͂̏��
const int Deth_Line = 950;	
int CharaLeftPath[3];
int ChararightPath[3];
Character character;
void Character::Init()
{
	x = 384;//2400
	y = 660;	//270				//�����l
	h = 32;			
	w = 32;
	GravitySpeed = 0;			//�d�͂̃X�s�[�h
	Next_x = x;					//���̍��W
	Next_y = y;					//���̍��W
	HitSquareX = 0;				//�}�b�v�ƃL�����̓����蔻���C�ӂɒ�������X
	HitSquareY = 0;				//�}�b�v�ƃL�����̓����蔻���C�ӂɒ�������Y
	Hp = 1;
	walkLeftFramecount = -1;
	walkrightFramecount = -1;
	handle = LoadGraph("Data/playerImage/playerstand.png");
	Isuse = false;
	DebugMode = true;
	Junpcount = 0;			//�W�����v�g�p�t���O
	backhandle = LoadGraph("Data/TitleImage/BackGround3.png");
	CharaLeftPath[0]= LoadGraph("Data/playerImage/playerdashleft1.png");
	CharaLeftPath[1] = LoadGraph("Data/playerImage/playerdashleft2.png");
	CharaLeftPath[2] = LoadGraph("Data/playerImage/playerdashleft3.png");
	ChararightPath[0]= LoadGraph("Data/playerImage/playerdash1.png");
	ChararightPath[1] = LoadGraph("Data/playerImage/playerdash2.png");
	ChararightPath[2] = LoadGraph("Data/playerImage/playerdash3.png");
}
void Character::Move()
{
	DrawFormatString(100, 70, GetColor(255, 0, 0), "GravitySpeed %d ",GravitySpeed);
	int a = 0;
	if (IsKeyKeep(KEY_INPUT_LSHIFT))
	{
		a = 4;
	}
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
			walkLeftFramecount++;
			Next_x -= MOVE_SPEED-a;
		}
		if (IsKeyRelease(KEY_INPUT_A))
		{
			walkLeftFramecount = -1;
		}
		
	}
	
	if (IsKeyKeep(KEY_INPUT_D))
	{
		walkrightFramecount++;
		Next_x += MOVE_SPEED-a;
	}
	if (IsKeyRelease(KEY_INPUT_D))
	{
		walkrightFramecount = -1;
	}

}
void Character::Stepwalk()
{

	if (walkLeftFramecount == 0)
	{
		handle = CharaLeftPath[0];
	}
	if (walkLeftFramecount == 15)
	{
		handle = CharaLeftPath[1];
	}
	if (walkLeftFramecount == 25)
	{
		handle = CharaLeftPath[2];
	}
	if (walkLeftFramecount > 26)
	{
		walkLeftFramecount = 0;
	}

	if (walkrightFramecount == 0)
	{
		handle = ChararightPath[0];
	}
	if (walkrightFramecount == 15)
	{
		handle = ChararightPath[1];
	}
	if (walkrightFramecount == 25)
	{
		handle = ChararightPath[2];
	}
	if (walkrightFramecount >26)
	{
		walkrightFramecount = 0;

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
	
	DrawRotaGraph(x - ScreenX + 16, y - ScreenY + 16, 1.0, 0.0, handle, true);
	DrawFormatString(100, 50, GetColor(255, 0, 0), "x = %d  y = %d", x,y);
	DrawFormatString(100, 500, GetColor(255, 0, 0), "walkLeftFramecount %d ", walkLeftFramecount);
	DrawFormatString(100, 520, GetColor(255, 0, 0), "walkrightFramecount %d ", walkrightFramecount);
	
	
}
void Character::UpdatePos()
{
	x = Next_x;
	y = Next_y;
}
void Character::Step()
{
	character.Move();
	Stepwalk();
	character.Gravity();
	character.StepScreen();
	Dead_Line();
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
	ScreenX =310;
	ScreenY = 216;
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
void Character::DrawPlayHaikei()
{
	DrawGraph(0, 0, backhandle, true);
}