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
#include "SceneKuria.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneKuria::CSceneKuria()
{
}

//�f�X�g���N�^
CSceneKuria::~CSceneKuria()
{
}

//�Q�[���^�C�g�����������\�b�h
void CSceneKuria::InitScene()
{
	
	
	
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjKuria* obj = new CObjKuria();
	Objs::InsertObj(obj, OBJ_KURIA, 10);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneKuria::Scene()
{

}
