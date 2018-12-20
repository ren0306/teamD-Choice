//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL\DrawTexture.h"
#include "../GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "../�Q�[�����C��/SceneMain3.h"
#include "SceneNazo3.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneNazo3::CSceneNazo3()
{
}

//�f�X�g���N�^
CSceneNazo3::~CSceneNazo3()
{
}

//�Q�[���^�C�g�����������\�b�h
void CSceneNazo3::InitScene()
{
	Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"delete.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(2, L"warning.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(3, L"next.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(4, L"keyboardSE.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);

	//�o�͂����镶���̃O���t�B�b�N���쐬
	//��@Font::SetStrTex(L"�Q�[�����n�߂�");
	Draw::LoadImage(L"Main3.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tenkey.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"��.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"���3.png", 13, TEX_SIZE_512);


	//�I�u�W�F�N�g�쐬
	CObjTenkey3* key = new CObjTenkey3();
	Objs::InsertObj(key, OBJ_TENKEY3, 2);

	CObjBGN3* BGN = new CObjBGN3();
	Objs::InsertObj(BGN, OBJ_BGN, 1);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 0);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);


}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneNazo3::Scene()
{


}
