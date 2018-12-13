//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"
#include "../GameHead.h"
#include "../GameL/Audio.h"
#include "ObjOP.h"
#include "../�Q�[�����C��/SceneMain.h"




//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjOP::Init()
{
	//�}�E�X�̈ʒu
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 0.0f;
	m_f = true;
	m_cnt = 1;
}

//�A�N�V����
void CObjOP::Action()
{
	//Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//Audio::Start(0);
	float k[4] = { 0.3,0.6,0.6,m_and };
	float c[4] = { 1,1,1,m_and };

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//�N���b�N����
	if (m_mou_x >= 450 && m_mou_x <= 740 && m_mou_y >= 470 && m_mou_y <= 500)
	{
		if (m_cnt >= 5)
		{
			return;
		}

		if (m_mou_l == true)
		{

			if (m_flag == true)
			{
				m_cnt++;
				m_flag = false;

			}
		}
		else
		{
			m_flag = true;
		}
	}
	if (m_cnt >= 5)
	{
		return;
	}
	else
	{
		Font::StrDraw(L"�������N���b�N�Ŏ���", 450, 480, 30, c);
	}
}

//�h���[
void CObjOP::Draw()
{
	float c[4] = { 1,1,1,m_and };
	float k[4] = { 0.7,0.7,0.0,m_and };
	float d[4] = { 1.0f,1.0f,1.0f,m_and };

	RECT_F src;
	RECT_F dst;

	//�t�F�[�h�C���E�t�F�[�h�A�E�g
	if (m_f == true)
	{
		m_and += 0.1f;
		if (m_and >= 1.0)
		{
			m_and = 1.0f;
			m_f = false;
		}

	}


	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 565 && m_mou_x < 750 && m_mou_y>540 && m_mou_y < 570)
	{
		Font::StrDraw(L"���E�o�����݂�", 570, 550, 32, c);
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneMain());
		}
	}
	else
	{
		Font::StrDraw(L"�E�o�����݂�", 570, 550, 32, c);
	}
	if (m_cnt==1)
	{
		Font::StrDraw(L"�����X�^�[�ɓ|����A�ڊo�߂��瓴�A�ɂ���", 115, 200, 30, k);
		Font::StrDraw(L"�������ԓ��ɂ�������E�o�����悤�I", 170, 250, 30, k);

	}
	
	if (m_cnt==2)
	{

		Font::StrDraw(L"��������E�o����ɂ́A���������", 170, 200, 30, k);
		Font::StrDraw(L"�G��|����������܂���", 175, 250, 30, k);
	}
	

	if (m_cnt == 3)
	{
		Font::StrDraw(L"��������Ď��̃X�e�[�W�ɍs�����@", 150, 100, 30, c);
		Font::StrDraw(L"�����}�E�X�ŃN���b�N���A��肪�o�Ă���̂�",70,180,30,k);
		Font::StrDraw(L"���������Ď��ɍs�����I",70,260,30,k);
		Font::StrDraw(L"�������A�����ԈႦ��Ǝ��Ԃ�30�b����̂Œ���",70,340,30,k);
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 763.0f;
		src.m_bottom = 567.0f;

		dst.m_top = 0.0f+380;
		dst.m_left = 50.0f;
		dst.m_right =420.0f+30;
		dst.m_bottom = 320.0f+300;
		Draw::Draw(1, &src, &dst, d, 0.0f);

	}

	if (m_cnt == 4)
	{
		Font::StrDraw(L"�G�Ƃ̐퓬�ɂ���",250,100,35,c);
		Font::StrDraw(L"�G�Ɛ키�ɂ͓G���N���b�N����ƁA�키���m�F�����̂�",70,180,25,k);
		Font::StrDraw(L"�u�͂��v�������Ɛ킦��",70,260,25,k);
		Font::StrDraw(L"�G�Ɛ키�Ɛ킢�̉��ő��̓G�Ɍ����邩������Ȃ��̂�",70,340,25,k);
		Font::StrDraw(L"�G�Ɛ키�̂͂Ȃ�ׂ������悤",450,420,25,k);
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 763.0f;
		src.m_bottom = 567.0f;

		dst.m_top = 0.0f + 380;
		dst.m_left = 50.0f;
		dst.m_right = 420.0f + 30;
		dst.m_bottom = 320.0f + 300;
		Draw::Draw(2, &src, &dst, d, 0.0f);

	}

	if (m_cnt == 5)
	{
		Font::StrDraw(L"�������ł����牺�́u�E�o�����݂�v���N���b�N����",60,230,30, k);
		Font::StrDraw(L"�E�o�����悤�I",300,300,35, k);

	}
	if (m_cnt >= 6)
	{
		Scene::SetScene(new CSceneMain());

	}
	//Choice�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 455.0f;
	src.m_bottom = 180.0f;

	dst.m_top = 150.0f;
	dst.m_left = 150.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 400.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);



}