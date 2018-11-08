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

//�Q�[���^�C�g�����������\�b�h
void CSceneSTG3::InitScene()
{

	//STG�I�u�W�F�N�g�쐬
	CObjSTG3* obj = new CObjSTG3();
	Objs::InsertObj(obj, OBJ_STG3, 10);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^
	Draw::LoadImageW(L"dou.png", 0, TEX_SIZE_512);

	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_STG3, 10);

	CObjBackGround* p = new CObjBackGround();
	Objs::InsertObj(p, OBJ_BACKGROUND, 0);


	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^
	Draw::LoadImageW(L"teki3.png", 10, TEX_SIZE_512);

	CObjteki3* objb = new CObjteki3(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI1, 50);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneSTG3::Scene()
{

}

