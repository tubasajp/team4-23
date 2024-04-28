#pragma once
#include "../Timer/Timer.h"
class ScenePlay
{
private:
	//”wŒi‰æ‘œ
	int BackGround[2];
	int Tuta[2];
	int BG_PosY[2];//”wŒi‰æ‘œ‚ÌˆÚ“®—p•Ï”

	Timer timer;

public:

	ScenePlay();
	~ScenePlay();

	//‰Šú‰»
	void Init();

	//’Êíˆ—
	void Step();

	//•`‰æ
	void Draw();

	//I—¹ˆ—
	void Fin();
};
