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

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^
	Draw::LoadImageW(L"teki1.png", 10, TEX_SIZE_512);

	CObjteki1* objb = new CObjteki1(200,10);
	Objs::InsertObj(objb, OBJ_TEKI1, 50);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneSTG::Scene()
{
}

