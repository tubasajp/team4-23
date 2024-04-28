#pragma once
#include "../Input/Input.h"
class SceneTitle
{
private:
	//”wŒi‰æ‘œ
	int BackGround;

public:

	SceneTitle();
	~SceneTitle();

	//‰Šú‰»
	void Init();

	//’Êíˆ—
	void Step();

	//•`‰æ
	void Draw();

	//I—¹ˆ—
	void Fin();
};