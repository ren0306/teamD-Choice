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
#include "SceneKuria5.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneKuria5::CSceneKuria5()
{
}

//�f�X�g���N�^
CSceneKuria5::~CSceneKuria5()
{
}

//�o�g���N���A���������\�b�h
void CSceneKuria5::InitScene()
{



	//�N���A�I�u�W�F�N�g�쐬
	CObjKuria5* obj = new CObjKuria5();
	Objs::InsertObj(obj, OBJ_KURIA5, 10);
}

//�o�g���N���A���s�����\�b�h
void CSceneKuria5::Scene()
{

}