#include "DxLib.h"
#include "Input.h"

#define KEY_BUF_LEN (256)

//���݃t���[���̃L�[���
char currentKeyBuf[KEY_BUF_LEN] = { 0 };

//�O�t���[���̃L�[���
char preKeyBuf[KEY_BUF_LEN] = { 0 };

//���͐��䏉����
void InitInput()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currentKeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}

//���͐���X�e�b�v
//����Step��葁���Ă�
void StepInput()
{
	//�O�t���[���̃L�[���ϐ��ɋL�^���Ă���
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		preKeyBuf[index] = currentKeyBuf[index];
	}
	//���݂̃L�[�����擾
	GetHitKeyStateAll(currentKeyBuf);

}

bool IsKeyPush(int Key_code)
{
	//�O�t���ŉ�����ĂȂ������t���ŉ�����Ă���
	if (preKeyBuf[Key_code] == 0 && currentKeyBuf[Key_code] == 1)
	{
		return true;
	}
	//������Ă��Ȃ��̂� false
	return false;
}

bool IsKeyKeep(int Key_code)
{
	if (preKeyBuf[Key_code] == 1 && currentKeyBuf[Key_code] == 1)
	{
		return true;
	}
	return false;

}

bool IsKeyRelease(int Key_code)
{
	if (preKeyBuf[Key_code] == 1 && currentKeyBuf[Key_code] == 0)
	{
		return true;
	}
	return false;

}

bool IsKeyDown(int Key_code)
{
	if (currentKeyBuf[Key_code] == 0 && currentKeyBuf[Key_code] == 0)
	{
		return true;
	}
	return false;

}