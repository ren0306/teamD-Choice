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
#include "../�Q�[�����C��/SceneMain5.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneMain5::CSceneMain5()
{
}




//�e�X�g���N�^
CSceneMain5::~CSceneMain5()
{
}



//�Q�[�����C�����������\�b�h
void CSceneMain5::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ��݂O�Ԃɓo�^
	Draw::LoadImage(L"ss01.png", 0, TEX_SIZE_1024);
	Draw::LoadImage(L"door2.png", 2, TEX_SIZE_512);

	CObjBackGround2* b = new CObjBackGround2();
	Objs::InsertObj(b, OBJ_BACKGROUND2, 120);

	CObjDoor2* Door2 = new CObjDoor2();
	Objs::InsertObj(Door2, OBJ_DOOR2, 130);



}



//�Q�[�����C�����s�����\�b�h
void CSceneMain5::Scene()
{
}
