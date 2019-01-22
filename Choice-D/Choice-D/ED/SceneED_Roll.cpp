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
	Audio::LoadAudio(0, L"titleBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(0);

	//�G�P��ǂݍ���1�Ԃɓo�^
	Draw::LoadImage(L"teki1.png", 1, TEX_SIZE_512);
	//�G�Q��ǂݍ���2�Ԃɓo�^
	Draw::LoadImage(L"teki2.png", 2, TEX_SIZE_512);
	//�G�R��ǂݍ���3�Ԃɓo�^
	Draw::LoadImage(L"teki3.png", 3, TEX_SIZE_512);
	//�G�S��ǂݍ���4�Ԃɓo�^
	Draw::LoadImage(L"teki4.png", 4, TEX_SIZE_512);
	//�G�T��ǂݍ���5�Ԃɓo�^
	Draw::LoadImage(L"teki5.png", 5, TEX_SIZE_512);

	//�G���f�B���O1�I�u�W�F�N�g�쐬
	CObjED_Roll* obj = new CObjED_Roll();
	Objs::InsertObj(obj, OBJ_ED_ROLL, 10);
}

//�Q�[���G���f�B���O1���s�����\�b�h
void CSceneED_Roll::Scene()
{
}
