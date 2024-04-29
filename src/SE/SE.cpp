#include "SE.h"
#include <DxLib.h>

// ���ʉ����{

void SE::Init(int n) {
	switch (n) {
	case SE1:
		m_SEhndl = LoadSoundMem("Data/SE/ButtonSound.mp3");
	case SE2:
		m_SEhndl = LoadSoundMem("Data/SE/�Q�[�W��2.mp3");
	case SE3:
		m_SEhndl = LoadSoundMem("Data/SE/�h�A���R�j��.mp3");
	case SE4:
		m_SEhndl = LoadSoundMem("Data/SE/�p���[�`���[�W.mp3");
	case SE5:
		m_SEhndl = LoadSoundMem("Data/SE/�r�[���K��.mp3");
	case SE6:
		m_SEhndl = LoadSoundMem("Data/SE/���݂�.mp3");
	case SE7:
		m_SEhndl = LoadSoundMem("Data/SE/����̏�1.mp3");
	case SE8:
		m_SEhndl = LoadSoundMem("Data/SE/����.mp3");
	case SE9:
		m_SEhndl = LoadSoundMem("Data/SE/����{�^��������8.mp3");
	case SE10:
		m_SEhndl = LoadSoundMem("Data/SE/����{�^��������39.mp3");
	case SE11:
		m_SEhndl = LoadSoundMem("Data/SE/���̖���2.mp3");
	case SE12:
		m_SEhndl = LoadSoundMem("Data/SE/���̂������铴�A.mp3");
	case SE13:
		m_SEhndl = LoadSoundMem("Data/SE/���H1.mp3");
	case SE14:
		m_SEhndl = LoadSoundMem("Data/SE/�ł��グ�ԉ�1.mp3");
	case SE15:
		m_SEhndl = LoadSoundMem("Data/SE/�Ō�6.mp3");
	case SE16:
		m_SEhndl = LoadSoundMem("Data/SE/�吨�Ŕ���.mp3");
	case SE17:
		m_SEhndl = LoadSoundMem("Data/SE/��C1.mp3");
	default:
		break;
	}


}

void SE::Step() {
	PlaySoundMem(m_SEhndl, DX_PLAYTYPE_BACK, true);

}

void SE::Fin() {
	DeleteSoundMem(m_SEhndl);

}