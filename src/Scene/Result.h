#pragma once
#include "../Input/Input.h"
class SceneResult
{
private:
	//”wŒi‰æ‘œ
	int BackGround;

public:

	SceneResult();
	~SceneResult();

	//‰Šú‰»
	void Init();

	//’Êíˆ—
	void Step();

	//•`‰æ
	void Draw();

	//I—¹ˆ—
	void Fin();
};