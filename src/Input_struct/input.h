#pragma once
#pragma once

void InitInput();					//入力制御初期化

void StepInput();					//入力制御ステップ //他のStepより早く呼ぶ	

bool IsKyePush(int key_code);		//今押された

bool IsKeykeep(int key_code);		//押し続ける

bool IsKeyRelease(int key_code);	//

bool IsKeyDown(int key_code);		//離したとき
