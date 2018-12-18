//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL/Audio.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../�Q�[�����C��/SceneMain.h"
#include "SceneED1.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneED1::CSceneED1()
{
}

//�f�X�g���N�^
CSceneED1::~CSceneED1()
{
}

//�Q�[���G���f�B���O1���������\�b�h
void CSceneED1::InitScene()
{
	Audio::LoadAudio(0, L"BADENDBGM .wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(0);

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"�Q�[�����n�߂�");

	//�G���f�B���O1�I�u�W�F�N�g�쐬
	CObjED1* obj = new CObjED1();
	Objs::InsertObj(obj, OBJ_ED1, 10);
}

//�Q�[���G���f�B���O1���s�����\�b�h
void CSceneED1::Scene()
{
}
