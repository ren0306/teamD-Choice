//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "�Q�[�����C��/SceneMain.h"
#include "Objteki5.h"
#include "SceneSTG5.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneSTG5::CSceneSTG5()
{
}

//�f�X�g���N�^
CSceneSTG5::~CSceneSTG5()
{
}

//�Q�[���V���[�e�B���O5���������\�b�h
void CSceneSTG5::InitScene()
{
	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"STGBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(2, L"HeroBullet.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);
	//STG�I�u�W�F�N�g�쐬
	CObjSTG5* obj = new CObjSTG5();
	Objs::InsertObj(obj, OBJ_STG5, 10);

	//�w�i��ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"syu-haikei.png", 0, TEX_SIZE_512);

	//�G�T��ǂݍ���10�Ԃɓo�^
	Draw::LoadImage(L"teki5.png", 10, TEX_SIZE_512);

	//��l����ǂݍ���6�Ԃɓo�^
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//�`���[�W�G�t�F�N�g��ǂݍ���8�Ԃɓo�^
	Draw::LoadImage(L"ChargeEffect.png", 8, TEX_SIZE_512);

	//�G�e�ۂ�ǂݍ���30�Ԃɓo�^
	Draw::LoadImage(L"Bullet5.png", 30, TEX_SIZE_512);

	//��l���e�ۂ�ǂݍ���11�Ԃɓo�^
	Draw::LoadImage(L"HeroBullet.png", 11, TEX_SIZE_512);

	//�GHP�o�[�\��
	Draw::LoadImage(L"HP.png", 5, TEX_SIZE_512);

	//���ߍU��
	Draw::LoadImage(L"tamedama.png", 12, TEX_SIZE_512);



	//�w�i�I�u�W�F�N�g�쐬
	STGBackground* back = new STGBackground();
	Objs::InsertObj(back, OBJ_STGBACKGROUND, 20);

	CObjteki5* objb = new CObjteki5(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI5, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);
	
	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);

	CObjChargeEffect*ef = new CObjChargeEffect(-100, -100);
	Objs::InsertObj(ef, OBJ_CHARGE_EFFECT, 145);
}

//�Q�[���V���[�e�B���O5���s�����\�b�h
void CSceneSTG5::Scene()
{

}
