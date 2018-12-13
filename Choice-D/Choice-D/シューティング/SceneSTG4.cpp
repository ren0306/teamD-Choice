//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../�Q�[�����C��/SceneMain.h"
#include "Objteki4.h"
#include "SceneSTG4.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneSTG4::CSceneSTG4()
{
}

//�f�X�g���N�^
CSceneSTG4::~CSceneSTG4()
{
}

//�Q�[���V���[�e�B���O4���������\�b�h
void CSceneSTG4::InitScene()
{

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"STGBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(2, L"HeroBullet.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);

	//STG�I�u�W�F�N�g�쐬
	CObjSTG4* obj = new CObjSTG4();
	Objs::InsertObj(obj, OBJ_STG4, 10);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	//float Volumu = Audio::VolumeMaster(-0.8f); //�}�X�^�[�{�����[����0.8������B
	//Audio::Start(0);//���y�X�^�[�g

	//�w�i��ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"syu-haikei.png", 0, TEX_SIZE_512);

	//�G�S��ǂݍ���10�Ԃɓo�^
	Draw::LoadImage(L"teki4.png", 10, TEX_SIZE_512);

	//��l����ǂݍ���6�Ԃɓo�^
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//�G�e�ۂ�ǂݍ���30�Ԃɓo�^
	Draw::LoadImage(L"Bullet4.png", 30, TEX_SIZE_512);

	//��l���e�ۂ�ǂݍ���11�Ԃɓo�^
	Draw::LoadImage(L"HeroBullet.png", 11, TEX_SIZE_512);

	//�GHP�o�[�\��
	Draw::LoadImage(L"HP.png", 5, TEX_SIZE_512);

	//���ߍU��
	Draw::LoadImage(L"tamedama.png", 12, TEX_SIZE_512);


	//�w�i�I�u�W�F�N�g�쐬
	STGBackground* back = new STGBackground();
	Objs::InsertObj(back, OBJ_STGBACKGROUND, 20);

	CObjteki4* objb = new CObjteki4(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI4, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);

}

//�Q�[���V���[�e�B���O4���s�����\�b�h
void CSceneSTG4::Scene()
{

}

