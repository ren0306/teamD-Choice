//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawTexture.h"
#include "../GameL\DrawFont.h"
#include "../GameL\UserData.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../�Q�[�����C��/SceneMain3.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneMain3::CSceneMain3()
{
}




//�e�X�g���N�^
CSceneMain3::~CSceneMain3()
{
}



//�Q�[�����C�����������\�b�h
void CSceneMain3::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ��݂O�Ԃɓo�^
	Draw::LoadImage(L"Main3.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 2, TEX_SIZE_512);

	CObjBackGround3* b = new CObjBackGround3();
	Objs::InsertObj(b, OBJ_BACKGROUND3, 0);

	CObjDoor2* Door2 = new CObjDoor2();
	Objs::InsertObj(Door2, OBJ_DOOR2, 130);



}



//�Q�[�����C�����s�����\�b�h
void CSceneMain3::Scene()
{
}
