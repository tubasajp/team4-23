#pragma once

struct Trap
{
	int x, y, h, w, handle;
	bool IsUse;
};
void Init();						// ������
void Step();						// �ʏ�
void Draw();						// �`��