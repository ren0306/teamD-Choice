//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../main.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneGameOver2::CSceneGameOver2()
{

}

//�f�X�g���N�^
CSceneGameOver2::~CSceneGameOver2()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameOver2::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"GAME OVER");

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGAMEOVER2* obj = new CObjGAMEOVER2();		//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAMEOVER2, 10);		//��l���I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneGameOver2::Scene()
{

}