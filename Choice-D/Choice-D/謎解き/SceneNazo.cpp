//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../�Q�[�����C��/SceneMain.h"
#include "SceneNazo.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneNazo::CSceneNazo()
{
}

//�f�X�g���N�^
CSceneNazo::~CSceneNazo()
{
}

//�Q�[���^�C�g�����������\�b�h
void CSceneNazo::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	//��@Font::SetStrTex(L"�Q�[�����n�߂�");

	Draw::LoadImageW(L"tenkey.png", 2, TEX_SIZE_512);


	//�I�u�W�F�N�g�쐬
	CObjTenkey* key = new CObjTenkey();
	Objs::InsertObj(key, OBJ_TENKEY, 10);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneNazo::Scene()
{
}
