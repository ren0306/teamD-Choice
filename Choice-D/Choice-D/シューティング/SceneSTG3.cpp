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
#include "Objteki3.h"
#include "SceneSTG3.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneSTG3::CSceneSTG3()
{
}

//�f�X�g���N�^
CSceneSTG3::~CSceneSTG3()
{
}

//�Q�[���V���[�e�B���O3���������\�b�h
void CSceneSTG3::InitScene()
{

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"STGBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(2, L"HERO�e�ہ@.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(3, L"����.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);

	//STG�I�u�W�F�N�g�쐬
	CObjSTG3* obj = new CObjSTG3();
	Objs::InsertObj(obj, OBJ_STG3, 10);


	//�w�i��ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"syu-haikei.png", 0, TEX_SIZE_512);

	//�G�R��ǂݍ���10�Ԃɓo�^
	Draw::LoadImage(L"teki3.png", 10, TEX_SIZE_512);

	//��l����ǂݍ���6�Ԃɓo�^
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//�`���[�W�G�t�F�N�g��ǂݍ���8�Ԃɓo�^
	Draw::LoadImage(L"ChargeEffect.png", 8, TEX_SIZE_512);

	//�G�e�ۂ�ǂݍ���30�Ԃɓo�^
	Draw::LoadImage(L"Bullet3.png", 30, TEX_SIZE_512);

	//��l���e�ۂ�ǂݍ���11�Ԃɓo�^
	Draw::LoadImage(L"HeroBullet.png", 11, TEX_SIZE_512);

	//�GHP�o�[�\��
	Draw::LoadImage(L"HP.png", 5, TEX_SIZE_512);

	//���ߍU��
	Draw::LoadImage(L"tamedama.png", 12, TEX_SIZE_512);

	//���j�G�t�F�N�g�Q��
	Draw::LoadImage(L"EnemyEX.png", 2, TEX_SIZE_512);

	//�w�i�I�u�W�F�N�g�쐬
	STGBackground* back = new STGBackground();
	Objs::InsertObj(back, OBJ_STGBACKGROUND, 20);

	CObjteki3* objb = new CObjteki3(200, 80);
	Objs::InsertObj(objb, OBJ_TEKI3, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);

	CObjChargeEffect*ef = new CObjChargeEffect(-100, -100);
	Objs::InsertObj(ef, OBJ_CHARGE_EFFECT, 145);

	CObjEnemyEX* eef = new CObjEnemyEX(0, 0);
	Objs::InsertObj(eef, OBJ_EX, 200);

}

//�Q�[���V���[�e�B���O3���s�����\�b�h
void CSceneSTG3::Scene()
{

}

