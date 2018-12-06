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

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//
	if (m_mou_x >= 430 && m_mou_x <= 720 && m_mou_y >= 325 && m_mou_y <= 355)
	{
		Font::StrDraw(L"���������N���b�N�Ŏ���", 430, 330, 30, k);

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
	else
	{
		Font::StrDraw(L"�������N���b�N�Ŏ���", 430, 330, 30, k);

	}

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