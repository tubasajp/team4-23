#include "SE.h"
#include <DxLib.h>

// 効果音ラボ

void SE::Init(int n) {
	switch (n) {
	case SE1:
		m_SEhndl = LoadSoundMem("Data/SE/ButtonSound.mp3");
	case SE2:
		m_SEhndl = LoadSoundMem("Data/SE/ゲージ回復2.mp3");
	case SE3:
		m_SEhndl = LoadSoundMem("Data/SE/ドアを蹴破る.mp3");
	case SE4:
		m_SEhndl = LoadSoundMem("Data/SE/パワーチャージ.mp3");
	case SE5:
		m_SEhndl = LoadSoundMem("Data/SE/ビームガン.mp3");
	case SE6:
		m_SEhndl = LoadSoundMem("Data/SE/噛みつく.mp3");
	case SE7:
		m_SEhndl = LoadSoundMem("Data/SE/教会の鐘1.mp3");
	case SE8:
		m_SEhndl = LoadSoundMem("Data/SE/驚く.mp3");
	case SE9:
		m_SEhndl = LoadSoundMem("Data/SE/決定ボタンを押す8.mp3");
	case SE10:
		m_SEhndl = LoadSoundMem("Data/SE/決定ボタンを押す39.mp3");
	case SE11:
		m_SEhndl = LoadSoundMem("Data/SE/犬の鳴き声2.mp3");
	case SE12:
		m_SEhndl = LoadSoundMem("Data/SE/水のしたたる洞窟.mp3");
	case SE13:
		m_SEhndl = LoadSoundMem("Data/SE/水滴1.mp3");
	case SE14:
		m_SEhndl = LoadSoundMem("Data/SE/打ち上げ花火1.mp3");
	case SE15:
		m_SEhndl = LoadSoundMem("Data/SE/打撃6.mp3");
	case SE16:
		m_SEhndl = LoadSoundMem("Data/SE/大勢で拍手.mp3");
	case SE17:
		m_SEhndl = LoadSoundMem("Data/SE/大砲1.mp3");
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