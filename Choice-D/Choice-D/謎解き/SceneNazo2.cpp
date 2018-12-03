//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL\DrawTexture.h"
#include "../GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../�Q�[�����C��/SceneMain.h"
#include "SceneNazo2.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneNazo2::CSceneNazo2()
{
}

//�f�X�g���N�^
CSceneNazo2::~CSceneNazo2()
{
}

//�Q�[���^�C�g�����������\�b�h
void CSceneNazo2::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	//��@Font::SetStrTex(L"�Q�[�����n�߂�");
	Draw::LoadImage(L"ss01.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tenkey.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"��.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"���.png", 13, TEX_SIZE_512);


	//�I�u�W�F�N�g�쐬
	CObjTenkey2* key = new CObjTenkey2();
	Objs::InsertObj(key, OBJ_TENKEY2, 2);

	CObjBGN2* BGN2 = new CObjBGN2();
	Objs::InsertObj(BGN2, OBJ_BGN, 1);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 0);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);


}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneNazo2::Scene()
{


}
