//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

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

//�Q�[���^�C�g�����������\�b�h
void CSceneSTG5::InitScene()
{

	//STG�I�u�W�F�N�g�쐬
	CObjSTG5* obj = new CObjSTG5();
	Objs::InsertObj(obj, OBJ_STG5, 10);

	//�w�i��ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"syu-haikei.png", 20, TEX_SIZE_512);

	//�G�S��ǂݍ���1�Ԃɓo�^
	Draw::LoadImage(L"teki5.png", 30, TEX_SIZE_512);

	//��l����ǂݍ���6�Ԃɓo�^
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_STG5, 10);

	CObjBackGround* q = new CObjBackGround();
	Objs::InsertObj(q, OBJ_BACKGROUND, 20);

	CObjteki5* objb = new CObjteki5(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI5, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneSTG5::Scene()
{

}
