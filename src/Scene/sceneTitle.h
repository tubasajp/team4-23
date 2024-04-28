#pragma once

// �摜�p�X
// �^�C�g���w�i
#define TITLE_BG_PATH "Data/TitleImage/TitleImage2.png"
#define TITLE_PUSH_IMAGE_PATH "Data/TitleImage/PushImage100.png"

#define TITLE_NAME_PATH "Data/TitleImage/���u���^�C�g��.png"

#define TITLE_CLOUD_HANDLE1 "Data/TitleImage/cloud1.png"
#define TITLE_CLOUD_HANDLE2 "Data/TitleImage/cloud2.png"

//�^�C�g��BGM
#define TITLE_BGM_PATH "Data/Sound/TitleSceneBGM.mp3"
#define BUTTON_SE_PATH "Data/Sound/ButtonSound.mp3"

#define CLOUD_MAX_NUM (4)

class SceneTitle 
{
private:
	// �^�C�g���w�i�n���h��
	int TitleBGHandle;

	int TitlePushHandle;
	int ChangeCnt;

	int TitleNameHandle;

	int CloudImageHandle1[CLOUD_MAX_NUM];
	int CloudImageHandle2[CLOUD_MAX_NUM];

	int CloudPosX[CLOUD_MAX_NUM], CloudPosY[CLOUD_MAX_NUM];
	int CloudPosX2[CLOUD_MAX_NUM], CloudPosY2[CLOUD_MAX_NUM];

	int mouseX, mouseY;

	int TitleSoundPath;
	int PushSEPath;

	int NextSceneCnt;

	bool SceneFlag;

public:
	SceneTitle();
	~SceneTitle();
	
	// �^�C�g���̏�����
	void InitTitle();

	// �^�C�g���ʏ폈��
	void StepTitle();

	// �^�C�g���`�揈��
	void DrawTitle();

	// �^�C�g���I������
	void FinTitle();
};

extern SceneTitle scenetitle;