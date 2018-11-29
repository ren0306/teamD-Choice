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
#include "../�Q�[�����C��/SceneMain4.h"
#include "SceneNazo4.h"
#include "../GameHead.h"

//�R���X�g���N�^
CSceneNazo4::CSceneNazo4()
{
}

//�f�X�g���N�^
CSceneNazo4::~CSceneNazo4()
{
}

//�Q�[���^�C�g�����������\�b�h
void CSceneNazo4::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	//��@Font::SetStrTex(L"�Q�[�����n�߂�");
	Draw::LoadImage(L"Main4.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tenkey.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"��.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"���.png", 13, TEX_SIZE_512);


	/*Audio::LoadAudio(0, L"door-old-open1 .wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(1, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(1);*/
	//�I�u�W�F�N�g�쐬
	CObjTenkey4* key = new CObjTenkey4();
	Objs::InsertObj(key, OBJ_TENKEY4, 2);

	CObjBGN* BGN = new CObjBGN();
	Objs::InsertObj(BGN, OBJ_BGN, 1);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 0);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);


}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneNazo4::Scene()
{


}
