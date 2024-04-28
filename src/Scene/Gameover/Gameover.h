#pragma once
class Gameover
{
private:
	int x, y, handle;
public:
	void Init();
	void Draw();
	void Step();
};
extern Gameover gameover;;