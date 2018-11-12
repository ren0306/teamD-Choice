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

//�Q�[���^�C�g�����������\�b�h
void CSceneSTG2::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"ss01.png", 0, TEX_SIZE_512);
	//�O���O���t�B�b�N�t�@�C����ǂݍ���10�Ԃɓo�^
	Draw::LoadImage(L"teki2.png", 10, TEX_SIZE_512);
	//�O���O���t�B�b�N�t�@�C����ǂݍ���6�Ԃɓo�^
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//STG�I�u�W�F�N�g�쐬
	CObjSTG2* obj = new CObjSTG2();
	Objs::InsertObj(obj, OBJ_STG2, 10);

	CObjBackGround2* p = new CObjBackGround2();
	Objs::InsertObj(p, OBJ_BACKGROUND2, 0);


	CObjteki2* objb = new CObjteki2(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI2, 50);


	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneSTG2::Scene()
{
}