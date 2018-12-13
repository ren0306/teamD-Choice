//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjMain2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjMain2::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 0.0;
	m_f = false;
	m_key_flag = false;
	m_timecnt = 50;
}

//�A�N�V����
void CObjMain2::Action()
{
	float c[4] = { 1,1,1,m_and };

	if (m_f == true)
	{
		m_and += 0.1;
		if (m_and == 1.0)
		{
			m_f = false;
		}

	}

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();



}

//�h���[
void CObjMain2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 0.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,m_and };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	wchar_t kaisou[4];
	swprintf_s(kaisou, L"%d�K�w", m_floor);
	Font::StrDraw(kaisou, 710, 0, 35, c);

	//�O�V�[�����獶�܂��͉E�N���b�N�����������Ă���A
	//�������͂��̃V�[���ɓ����Ĉ�x�ł��N���b�N�������ĂȂ���ԂɈڍs����Ǝ��s�B
	if (m_mou_r == true || m_mou_l == true || m_key_flag == true)
	{
		//���̃V�[���ɓ����Ĉ�x�ł��N���b�N�������ĂȂ���ԂɈڍs����Ǝ��s�B
		if (m_key_flag == true)
		{
			//�퓬��ʑJ��
			if (m_mou_x > 110 && m_mou_x < 360 && m_mou_y>238 && m_mou_y < 530)
			{
				Font::StrDraw(L"�G�Ɛ키���Ƃ�I��", 455, 350, 32, c);
				//�}�E�X�̃{�^���������ꂽ��퓬�ɑJ��
				if (m_mou_r == true || m_mou_l == true)
				{
					m_f = true;

				}

			}
			if (m_f == true)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 768.0f;
				src.m_bottom = 614.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = 0.0f;
				dst.m_left = 0.0f;
				dst.m_right = 500.0f;
				dst.m_bottom = 300.0f;

				//3�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
				Draw::Draw(3, &src, &dst, c, 0.0f);
				if (m_mou_x > 100 && m_mou_x < 160 && m_mou_y>150 && m_mou_y < 175)
				{
					Font::StrDraw(L"���͂�", 100, 150, 32, d);
					if (m_mou_l == true)
					{
						Scene::SetScene(new CSceneSTG2());
					}
				}
				else
				{
					Font::StrDraw(L"�͂�", 100, 150, 32, d);
				}
				if (m_mou_x > 300 && m_mou_x < 380 && m_mou_y>150 && m_mou_y < 175)
				{
					Font::StrDraw(L"��������", 300, 150, 32, d);
					if (m_mou_l == true)
					{
						Scene::SetScene(new CSceneMain2());
					}
				}
				else
				{
					Font::StrDraw(L"������", 300, 150, 32, d);
				}

			}

			//���ʑJ��
			if (m_mou_x >455 && m_mou_x < 630 && m_mou_y>397 && m_mou_y < 584)
			{

				Font::StrDraw(L"�������I��", 455, 350, 32, c);

				if (m_mou_r == true || m_mou_l == true)
				{
					//����SceneNazo�Ɍq���ł���B���SceneNazo2�ɕύX���ׂ��B
					Scene::SetScene(new CSceneNazo2());
				}

			}
		}
	}
	else
	{
		m_key_flag = true;
	}
	if (m_clear == true)
	{
		Font::StrDraw(L"+30�b", 40, 50, 30, g);
		m_TimeL += 18;//�R�O�b����
		m_clearcnt--;
		if (m_clearcnt <= 0)
		{
			m_clear = false;
			m_clearcnt = 500.f;
		}
	}

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1071.0f;
	src.m_bottom = 865.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + 200;
	dst.m_left = 0.0f + 50;
	dst.m_right = 200.0f + 250;
	dst.m_bottom = 160.0f + 400;

	//2�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(2, &src, &dst, c, 0.0f);


}
