#include"DxLib.h"
#include"../Character/Character.h"
#include"../Map/Map.h"
#include"../PlaySceen/PlaySceen.h"
#include"../Collision/Collision.h"
#include"../Trap/Trap.h"
#include"../MapChipGoal/MapChipGoal.h"
#include"../Scene/Scene.h"
#include"../kumo/Enemykumo.h"

const int SQUARE_Y = 5;		//���݂̈ʒu����Y���̓����蔻��͈̔͂�ݒ肷��
const int SQUARE_X = 10;	//���݂̈ʒu����X���̓����蔻��͈̔͂�ݒ肷��
PlaySceen playSceen;
void PlaySceen::Character_Hit_Map()
{
	DrawFormatString(100, 180, GetColor(255, 0, 0), "HitSquareX=%d", character.GetHitSquareX());
	DrawFormatString(100, 200, GetColor(255, 0, 0), "HitSquareY=%d", character.GetHitSquareY());
	character.StepHitSquare();
	for (int y = character.GetHitSquareY() - SQUARE_Y; character.GetHitSquareY() + SQUARE_Y > y;y++)
	{
		//�z��𒴂�����
		if (character.GetHitSquareY() > 28)
			continue;
		//�z��𒴂�����
		if (character.GetHitSquareY() < 1)
			continue;
		for (int x = character.GetHitSquareX() - SQUARE_X; character.GetHitSquareX() + SQUARE_X > x; x++)
		{
			// ���������l����
				// �ǂ̕����ɐi��ł������`�F�b�N
				// ��Player�N���X�ɐi�ޕ������`�F�b�N����֐����������Ă��܂��B

			bool dirArray[4] = { false,false,false,false };
			character.GetMoveDirection(dirArray);
			// ���������l����
			// ��`�̓����蔻��p�̃f�[�^������
			// �v���C���[�̏��
			int Ax = character.GetPosX();
			int Ay = character.GetPosY();
			int Aw = character.GetPosW();
			int Ah = character.GetPosH();

			// �I�u�W�F�N�g�̏��
			int Bx = x * 32;
			int By = y * 32;
			int Bw = MAPCHIP_SIZW;
			int Bh = MAPCHIP_SIZH;

			if (MapChipData1[y][x] == 3)
				continue;
			{
				Ay = character.GetPosY();
				Ax = character.GetNextPosX();
				if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh))
				{
					if (dirArray[2]) {
						// ���������l����
						// �߂荞�ݗʂ��v�Z����
						int overlap = Bx + Bw - Ax;
						character.SetNextPosX(Ax + overlap);
					}
					// �E�����̏C��
					//�}���I�̉E��
					if (dirArray[3]) {
						// ���������l����
						// �߂荞�ݗʂ��v�Z����
						int overlap = Ax + Aw - Bx;
						character.SetNextPosX(Ax - overlap);
					}
				}
			}

		}
	}
	for (int y = character.GetHitSquareY() - SQUARE_Y; character.GetHitSquareY() + SQUARE_Y > y; y++)
	{
		//�z��𒴂�����
		if (character.GetHitSquareY() > 28)
			continue;
		//�z��𒴂�����
		if (character.GetHitSquareY() < 1)
			continue;
		for (int x = character.GetHitSquareX() - SQUARE_X; character.GetHitSquareX() + SQUARE_X > x; x++)
		{
			
			bool dirArray[4] = { false,false,false,false };
			character.GetMoveDirection(dirArray);

			// ���������l����
			// ��`�̓����蔻��p�̃f�[�^������
			// �v���C���[�̏��
			int Ax = character.GetPosX();
			int Ay = character.GetPosY();
			int Aw = character.GetPosW();
			int Ah = character.GetPosH();

			// �I�u�W�F�N�g�̏��
			int Bx = x * 32;
			int By = y * 32;
			int Bw = MAPCHIP_SIZW;
			int Bh = MAPCHIP_SIZH;
			if (MapChipData1[y][x] == 3)
				continue;

			{
				DrawBox(Bx-character.GetScreenX(), By- character.GetScreenY(), Bx + Bw- character.GetScreenX(), By + Bh- character.GetScreenY(), GetColor(255, 255, 255), false);
				DrawBox(Ax - character.GetScreenX(), Ay - character.GetScreenY(), Ax + Aw - character.GetScreenX(), Ay + Ah - character.GetScreenY(), GetColor(255, 255, 255), false);
				DrawFormatString(100, 90, GetColor(255, 0, 0), " GetJunpcount= %d ", character.GetJunpcount());
				// ��Y�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
				Ay = character.GetNextPosY();
				Ax = character.GetNextPosX();

				// �������Ă��邩�`�F�b�N
				if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
					// �������̏C��
					//�}���I�̍���
					if (dirArray[0]) {
						// ���������l����
						// �߂荞�ݗʂ��v�Z����
						character.SetGravitySpeed(0);
						
						int overlap = By + Bh - Ay;
						character.SetNextPosY((Ay + overlap));
					}
					// �E�����̏C��
					//�}���I�̉E��
					if (dirArray[1]) {
						// ���������l����
						// �߂荞�ݗʂ��v�Z����
						int overlap = Ay + Ah - By;
						character.SetNextPosY (Ay - overlap);
						character.SetJunpcount(0);		//����ɐG�ꂽ�烊�Z�b�g����
						character.StepOnJunp();			//����ɐG��Ă��Ȃ��ƃW�����v�ł��Ȃ�
					}
				}
			}
		}
	}
}
void PlaySceen::Character_Hit_Trap()
{
	for (int i = 0; i < TRAP_MAX; i++)
	{
		int Ax = character.GetPosX();
		int Ay = character.GetPosY();
		int Aw = character.GetPosW();
		int Ah = character.GetPosH();

		int Bx = trap[i].x;
		int By =trap[i].y;
		int Bw = trap[i].w;
		int Bh = trap[i].h;
		DrawBox(Bx - character.GetScreenX(), By - character.GetScreenY(), Bx + Bw - character.GetScreenX(), By + Bh - character.GetScreenY(), GetColor(255, 255, 255), false);
		if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh))
		{
			DrawFormatString(100, 150, GetColor(255, 0, 0), " �g�Q�ƃL�����N�^�[�q�b�g = %d ", character.GetHp());
			character.SetHp(0);
		}
	}
}
void PlaySceen::Character_Hit_Goal()
{
	for (int i = 0; i < TRAP_MAX; i++)
	{
		int Ax = character.GetPosX();
		int Ay = character.GetPosY();
		int Aw = character.GetPosW();
		int Ah = character.GetPosH();

		int Bx = goal.GetX();
		int By = goal.GetY();
		int Bw = goal.GetW();
		int Bh = goal.GetH();
		DrawBox(Bx - character.GetScreenX(), By - character.GetScreenY(), Bx + Bw - character.GetScreenX(), By + Bh - character.GetScreenY(), GetColor(255, 255, 255), false);
		if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh))
		{
			DrawFormatString(100, 170, GetColor(255, 0, 0), "�S�[��");
			sceneID = SCENE_ID_INIT_CLEAR;
		}
	}
}
void PlaySceen::Map_erase()
{
	int Ax = character.GetPosX();
	int Ay = character.GetPosY();
	if (Ax > 1568 && Ax<1762 &&Ay > 800)
	{
		DrawFormatString(100, 240, GetColor(255, 0, 0), "��������܂�");
		//���������
		MapChipData1[29][49] = 3;
		MapChipData1[29][50] = 3;
		MapChipData1[29][51] = 3;
		MapChipData1[29][52] = 3;
		MapChipData1[29][53] = 3;
		MapChipData1[29][54] = 3;
	}
}
void PlaySceen::Character_Hit_Enemykumo()
{
	for (int i = 0; i < KUMO_MAX; i++)
	{
		int Ax = character.GetPosX();
		int Ay = character.GetPosY();
		int Aw = character.GetPosW();
		int Ah = character.GetPosH();

		int Bx = kumo[i].x;
		int By = kumo[i].y;
		int Bw = kumo[i].h;
		int Bh = kumo[i].w;
		DrawBox(Bx - character.GetScreenX(), By - character.GetScreenY(), Bx + Bw - character.GetScreenX(), By + Bh - character.GetScreenY(), GetColor(255, 255, 255), false);
		if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh))
		{
			DrawFormatString(100, 270, GetColor(255, 0, 0), "�_�q�b�g");
			character.SetHp(0);
		}
	}
}
void PlaySceen::Step()
{
	Character_Hit_Map();
	Character_Hit_Trap();
	Character_Hit_Goal();
	Character_Hit_Enemykumo();
	Map_erase();
}