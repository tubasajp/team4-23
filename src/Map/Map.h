#pragma once
#include"DxLib.h"
#define MAPCHIP_SIZW		(32)		//�}�b�v�`�b�v�̕�
#define MAPCHIP_SIZH		(32)		//�}�b�v�`�b�v�̏c
const int MAP_CHIP_X_NUM = 100;		//�}�b�v�`�b�v�̉�
const int MAP_CHIP_Y_NUM = 30;		//�}�b�v�`�b�v�̏c
class Map
{
private:
	int Maplevel = 0;
public:
	
	void InitMap();			
	void ReadFilemap();
	void DrawMap();
};
extern Map map;
extern int MapChipData1[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];		//��ڂ̃}�b�v