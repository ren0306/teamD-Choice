//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../�Q�[�����C��/SceneMain.h"
#include "Objteki1.h"
#include "SceneSTG.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneSTG::CSceneSTG()
{
}

//�f�X�g���N�^
CSceneSTG::~CSceneSTG()
{
}

//�Q�[���^�C�g�����������\�b�h
void CSceneSTG::InitScene()
{
	

	//STG�I�u�W�F�N�g�쐬
	CObjSTG* obj = new CObjSTG();
	Objs::InsertObj(obj, OBJ_STG, 10);

	

	//�w�i��ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"syu-haikei.png", 20, TEX_SIZE_512);
	
	//�G�P��ǂݍ���1�Ԃɓo�^
	Draw::LoadImage(L"teki1.png", 10, TEX_SIZE_512);

	//��l����ǂݍ���6�Ԃɓo�^
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//�G�e�ۂ�ǂݍ���30�Ԃɓo�^
	Draw::LoadImage(L"Bullet1.png", 30, TEX_SIZE_512);

	CObjBackGround* q = new CObjBackGround();
	Objs::InsertObj(q, OBJ_BACKGROUND, 20);

	CObjteki1* objb = new CObjteki1(200,10);
	Objs::InsertObj(objb, OBJ_TEKI1, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneSTG::Scene()
{
}

