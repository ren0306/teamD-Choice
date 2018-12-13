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
#include "../�Q�[�����C��/SceneMain4.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneMain4::CSceneMain4()
{
}




//�e�X�g���N�^
CSceneMain4::~CSceneMain4()
{
}



//�Q�[�����C�����������\�b�h
void CSceneMain4::InitScene()
{

	//BGM��o�^
	//Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);
	//float Volume = Audio::VolumeMaster(-0.9f);//�}�X�^�[�{�����[����0.8������

	//Audio::Start(0);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^
	Draw::LoadImage(L"Main4.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 20, TEX_SIZE_512);
	//�G�Q��ǂݍ���2�Ԃɓo�^
	Draw::LoadImage(L"teki4.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"sentaku.png", 3, TEX_SIZE_512);

	CObjMain4* m = new CObjMain4();
	Objs::InsertObj(m, OBJ_MAIN4, 140);

	CObjBackGround4* b = new CObjBackGround4();
	Objs::InsertObj(b, OBJ_BACKGROUND4, 120);

	CObjDoor2* Door2 = new CObjDoor2();
	Objs::InsertObj(Door2, OBJ_DOOR2, 130);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);




}



//�Q�[�����C�����s�����\�b�h
void CSceneMain4::Scene()
{
}
