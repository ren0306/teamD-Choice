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
CSceneED_Roll::CSceneED_Roll()
{
}

//�f�X�g���N�^
CSceneED_Roll::~CSceneED_Roll()
{
}

//�Q�[���G���f�B���O1���������\�b�h
void CSceneED_Roll::InitScene()
{
	Audio::LoadAudio(0, L"BADENDBGM .wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(0);

	//�G���f�B���O1�I�u�W�F�N�g�쐬
	CObjED_Roll* obj = new CObjED_Roll();
	Objs::InsertObj(obj, OBJ_ED_ROLL, 10);
}

//�Q�[���G���f�B���O1���s�����\�b�h
void CSceneED_Roll::Scene()
{
}
