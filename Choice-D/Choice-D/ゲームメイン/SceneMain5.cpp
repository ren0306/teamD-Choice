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
#include "../�Q�[�����C��/SceneMain5.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneMain5::CSceneMain5()
{
}




//�e�X�g���N�^
CSceneMain5::~CSceneMain5()
{
}



//�Q�[�����C�����������\�b�h
void CSceneMain5::InitScene()
{

	//BGM��o�^
	//Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);
	//float Volume = Audio::VolumeMaster(-0.9f);//�}�X�^�[�{�����[����0.8������

	//Audio::Start(0);


	//�O���O���t�B�b�N�t�@�C����ǂݍ��݂O�Ԃɓo�^
	Draw::LoadImage(L"Main5.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 30, TEX_SIZE_512);
	//�G�Q��ǂݍ���2�Ԃɓo�^
	Draw::LoadImage(L"teki5.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"sentaku.png", 3, TEX_SIZE_512);

	CObjMain5* m = new CObjMain5();
	Objs::InsertObj(m, OBJ_MAIN5, 140);

	CObjBackGround5* b = new CObjBackGround5();
	Objs::InsertObj(b, OBJ_BACKGROUND5, 120);

	CObjDoor2* Door2 = new CObjDoor2();
	Objs::InsertObj(Door2, OBJ_DOOR2, 130);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);



}



//�Q�[�����C�����s�����\�b�h
void CSceneMain5::Scene()
{
}
