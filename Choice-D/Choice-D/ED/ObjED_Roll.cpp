//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"
#include "../GameL/DrawTexture.h"
#include "../GameHead.h"
#include "ObjED_Roll.h"
#include "../�Q�[�����C��/SceneMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjED_Roll::Init()
{
	m_y = 0;
	m_and = 1.0f;
}

//�A�N�V����
void CObjED_Roll::Action()
{
	float c[4] = { 1,1,1,1 };
	float f[4] = { 1.0f,1.0f,1.0f,m_and };
	m_y--;
	//�G���^�[�L�[�ő�����@�\
	if (Input::GetVKey(VK_RETURN) == true)
	{
		m_y -= 10;
	}
	//3�b��ɂ��񂾂�����Ă���
	if (m_y <= -300)
	{
		Font::StrDraw(L"Enter�L�[�������ő�����ł��܂�", 0, 0, 32, f);

		m_and -= 0.02f;
	}
	else
	{
		Font::StrDraw(L"Enter�L�[�������ő�����ł��܂�", 0, 0, 32, f);
	}

	Font::StrDraw(L"������", 200, 600 + m_y, 32, c);

	Font::StrDraw(L"������", 200, 650 + m_y, 50, c);
	Font::StrDraw(L"https://maoudamashii.jokersounds.com/", 200, 700 + m_y, 32, c);

	Font::StrDraw(L"���ʉ����{", 200, 750 + m_y, 50, c);
	Font::StrDraw(L"https://soundeffect-lab.info/", 200, 800 + m_y, 32, c);

	Font::StrDraw(L"���", 200, 850 + m_y, 50, c);
	Font::StrDraw(L"��m��@�T�M", 200, 900 + m_y, 32, c);
	Font::StrDraw(L"����@��", 200, 930 + m_y, 32, c);
	Font::StrDraw(L"�����@�@", 200, 960 + m_y, 32, c);
	Font::StrDraw(L"�c���@�ǖ�", 200, 990 + m_y, 32, c);
	Font::StrDraw(L"���c�@�L�i", 200, 1020 + m_y, 32, c);

	Font::StrDraw(L"�G�L�����N�^�[�����", 200, 1070 + m_y, 50, c);
	Font::StrDraw(L"�G�P", 200, 1120 + m_y, 40, c);
	Font::StrDraw(L"����@��", 200, 1160 + m_y, 32, c);

	Font::StrDraw(L"�G�Q", 200, 1400 + m_y, 40, c);
	Font::StrDraw(L"�c���@�ǖ�", 200, 1440 + m_y, 32, c);

	Font::StrDraw(L"�G�R", 200, 1700 + m_y, 40, c);
	Font::StrDraw(L"�����@�@", 200, 1740 + m_y, 32, c);

	Font::StrDraw(L"�G�S", 200, 2000 + m_y, 40, c);
	Font::StrDraw(L"��m��@�T�M", 200, 2040 + m_y, 32, c);

	Font::StrDraw(L"�G�T", 200, 2300 + m_y, 40, c);
	Font::StrDraw(L"���c�@�L�i", 200, 2340 + m_y, 32, c);

	Font::StrDraw(L"����Ɏg�����\�t�g", 180, 2700 + m_y, 50, c);
	Font::StrDraw(L"Microsoft Visual Studio 2015", 180, 2750 + m_y, 32, c);

	Font::StrDraw(L"�ē�", 200, 3000 + m_y, 50, c);
	Font::StrDraw(L"�����@�@", 200, 3100 + m_y, 40, c);

	if (m_y <= -3200)
	{
		Scene::SetScene(new CSceneTitle());
	}
}

//�h���[
void CObjED_Roll::Draw()
{
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	//�G�\��
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	//----------------------------------------------------------
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 986.0f;
	src.m_bottom = 785.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 1210.0f + m_y;
	dst.m_left = 300.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 1470.0f + m_y;

	//1�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
	//----------------------------------------------------------
	//----------------------------------------------------------
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1071.0f;
	src.m_bottom = 865.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 1490.0f + m_y;
	dst.m_left = 300.0f ;
	dst.m_right = 500.0f ;
	dst.m_bottom = 1650.0f + m_y;

	//2�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(2, &src, &dst, c, 0.0f);
	//----------------------------------------------------------
	//----------------------------------------------------------
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 1770.0f + m_y;
	dst.m_left = 300.0f ;
	dst.m_right = 500.0f ;
	dst.m_bottom = 1930.0f + m_y;

	//3�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(3, &src, &dst, c, 0.0f);
	//-----------------------------------------------------------
	//-----------------------------------------------------------
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1152.0f;
	src.m_bottom = 1772.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 2150.0f + m_y;
	dst.m_left = 300.0f;
	dst.m_right = 460.0f;
	dst.m_bottom = 2310.0f + m_y;

	//4�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(4, &src, &dst, c, 0.0f);
	//-----------------------------------------------------------
	//-----------------------------------------------------------
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 187.0f;
	src.m_bottom = 159.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 2430.0f + m_y;
	dst.m_left = 300.0f ;
	dst.m_right = 500.0f;
	dst.m_bottom = 2590.0f + m_y;

	//10�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(5, &src, &dst, c, 0.0f);
	//-----------------------------------------------------------
}
