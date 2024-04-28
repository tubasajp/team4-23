#include"DxLib.h"
#include"../Character/Character.h"
#include"../Map/Map.h"
#include"../PlaySceen/PlaySceen.h"
#include"../Collision/Collision.h"
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
		if (character.GetHitSquareY() > 45)
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
		if (character.GetHitSquareY() > 45)
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