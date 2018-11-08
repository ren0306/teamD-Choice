//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjTenkey.h"
#include "../�Q�[�����C��/SceneMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTenkey::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_f = true;
	m_flag[1] = true;
	m_flag[2] = true;
	m_flag[3] = true;
	m_flag[4] = true;
	m_flag[5] = true;
	m_flag[6] = true;
	m_flag[7] = true;
	m_flag[8] = true;
	m_flag[9] = true;
	m_flag[10] = true;
}

//�A�N�V����
void CObjTenkey::Action()
{
	if (m_flag[5] == false&&m_flag[4]==false&&m_flag[7]==false)
	{
		Scene::SetScene(new CSceneMain);
	}
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	float o[4] = { 0.5f,0.0f,1.0f,1.0f };
	float f[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"[���ׂč폜]", 500, 450, 30, f);
	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	/*
	789
	456
	123
	*/
	//741
	if (m_mou_x > 300 && m_mou_x < 345)
	{
		//�V����
			if (m_mou_y > 373 && m_mou_y < 410)
			{
				if (m_flag[7] == true)
				{
					Font::StrDraw(L"7", m_ps, 270, 50, o);
					m_flag[7] = false;
				}
				else
				{
					m_flag[7] == true;
				}
			}
			//4����
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
					if (m_mou_l == true)
					{
						if (m_flag[4] == true)
						{
							Font::StrDraw(L"4", m_ps, 270, 50, o);
							m_flag[4] = false;
						}
					}
					else
					{
						m_flag[4] == true;
					}
			}
			//1����
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					if (m_flag[1] == true)
					{
						Font::StrDraw(L"1", m_ps, 270, 50, o);
						m_flag[1] = false;
					}
				}
				else
				{
					m_flag[1] == true;
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
				if (m_flag[8] == true)
				{
					Font::StrDraw(L"8", m_ps, 270, 50, o);
					m_flag[8] = false;
				}
			}
			else
			{
				m_flag[8] == true;
			}

		}
		//5����
		else if (m_mou_y > 416 && m_mou_y < 450)
		{
			if (m_mou_l == true)
			{
				if (m_flag[5] == true)
				{
					Font::StrDraw(L"5", m_ps, 270, 50, o);
					m_flag[5] = false;
				}
			}
			else
			{
				m_flag[5] == true;
			}

		}
		//2����
		else if (m_mou_y > 460 && m_mou_y < 494)
		{
			if (m_mou_l == true)
			{
				if (m_flag[7] == true)
				{
					Font::StrDraw(L"2", m_ps, 270, 50, o);
					m_flag[7] = false;
				}
			}
			else
			{
				m_flag[7] == true;
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
					if (m_flag[9] == true)
					{
						Font::StrDraw(L"9", m_ps, 270, 50, o);
						m_flag[9] = false;
					}
				}
				else
				{
					m_flag[9] == true;
				}

			}
			//6����
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
				if (m_mou_l == true)
				{
					if (m_flag[6] == true)
					{
						Font::StrDraw(L"6", m_ps, 270, 50, o);
						m_flag[6] = false;
					}
				}
				else
				{
					m_flag[6] == true;
				}


			}
			//3����
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					if (m_flag[3] == true)
					{
						Font::StrDraw(L"3", m_ps, 270, 50, o);
						m_flag[3] = false;
					}
				}
				else
				{
					m_flag[3] == true;
				}

			}

		}
		//[���ׂč폜]��������(������)
		if (m_reset_flag == true)
		{
			return;
		}

		if (cnt == 4)
		{
			Scene::SetScene(new CSceneGameOver2);
		}
		/*
		if (m_flag[1] == true)
			{
				Font::StrDraw(L"1", m_ps, 270, 50, o);
			}
		if (m_flag[2] == true)
			{

				Font::StrDraw(L"2", m_ps, 270, 50, o);

			}
		if (m_flag[3] == true)
			{

				Font::StrDraw(L"3", m_ps, 270, 50, o);

			}
		if (m_flag[4] == true)
			{

				Font::StrDraw(L"4", m_ps, 270, 50, o);

			}
		if (m_flag[5] == true)
			{

				Font::StrDraw(L"5", m_ps, 270, 50, o);

			}
		if (m_flag[6] == true)
			{

				Font::StrDraw(L"6", m_ps, 270, 50, o);

			}
		if (m_flag[7] == true)
			{

			}
		if (m_flag[8] == true)
			{

				Font::StrDraw(L"8", m_ps, 270, 50, o);

			}
		if (m_flag[9] == true)
			{
				Font::StrDraw(L"9", m_ps, 270, 50, o);
			}
			*/


}

//�h���[
void CObjTenkey::Draw()
{

	float c[4] = { 1,1,1,1 };
	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);

	Font::StrDraw(L"__________", 250, 290, 50, c);

	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 1024.0f;

	dst.m_top = 50.0f+300;
	dst.m_left = 0.0f+255;
	dst.m_right = 400.0f+100;
	dst.m_bottom =250.0f+300;
	Draw::Draw(2, &src, &dst, d, 0.0f);

}





