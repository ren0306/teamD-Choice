//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL/DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../�Q�[�����C��/SceneMain.h"
#include "SceneKuria4.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneKuria4::CSceneKuria4()
{
}

//�f�X�g���N�^
CSceneKuria4::~CSceneKuria4()
{
}

//�o�g���N���A���������\�b�h
void CSceneKuria4::InitScene()
{



	//�N���A�I�u�W�F�N�g�쐬
	CObjKuria4* obj = new CObjKuria4();
	Objs::InsertObj(obj, OBJ_KURIA4, 10);
}

//�o�g���N���A���s�����\�b�h
void CSceneKuria4::Scene()
{

}