#pragma once
const int TRAP_MAX = 15;
struct Trap
{
	int x, y, h, w, handle, trapPosX, trapPosY;
	bool IsUse,sitaIsMove, ueIsMove, hidariIsMove, migiIsMove;
};
void trapInit();						// ������
void trapStep();						// �ʏ�
void trapDraw();						// �`��
void TrapMove();
extern Trap  trap[TRAP_MAX];