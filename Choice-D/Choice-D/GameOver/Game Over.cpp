//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneManager.h"
#include "../GameL\DrawFont.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;
//�g�p�w�b�_�[
#include "../main.h"
#include "../GameHead.h"


//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[���I�[�o�[���������\�b�h
void CSceneGameOver::InitScene()
{
	//�Q�[���I�[�o�[1�摜��ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"GameOver kuuhuku.png", 3, TEX_SIZE_512);

	CObjGameOvergamen* ga = new CObjGameOvergamen();
	Objs::InsertObj(ga, OBJ_GAMEOVERGAMEN, 20);

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"GAME OVER");

	//�Q�[���I�[�o�[�I�u�W�F�N�g1�쐬
	CObjGAMEOVER* obj = new CObjGAMEOVER();		//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);		//��l���I�u�W�F�N�g�o�^
}

//�Q�[���I�[�o�[1���s�����\�b�h
void CSceneGameOver::Scene()
{

}