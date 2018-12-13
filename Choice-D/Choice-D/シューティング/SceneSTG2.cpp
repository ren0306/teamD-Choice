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
#include "Objteki2.h"
#include "SceneSTG2.h"
#include "../GameHead.h"
#include "ObjHero.h"

//�R���X�g���N�^
CSceneSTG2::CSceneSTG2()
{
}

//�f�X�g���N�^
CSceneSTG2::~CSceneSTG2()
{
}

//�Q�[���V���[�e�B���O2���������\�b�h
void CSceneSTG2::InitScene()
{
	//�w�i��ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"syu-haikei.png", 0, TEX_SIZE_512);

	//�G�Q��ǂݍ���10�Ԃɓo�^
	Draw::LoadImage(L"teki2.png", 10, TEX_SIZE_512);

	//��l����ǂݍ���6�Ԃɓo�^
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//�G�e�ۂ�ǂݍ���30�Ԃɓo�^
	Draw::LoadImage(L"Bullet2.png", 30, TEX_SIZE_512);

	//��l���e�ۂ�ǂݍ���11�Ԃɓo�^
	Draw::LoadImage(L"HeroBullet.png", 11, TEX_SIZE_512);

	//�GHP�o�[�\��
	Draw::LoadImage(L"HP.png", 5, TEX_SIZE_512);

	//���ߍU��
	Draw::LoadImage(L"tamedama.png", 12, TEX_SIZE_512);


	//STG�I�u�W�F�N�g�쐬
	CObjSTG2* obj = new CObjSTG2();
	Objs::InsertObj(obj, OBJ_STG2, 10);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	//float Volumu = Audio::VolumeMaster(-0.8f); //�}�X�^�[�{�����[����0.8������B
	//Audio::Start(0);//���y�X�^�[�g

	//�w�i�I�u�W�F�N�g�쐬
	STGBackground* back = new STGBackground();
	Objs::InsertObj(back, OBJ_STGBACKGROUND, 20);


	CObjteki2* objb = new CObjteki2(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI2, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);


}

//�Q�[���V���[�e�B���O2���s�����\�b�h
void CSceneSTG2::Scene()
{
}