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
#include "SceneSousagamen.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneSousagamen::CSceneSousagamen()
{
}

//�f�X�g���N�^
CSceneSousagamen::~CSceneSousagamen()
{
}

//�����ʏ��������\�b�h
void CSceneSousagamen::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"�Q�[�����n�߂�");
	Draw::LoadImage(L"ki-bo-do.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"mausu.png", 1, TEX_SIZE_512);
	//Draw::LoadImage(L"tenbin.png", 1, TEX_SIZE_512);

	//�����ʃI�u�W�F�N�g�쐬
	CObjSousagamen* s = new CObjSousagamen();
	Objs::InsertObj(s, OBJ_SOUSAGAMEN, 10);
}

//�����ʎ��s�����\�b�h
void CSceneSousagamen::Scene()
{

}
