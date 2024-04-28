#include "Trap.h"
#include <DXLib.h>


void CTrap::Init() {
	m_xpos = 0.0f;
	m_ypos = 0.0f;
	m_size = 1.0f;
	m_angle = 0.0f;
	m_hndl = LoadGraph("../../Data/Map/ƒgƒQ.png");
}

void CTrap::Step() {

	Draw();
}

void CTrap::Draw() {
	DrawRotaGraph(m_xpos, m_ypos, m_size, m_angle, m_hndl, true);
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
	m_xpos = y;
}