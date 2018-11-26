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
#include "../�Q�[�����C��/SceneMain2.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneMain2::CSceneMain2()
{
}




//�e�X�g���N�^
CSceneMain2::~CSceneMain2()
{
}



//�Q�[�����C�����������\�b�h
void CSceneMain2::InitScene()
{

	//BGM��o�^
	Audio::LoadAudio(1, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);
	float Volume = Audio::VolumeMaster(-0.9f);//�}�X�^�[�{�����[����0.8������

	Audio::Start(1);
	//�O���O���t�B�b�N�t�@�C����ǂݍ��݂O�Ԃɓo�^
	Draw::LoadImage(L"ss01.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 1, TEX_SIZE_512);
	//�G�Q��ǂݍ���2�Ԃɓo�^
	Draw::LoadImage(L"teki2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"sentaku.png", 3, TEX_SIZE_512);

	CObjMain2* m = new CObjMain2();
	Objs::InsertObj(m, OBJ_MAIN2, 140);

	CObjBackGround2* b = new CObjBackGround2();
	Objs::InsertObj(b, OBJ_BACKGROUND2, 120);

	CObjDoor2* Door2 = new CObjDoor2();
	Objs::InsertObj(Door2, OBJ_DOOR2, 130);



}



//�Q�[�����C�����s�����\�b�h
void CSceneMain2::Scene()
{
}
