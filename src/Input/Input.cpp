#include"DxLib.h"
#include"input.h"

#define KEY_BUF_LEN	(256)

//現在のフレームキー情報
char currntkeyBuf[KEY_BUF_LEN] = { 0 };
//前のフレームのキー情報
char preKeyBuf[KEY_BUF_LEN] = { 0 };
//入力制御初期化
void InitInput()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currntkeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}

void StepInput()
{
	//前のフレームキー情報変数に記録しておく
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		preKeyBuf[index] = currntkeyBuf[index];
	}
	//現在のキー情報を取得
	GetHitKeyStateAll(currntkeyBuf);
}

bool IsKyePush(int key_code)
{
	//前フレで押されてない　かつ　現振れで押されている
	if (preKeyBuf[key_code] == 0 && currntkeyBuf[key_code] == 1)
	{
		return true;	}

	return false;
}

bool IsKeykeep(int key_code)											//押し続ける
{
	if (preKeyBuf[key_code] == 1 && currntkeyBuf[key_code] == 1)
	{
		return true;
	}
	return false;
}
bool IsKeyRelease(int key_code)
{
	if (preKeyBuf[key_code] == 1 && currntkeyBuf[key_code] == 0)
	{
		return true;
	}
	return false;
}
bool IsKeyDown(int key_code)
{
	if (currntkeyBuf[key_code] == 1)
	{
		return true;
	}
	return false;
}