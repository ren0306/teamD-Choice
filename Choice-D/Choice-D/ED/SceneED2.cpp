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
#include "SceneED2.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneED2::CSceneED2()
{
}

//�f�X�g���N�^
CSceneED2::~CSceneED2()
{
}

//�Q�[���^�C�g�����������\�b�h
void CSceneED2::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"�Q�[�����n�߂�");

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjED2* obj = new CObjED2();
	Objs::InsertObj(obj, OBJ_ED2, 10);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneED2::Scene()
{
}
