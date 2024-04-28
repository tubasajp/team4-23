#include "DxLib.h"
#include "SceneTitle.h"
#include "../Scene/scene.h"
#include "../Input/Input.h"

SceneTitle scenetitle;

SceneTitle::SceneTitle() 
{
	// �^�C�g���w�i�n���h��
	TitleBGHandle = 0;
	TitlePushHandle = 0;
	TitleNameHandle = 0;

	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		CloudImageHandle1[i] = 0;
		CloudImageHandle2[i] = 0;
	}
	

	//TitleSoundPath = 0;
}
SceneTitle::~SceneTitle() { FinTitle(); }

// �^�C�g���̏�����
void SceneTitle::InitTitle()
{
	SetMouseDispFlag(true);

	// �^�C�g���w�i�n���h��
	TitleBGHandle = LoadGraph(TITLE_BG_PATH);
	//�^�C�g���{�^���n���h��
	TitlePushHandle = LoadGraph(TITLE_PUSH_IMAGE_PATH);
	
	ChangeCnt = 100;

	//�^�C�g�����n���h��
	TitleNameHandle = LoadGraph(TITLE_NAME_PATH);

	//�_�n���h��
	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		CloudImageHandle1[i] = LoadGraph(TITLE_CLOUD_HANDLE1);
		CloudImageHandle2[i] = LoadGraph(TITLE_CLOUD_HANDLE2);

		//�_�̏������W
		CloudPosX[i] = GetRand(1080);
		CloudPosY[i] = GetRand(350);

		CloudPosX2[i] = GetRand(1080);
		CloudPosY2[i] = GetRand(350);
	}

	//�T�E���h�n���h��
	TitleSoundPath = LoadSoundMem(TITLE_BGM_PATH);
	PushSEPath = LoadSoundMem(BUTTON_SE_PATH);

	PlaySoundMem(TitleSoundPath, DX_PLAYTYPE_BACK, true);

	NextSceneCnt = 255;
	SceneFlag = false;

	// �^�C�g�����[�v��
	sceneID = SCENE_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle()
{
	GetMousePoint(&mouseX, &mouseY);

	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		CloudPosX[i] -= 2;
		CloudPosX2[i] -= 1;

		if (CloudPosX[i] < -64)
		{
			CloudPosX[i] = 1080 + GetRand(128);
			CloudPosY[i] = GetRand(350);
		}

		if (CloudPosX2[i] < -32)
		{
			CloudPosX2[i] = 1080 + GetRand(32*3);
			CloudPosY2[i] = GetRand(350);
		}

	}

	// Enter����������
	//if(InputKey::Push(KEY_INPUT_RETURN))
	//{
	//	// �^�C�g���V�[�����I��
	//	FinTitle();
	//}

	//�^�C�g���{�^������������
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		PlaySoundMem(PushSEPath, DX_PLAYTYPE_BACK,true);

		SceneFlag = true;
	}
	if (NextSceneCnt == 0)
	{
		//�^�C�g���V�[�����I��
		FinTitle();
	}

	if (SceneFlag == true)
	{
		NextSceneCnt-=4;
		if (NextSceneCnt < 0)
		{
			SceneFlag = false;
			NextSceneCnt = 0;
		}
	}
	
}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle()
{
	// �^�C�g���w�i�`��
	DrawGraph(0, 0, TitleBGHandle, true);

	//�^�C�g���{�^���`��
	DrawGraph(270, 300, TitlePushHandle, true);
	
	
	//�^�C�g�����`��
	DrawGraph(250, 100, TitleNameHandle, true);

	//�_�`��
	for (int i = 0; i < CLOUD_MAX_NUM; i++)
	{
		DrawRotaGraph(CloudPosX2[i], CloudPosY2[i], 1.0f, 0.0f, CloudImageHandle2[i], true);
		DrawRotaGraph(CloudPosX[i], CloudPosY[i], 1.0f, 0.0f, CloudImageHandle1[i], true);
	}


	if (NextSceneCnt == 0)
	{
		SetDrawBright(255, 255, 255);
	}
	else
	{
		SetDrawBright(NextSceneCnt, NextSceneCnt, NextSceneCnt);
	}
	
	
		
	
	
	//���W�m�F�p
   /* DrawFormatString(0, 55, GetColor(0, 0, 255),
		"�}�E�X���W:X:%d\n�}�E�X���W:Y:%d"
		, mouseX, mouseY);*/
}

// �^�C�g���I������
void SceneTitle::FinTitle()
{
	// �^�C�g���w�i�n���h��
	DeleteGraph(TitleBGHandle);

	//�^�C�g���{�^���n���h��
	DeleteGraph(TitlePushHandle);
	
	
	//BGM�n���h��
	DeleteSoundMem(TitleSoundPath);
	DeleteSoundMem(PushSEPath);
	
	// �v���C�V�[���Ɉړ�
	sceneID = SCENE_INIT_PLAY;
}
