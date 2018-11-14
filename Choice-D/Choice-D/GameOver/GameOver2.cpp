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
	//�O���O���t�B�b�N�摜��ǂݍ���15�Ԃɓo�^
	Draw::LoadImage(L"teki3.png", 15, TEX_SIZE_512);

	CObjGameOvergamen* ga6 = new CObjGameOvergamen();
	Objs::InsertObj(ga6, OBJ_GAMEOVERGAMEN, 24);

	//�O���O���t�B�b�N�摜��ǂݍ���14�Ԃɓo�^
	Draw::LoadImage(L"teki3.png", 14, TEX_SIZE_512);

	CObjGameOvergamen* ga5 = new CObjGameOvergamen();
	Objs::InsertObj(ga5, OBJ_GAMEOVERGAMEN, 23);

	//�O���O���t�B�b�N�摜��ǂݍ���13�Ԃɓo�^
	Draw::LoadImage(L"teki3.png", 13, TEX_SIZE_512);

	CObjGameOvergamen* ga4 = new CObjGameOvergamen();
	Objs::InsertObj(ga4, OBJ_GAMEOVERGAMEN, 22);

	//�O���O���t�B�b�N�摜��ǂݍ���12�Ԃɓo�^
	Draw::LoadImage(L"teki3.png", 12, TEX_SIZE_512);

	CObjGameOvergamen* ga3 = new CObjGameOvergamen();
	Objs::InsertObj(ga3, OBJ_GAMEOVERGAMEN, 21);

	//�O���O���t�B�b�N�摜��ǂݍ���9�Ԃɓo�^
	Draw::LoadImage(L"yarareta.png", 9, TEX_SIZE_512);

	CObjGameOvergamen* ga2 = new CObjGameOvergamen();
	Objs::InsertObj(ga2, OBJ_GAMEOVERGAMEN, 20);

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