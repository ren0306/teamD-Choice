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
#include "SceneOP.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneOP::CSceneOP()
{
}

//�f�X�g���N�^
CSceneOP::~CSceneOP()
{
}

//�Q�[��OP���������\�b�h
void CSceneOP::InitScene()
{


	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"�Q�[�����n�߂�");
	
	//OP�I�u�W�F�N�g�쐬
	CObjOP* obj = new CObjOP();
	Objs::InsertObj(obj, OBJ_OP, 10);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneOP::Scene()
{
}
