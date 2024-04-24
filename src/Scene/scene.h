#pragma once
#include "DxLib.h"

enum SCENE_ID
{
	//�^�C�g���V�[����ID
	SCENE_INIT_TITLE = 100,
	SCENE_LOOP_TITLE,
	SCENE_FIN_TITLE,

	//�v���C�V�[����ID
	SCENE_INIT_PLAY = 200,
	SCENE_LOOP_PLAY,
	SCENE_FIN_PLAY,

	//���U���g�V�[����ID
	SCENE_INIT_RESULT = 300,
	SCENE_LOOP_RESULT,
	SCENE_FIN_RESULT,
};

extern SCENE_ID sceneID;
