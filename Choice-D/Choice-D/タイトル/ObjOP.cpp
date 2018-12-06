//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"



#include "../GameHead.h"
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
	m_and = 1.0f;
	m_f = true;
	m_cnt = 1;
}

//�A�N�V����
void CObjOP::Action()
{
	float k[4] = { 0.3,0.6,0.6,1.0f };
	float c[4] = { 1,1,1,1 };

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//
	if (m_mou_x >= 430 && m_mou_x <= 720 && m_mou_y >= 325 && m_mou_y <= 355)
	{

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
	if (m_cnt == 5)
	{
		return;
	}
	else
	Font::StrDraw(L"�������N���b�N�Ŏ���", 430, 330, 30, c);

}

//�h���[
void CObjOP::Draw()
{
	float c[4] = { 1,1,1,m_and };
	float k[4] = { 0.3,0.6,0.6,m_and };

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
		Font::StrDraw(L"��������Ď��̃X�e�[�W�ɍs�����@", 100, 100, 20, k);
		Font::StrDraw(L"�����}�E�X�ŃN���b�N���A��肪�o�Ă���̂�",200,200,20,k);
		Font::StrDraw(L"���������Ď��ɍs�����I",300,300,20,k);
		Font::StrDraw(L"�������A�����ԈႦ��Ǝ��Ԃ�30�b����̂Œ���",400,400,20,k);

	}

	if (m_cnt == 4)
	{
		Font::StrDraw(L"�G�Ƃ̐퓬�ɂ���",100,100,20,k);
		Font::StrDraw(L"�G�Ɛ키�ɂ͓G���N���b�N����ƁA�키���m�F�����̂�",100,200,20,k);
		Font::StrDraw(L"�u�͂��v�������Ɛ킦��",200,100,20,k);
		Font::StrDraw(L"�G�Ɛ키�Ɛ킢�̉��ő��̓G�Ɍ����邩������Ȃ��̂�",300,100,20,k);
		Font::StrDraw(L"�G�Ɛ키�̂͂Ȃ�ׂ������悤",100,300,20,k);

	}

	if (m_cnt == 5)
	{
		Font::StrDraw(L"�������ł����牺�́u�E�o�����݂�v���N���b�N����",100,200,20, k);
		Font::StrDraw(L"�E�o�����悤�I",200,100,20, k);

	}

	RECT_F src;
	RECT_F dst;

	float d[4] = { 1.0f,1.0f,1.0f,m_and };
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