#pragma once

// �N���X�̃g�Q�g���b�v
class CTrap {
private:
	float m_xpos = 0.0f, m_ypos = 0.0f;	// ���W
	float m_size = 1.0f;				// �傫��
	float m_angle = 0.0f;				// �p�x
	char m_serif = 0;					// �Z���t
	int m_hndl;							// �摜�n���h��
	bool m_is_Damage = true;			// �v���C���[�Ƀ_���[�W��^���邩�ǂ���(true=�_���[�W��^����)

public:

	void Init();						// ������
	void Step();						// �ʏ�
	void Draw();						// �`��
	void Fin();							// �I��

	void DrawSerif(float x, float y,	// �Z���t�`��
		int R, int G, int B, char serif);

	void SetPosX(float x);				// ���W�ݒ�
	void SetPosY(float y);
	float GetPosX() { return m_xpos; }	// ���W�擾
	float GetPosY() { return m_ypos; }

};