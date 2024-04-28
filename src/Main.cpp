//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include"Scene/scene.h"
#include"Common.h"
#include"Input/Input.h"
#include"Character/Character.h"
#include"Map/Map.h"
#include"PlaySceen/PlaySceen.h"
#include "Scene/sceneTitle.h"
SCENE_ID sceneID;
int StageIndex;

//�ݒ�t���[�����[�g (60FPS)
#define FRAME_RATE (60)

//1�t���[���̎��� (�~���b)
#define FRAME_TIME (1000/FRAME_RATE)


struct FrameRateInfo
{
	int currentTime;    //���݂̎���
	int lastFrameTime;  //�O��̃t���[�����s���̎���
	int count;          //�t���[���J�E���g�p
	int calcFpsTime;    //FPS���v�Z��������
	float fps;          //�v������FPS (�\���p)
};

//�t���[�����[�g���ϐ�
FrameRateInfo frameRateInfo;

//FPS�v�Z
void CalcFPS();

//FPS�\�� (�f�o�b�N�p)
void DrawFPS();

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���

	sceneID = SCENE_INIT_PLAY;
	//sceneID = SCENE_INIT_PLAY;


	//���͐��䏉����
	InitInput();


	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{

		Sleep(1);  //�V�X�e���ɏ�����Ԃ�

		//���݂̎��Ԃ��擾
		frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}


		//���݂̎��Ԃ��A�O��̃t���[�������
		//1000/60�~���b(1/60�b)�ȏ�o�߂��Ă����珈�������s����
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//�t���[�������J�E���g
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

			StepInput();

			//-----------------------------------------
			//��������Q�[���̖{�̂��������ƂɂȂ�
			switch (sceneID)
			{
			//-----------------------------------------
			case SCENE_INIT_TITLE:
			{
				scenetitle.InitTitle();
			}
				break;

			case SCENE_LOOP_TITLE:
			{
				scenetitle.StepTitle();
				scenetitle.DrawTitle();
			}
				break;

			case SCENE_FIN_TITLE:
			{
				scenetitle.FinTitle();
			}
				break;

			case SCENE_INIT_PLAY:
			{
				character.Init();
				character.InitScreen();
				map.ReadFilemap();
				map.InitMap();
				sceneID = SCENE_LOOP_PLAY;
			}
				break;

			case SCENE_LOOP_PLAY:
			{
				character.Step();
				playSceen.Character_Hit_Map();
				character.UpdatePos();
				character.Draw();
				map.DrawMap();
			}
				break;

			case SCENE_FIN_PLAY:
			{
				
			}
				break;

			case SCENE_INIT_RESULT:
			{
			
			}
				break;

			case SCENE_LOOP_RESULT:
			{
			
			}
				break;

			case SCENE_FIN_RESULT:
			{
				
			}
				break;

			default:
				break;

			}

			
			//-----------------------------------------

			//FPS�v�Z
			CalcFPS();

			//FPS�\��
			DrawFPS();


			//���[�v�̏I����
			//�t���b�v�֐�
			ScreenFlip();
		}
	}

	

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���

	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

	void CalcFPS()
	{
		//�O���FPS���v�Z�������Ԃ���̌o�ߎ��Ԃ����߂�
		int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

		//�O���FPS���v�Z�������Ԃ���
		//1�b�ȏ�o�߂��Ă�����FPS���v�Z����
		if (difTime > 1000)
		{
			//�t���[���񐔂��~���b�ɍ��킹��
			//�����܂ŏo�������̂�float�ɃL���X�g
			float frameCount = (float)(frameRateInfo.count * 1000.0f);

			//FPS�����߂�
			//���z�̐��l�� 60000 / 1000 �� 60 �ƂȂ�
			frameRateInfo.fps = frameCount / difTime;

			//�t���[�����[�g�J�E���g���N���A
			frameRateInfo.fps = frameCount / difTime;

			//�t���[�����[�g�J�E���g���N���A
			frameRateInfo.count = 0;

			//FPS���v�Z�������Ԃ��X�V
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
		}
	}

	//FPS�\�� (�f�o�b�N�p)
	void DrawFPS()
	{
		unsigned int color = GetColor(255, 30, 30);
		DrawFormatString(0, 0, color, "FPS[%.2f]", frameRateInfo.fps);

	}

