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

	Draw::LoadImage(L"tenkey.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"door.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"doukutu.png", 0, TEX_SIZE_512);
	//�I�u�W�F�N�g�쐬
	CObjTenkey* key = new CObjTenkey();
	Objs::InsertObj(key, OBJ_TENKEY, 10);

	CObjBGN* BGN = new CObjBGN();
	Objs::InsertObj(BGN, OBJ_BGN, 1);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 0);

	
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneNazo::Scene()
{
}
