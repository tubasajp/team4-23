#pragma once
#include"DxLib.h"

#define CLOUD_MAX_NUM (4)

class Title
{
private :
	int x, y, handle;
	int TitleButtonHandle;
	int TitleNameHandle;
	int cloudHandle[CLOUD_MAX_NUM];
	int cloudx[CLOUD_MAX_NUM], cloudy[CLOUD_MAX_NUM], TitleCloudHandle[CLOUD_MAX_NUM];

	int soundhandle;
	int ButtonSEPath;

	int NextSceneCnt;

	bool SceneFlag;
public:
	void InitTitle();
	void DrawTitle();
};
extern Title title;