#pragma once
const int TRAP_MAX = 10;
struct Trap
{
	int x, y, h, w, handle, trapPosX, trapPosY;
	bool IsUse;
};
void trapInit();						// ������
void trapStep();						// �ʏ�
void trapDraw();						// �`��
extern Trap  trap[TRAP_MAX];