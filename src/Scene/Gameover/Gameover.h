#pragma once
class Gameover
{
private:
	int x, y, handle;
	int soundhandle;
public:
	void Init();
	void Draw();
	//void Step();
};
extern Gameover gameover;;