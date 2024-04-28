#include "ClassTrap.h"
#include "../../Character/Character.h"
#include <DXLib.h>


const int HndlSize = 32;	// �摜�̃T�C�Y

// �N���X�̃g�Q�g���b�v
void CTrap::Init() {
	m_xpos = 0.0f;
	m_ypos = 0.0f;
	m_size = 1.0f;
	m_angle = 0.0f;
	m_hndl = LoadGraph("../../Data/Map/�g�Q.png");
	m_is_Damage = true;
}

void CTrap::Step() {

	// �v���C���[�Ƀ_���[�W��^����ꍇ,�^���Ȃ��ꍇ�̏���
	if (m_is_Damage == true) {

	}
	else if (m_is_Damage == false) {

	}

}

void CTrap::Draw() {
	// ��(test�p)
	/*
	DrawBox((int)m_xpos - character.GetScreenX(), (int)m_ypos - character.GetScreenY(),
		(int)m_xpos + HndlSize - character.GetScreenX(), (int)m_ypos + HndlSize - character.GetScreenY(),
		GetColor(0, 255, 0), true);
	*/


	DrawRotaGraph((int)m_xpos + HndlSize / 2, (int)m_ypos + HndlSize / 2, m_size, m_angle, m_hndl, true);
}

void CTrap::Fin() {

}


void CTrap::DrawSerif(float x, float y, int R, int G, int B, char serif) {
	DrawFormatString((int)x, (int)y, GetColor(R, G, B), &serif);
}


void CTrap::SetPosX(float x) {
	m_xpos = x;
}

void CTrap::SetPosY(float y) {
	m_ypos = y;
}