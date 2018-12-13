//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawTexture.h"
#include "../GameL\DrawFont.h"
#include "../GameL\UserData.h"
#include "../GameL/Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "../GameHead.h"
#include "../�^�C�g��/SceneTitle.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{
}




//�e�X�g���N�^
CSceneMain::~CSceneMain()
{
}



//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//BGM��o�^
	Audio::LoadAudio(1, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::Start(1);
	//�O���O���t�B�b�N�t�@�C����ǂݍ��݂O�Ԃɓo�^
	Draw::LoadImage(L"doukutu.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door.png", 1, TEX_SIZE_512);
	//�G�P��ǂݍ���2�Ԃɓo�^
	Draw::LoadImage(L"teki1.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"sentaku.png", 3, TEX_SIZE_512);


	Font::SetStrTex(L"�������I��");


	



	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_MAIN, 140);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 120);

	CObjDoor* Door = new CObjDoor();
	Objs::InsertObj(Door, OBJ_DOOR, 130);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);



}



//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{
}
