//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjTenkey5.h"
#include "../�Q�[�����C��/SceneMain5.h"
#include "../GameL/Audio.h"

#include <stdio.h>
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTenkey5::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_f = true;
	m_andf = true;
	cnt = 0;
	m_and = 0.0f;
	m_flag[1] = false;
	m_flag[2] = false;
	m_flag[3] = false;
	m_flag[4] = false;
	m_flag[5] = false;
	m_flag[6] = false;
	m_flag[7] = false;
	m_flag[8] = false;
	m_flag[9] = false;
	m_misscnt = 100.f;
}

//�A�N�V����
void CObjTenkey5::Action()
{

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	/*
	789
	456
	123
	*/
	Tenkey();
}

//�h���[
void CObjTenkey5::Draw()
{	//��
	float f[4] = { 1.0f,1.0f,1.0f,1.0f };
	//��
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	//���F
	float s[4] = { 1.0f,1.0f,0.0f,1.0f };
	//��
	float o[4] = { 0.5f,0.0f,1.0f,1.0f };
	Font::StrDraw(L"���̖���2���̐����̂ݓ��͉\�ł�", 160, 550, 30, r);

	RECT_F src;
	RECT_F dst;

	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, f);

	//���C���ɖ߂�
	if (m_mou_x >= 37 && m_mou_x <= 290 && m_mou_y >= 33 && m_mou_y <= 60)
	{
		Font::StrDraw(L"[�����C����ʂɖ߂�]", 32, 32, 30, f);
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneMain5);



		}
	}
	else
	{
		Font::StrDraw(L"[���C����ʂɖ߂�]", 32, 32, 30, f);
		//BGM��o�^
	}
	//��������������ɂ̏ꍇ3��
	if (m_mou_x >= 5 && m_mou_x <= 232 && m_mou_y >= 445 && m_mou_y <= 470)
	{
		Font::StrDraw(L"[����������{�^��]", 0, 450, 25, s);

		if (m_mou_l == true)
		{
			Anser();
			cnt = 0;
			if (m_f == true)
			{
				if (m_ok == true)
				{
					if (m_Nazocnt == 4)
					{
						Scene::SetScene(new CSceneED3);
					}
					else
					{
						Scene::SetScene(new CSceneED2);
					}
				}
				else
				{
					m_flag[1] = false;
					m_flag[2] = false;
					m_flag[3] = false;
					m_flag[4] = false;
					m_flag[5] = false;
					m_flag[6] = false;
					m_flag[7] = false;
					m_flag[8] = false;
					m_flag[9] = false;
					m_num[1] = 0;
					m_num[2] = 0;
					m_num[3] = 0;
					m_num[4] = 0;
					m_num[5] = 0;
					m_num[6] = 0;
					m_num[7] = 0;
					m_num[8] = 0;
					m_num[9] = 0;
					m_miss = true;
					m_f = false;
				}
			}
		}
		else
		{
			m_f = true;
		}
	}
	else
	{
		Font::StrDraw(L"[��������{�^��]", 0, 450, 30, s);
	}
	if (m_miss == true)
	{
		Font::StrDraw(L"-30�b", 40, 50, 30, r);
		m_misscnt--;
		if (m_misscnt <= 0)
		{
			m_miss = false;
			m_misscnt = 100.f;
		}
	}


	//[���ׂč폜]��������
	if (m_mou_x >= 500 && m_mou_x <= 666 && m_mou_y >= 442 && m_mou_y <= 470)
	{
		Font::StrDraw(L"[�����ׂč폜]", 500, 450, 30, f);

		if (m_mou_l == true)
		{
			m_flag[1] = false;
			m_flag[2] = false;
			m_flag[3] = false;
			m_flag[4] = false;
			m_flag[5] = false;
			m_flag[6] = false;
			m_flag[7] = false;
			m_flag[8] = false;
			m_flag[9] = false;
			m_num[1] = 0;
			m_num[2] = 0;
			m_num[3] = 0;
			m_num[4] = 0;
			m_num[5] = 0;
			m_num[6] = 0;
			m_num[7] = 0;
			m_num[8] = 0;
			m_num[9] = 0;

			cnt = 0;
		}
	}
	else
	{
		Font::StrDraw(L"[���ׂč폜]", 500, 450, 30, f);
	}

	//�e���L�[�o�́i�؂���ʒu�j
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 1024.0f;
	//�e���L�[�o�́i�o�͈ʒu�j
	dst.m_top = 50.0f + 300;
	dst.m_left = 0.0f + 255;
	dst.m_right = 400.0f + 100;
	dst.m_bottom = 250.0f + 300;
	Draw::Draw(2, &src, &dst, f, 0.0f);


	//�𓚏o�́i�؂���ʒu�j
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1008.0f;
	src.m_bottom = 647.0f;
	//�𓚏o�́i�o�͈ʒu�j
	dst.m_top = 60.0f + 100;
	dst.m_left = 0.0f;
	dst.m_right = 700.0f + 300;
	dst.m_bottom = 450.0f + 250;
	Draw::Draw(12, &src, &dst, f, 0.0f);

	//���o�́i�؂���ʒu�j
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 980.0f;
	src.m_bottom = 647.0f;
	//���o�́i�o�͈ʒu�j
	dst.m_top    = 20.0f;
	dst.m_left   = 70.0f;
	dst.m_right  = 745.f;
	dst.m_bottom = 330.0f;
	Draw::Draw(13, &src, &dst, f, 0.0f);

	Font::StrDraw(L"1 2 3 4 5 6 7 8 9", 250, 300, 30, o);

	//m_flag[]�̐���
	if (m_flag[1] == true)
	{
		Font::StrDraw(L"�Z", 237, 293, 40, o);
		m_num[1] = 1;
	}
	if (m_flag[2] == true)
	{
		Font::StrDraw(L"�Z", 267, 293, 40, o);
		m_num[2] = 2;

	}
	if (m_flag[3] == true)
	{
		Font::StrDraw(L"�Z", 297, 293, 40, o);
		m_num[3] = 3;

	}
	if (m_flag[4] == true)
	{
		Font::StrDraw(L"�Z", 327, 293, 40, o);
		m_num[4] = 4;

	}
	if (m_flag[5] == true)
	{
		Font::StrDraw(L"�Z", 357, 293, 40, o);
		m_num[5] = 5;

	}
	if (m_flag[6] == true)
	{
		Font::StrDraw(L"�Z", 387, 293, 40, o);
		m_num[6] = 6;

	}
	if (m_flag[7] == true)
	{
		Font::StrDraw(L"�Z", 417, 293, 40, o);
		m_num[7] = 7;

	}
	if (m_flag[8] == true)
	{
		Font::StrDraw(L"�Z", 447, 293, 40, o);
		m_num[8] = 8;

	}
	if (m_flag[9] == true)
	{
		Font::StrDraw(L"�Z", 477, 293, 40, o);
		m_num[9] = 9;

	}

}

