//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include "GameL/Audio.h"
#include "ObjBGM.h"
#include "�Q�[�����C��/SceneMain.h"




//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBGM::Init()
{
	//�}�E�X�̈ʒu
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//�A�N�V����
void CObjBGM::Action()
{
	//Audio::LoadAudio(0, L"titleBGM.wav", SOUND_TYPE::BACK_MUSIC);
	//BGM��o�^
	//Audio::LoadAudio(1, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//���y���̓ǂݍ���
	//Audio::LoadAudio(2, L"STGBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//Audio::Start(0);
	if (m_BGM == 1)
	{
		//Audio::Start(1);
	}
	float k[4] = { 0.3,0.6,0.6,0 };
	float c[4] = { 1,1,1,0 };

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

//�h���[
void CObjBGM::Draw()
{



}