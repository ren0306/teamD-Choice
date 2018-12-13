//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL/DrawTexture.h"
#include "../GameL\Audio.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../�Q�[�����C��/SceneMain.h"
#include "SceneTitle.h"
#include "../GameHead.h"
#include "../ObjBGM.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{
}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{
}

//�Q�[���^�C�g�����������\�b�h
void CSceneTitle::InitScene()
{
	Audio::LoadAudio(0, L"titleBGM.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::Start(0);

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"�Q�[�����n�߂�");
	Draw::LoadImage(L"Title.png", 0, TEX_SIZE_512);
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneTitle::Scene()
{
}
