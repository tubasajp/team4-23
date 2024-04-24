#include "DxLib.h"
#include "Input.h"

#define KEY_BUF_LEN (256)

//現在フレームのキー情報
char currentKeyBuf[KEY_BUF_LEN] = { 0 };

//前フレームのキー情報
char preKeyBuf[KEY_BUF_LEN] = { 0 };

//入力制御初期化
void InitInput()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currentKeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}

//入力制御ステップ
//他のStepより早く呼ぶ
void StepInput()
{
	//前フレームのキー情報変数に記録しておく
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		preKeyBuf[index] = currentKeyBuf[index];
	}
	//現在のキー情報を取得
	GetHitKeyStateAll(currentKeyBuf);

}

bool IsKeyPush(int Key_code)
{
	//前フレで押されてないか現フレで押されている
	if (preKeyBuf[Key_code] == 0 && currentKeyBuf[Key_code] == 1)
	{
		return true;
	}
	//押されていないので false
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