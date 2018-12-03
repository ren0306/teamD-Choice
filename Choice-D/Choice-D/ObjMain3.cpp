//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjMain3.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjMain3::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0;
	m_f = false;
	m_key_flag = false;
}

//�A�N�V����
void CObjMain3::Action()
{
	float c[4] = { 1,1,1,m_and };

	/*if (m_f == true)
	{
	m_and += 0.1;
	if (m_and == 1.0)
	{
	m_f = false;
	}

	}*/
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();



}

//�h���[
void CObjMain3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 0.0f,0.0f,0.0f,1.0f };
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
			if (m_mou_x > 165 && m_mou_x < 295 && m_mou_y>135 && m_mou_y < 275)
			{
				Font::StrDraw(L"�G�Ɛ키���Ƃ�I��", 290, 350, 32, c);
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
				dst.m_top = 0.0f + 350;
				dst.m_left = 0.0f;
				dst.m_right = 500.0f;
				dst.m_bottom = 300.0f + 350;

				//3�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
				Draw::Draw(3, &src, &dst, c, 0.0f);
				if (m_mou_x > 100 && m_mou_x < 160 && m_mou_y>150 + 350 && m_mou_y < 175 + 350)
				{
					Font::StrDraw(L"���͂�", 100, 150 + 350, 32, d);
					if (m_mou_l == true)
					{
						Scene::SetScene(new CSceneSTG3());
					}
				}
				else
				{
					Font::StrDraw(L"�͂�", 100, 150 + 350, 32, d);
				}
				if (m_mou_x > 300 && m_mou_x < 380 && m_mou_y>150 + 350 && m_mou_y < 175 + 350)
				{
					Font::StrDraw(L"��������", 300, 150 + 350, 32, d);
					if (m_mou_l == true)
					{
						Scene::SetScene(new CSceneMain3());
					}
				}
				else
				{
					Font::StrDraw(L"������", 300, 150 + 350, 32, d);
				}

			}

			//���ʑJ��
			if (m_mou_x >485 && m_mou_x < 700 && m_mou_y>70 && m_mou_y < 310)
			{

				Font::StrDraw(L"�������I��", 340, 350, 32, c);

				if (m_mou_r == true || m_mou_l == true)
				{
					//����SceneNazo�Ɍq���ł���B���SceneNazo3�ɕύX���ׂ��B
					Scene::SetScene(new CSceneNazo3());
				}

			}
		}
	}
	else
	{
		m_key_flag = true;
	}

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + 80;
	dst.m_left = 0.0f + 100;
	dst.m_right = 200.0f + 200;
	dst.m_bottom = 200.0f + 180;

	//2�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(2, &src, &dst, c, 0.0f);
}