void CObjTenkey5::Tenkey()
{
	//�Q���̂ݓ��͉\
	if (cnt != 2)
	{
		//741
		if (m_mou_x > 300 && m_mou_x < 345)
		{
			//�V����
			if (m_mou_y > 373 && m_mou_y < 410)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_flag[7] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}
			}
			//4����
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_flag[4] = true;
						cnt++;
						m_f = false;
					}

				}
				else
				{
					m_f = true;
				}

			}


			//1����
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_flag[1] = true;
						cnt++;
						m_f = false;
					}

				}
				else
				{
					m_f = true;
				}

			}
		}
		//852
		if (m_mou_x > 353 && m_mou_x < 395)
		{
			//8����
			if (m_mou_y > 373 && m_mou_y < 410)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_flag[8] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}


			}
			//5����
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_flag[5] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}


			}
			//2����
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_flag[2] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}

			}

		}
		//963
		if (m_mou_x > 406 && m_mou_x < 445)
		{
			//9����
			if (m_mou_y > 373 && m_mou_y < 410)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_flag[9] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}

			}
			//6����
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_flag[6] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}


			}
			//3����
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_flag[3] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}

			}

		}
	}
	return;
}

bool CObjTenkey5::Anser()
{
	//����
	int m_anser[QUESTION][ANSER] = {
		{ 4 },
		{ 1,5 },
		{ 7,4,8 },
		{ 3,4,7,9 },
		{ 4,3 },
	};
	cnt = 0;
	//�����m�F����
	for (int j = 0; j<2; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (m_num[i + 1] == m_anser[4][j])//�����������Ɛ���������ׂ�
			{
				cnt++;
				if (cnt == 2)
				{
					m_ok = true;
					return m_ok;
				}
				break;
			}
			else
			{
				;
			}
		}
	}
	m_ok = false;
	return m_ok;

}





