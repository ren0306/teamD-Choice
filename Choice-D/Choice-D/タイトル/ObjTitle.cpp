//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"



#include "../GameHead.h"
#include "ObjTitle.h"
#include "../�Q�[�����C��/SceneMain.h"




//�g�p����l�[���X�y�[�X
using namespace GameL;

//GameHead.h�Œ�`�����O���[�o���ϐ��������ŏ�����----------------------
bool m_nazoflag = false;
int m_Nazocnt = 0;
bool m_endflag = false;
int m_tekicnt = 0;
int m_TimeL = 19800;
int m_floor = 1;
//----------------------------------------------------------------------

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	//�}�E�X�̈ʒu
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0f;
}

//�A�N�V����
void CObjTitle::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//�O���[�o���ϐ����^�C�g���ɗ����炷�ׂď�����-------------------
	m_Nazocnt = 0;
	m_nazoflag = false;
	m_endflag = false;
	m_tekicnt = 0;
	m_floor = 1;
	m_TimeL = 19800;
	//---------------------------------------------------------------
}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,m_and };
	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12,c);
	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 400 && m_mou_x < 620 && m_mou_y>390 && m_mou_y < 430)
	{
		Font::StrDraw(L"���Q�[�����n�߂�", 400, 400, 32,c);
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_l == true)
		{
			m_f = true;
		}
	}
	else
	{
		Font::StrDraw(L"�Q�[�����n�߂�", 400, 400, 32, c);
	}

	if (m_mou_x > 400 && m_mou_x < 620 && m_mou_y>430 && m_mou_y < 460)
	{
		Font::StrDraw(L"���������", 400, 450, 32, c);
		//�������
		if (m_mou_l == true)
		{
			m_and -= 0.1;
			Scene::SetScene(new CSceneSousagamen());
		}
	}
	else
	{
		Font::StrDraw(L"�������", 400, 450, 32, c);
	}
	if (m_mou_x > 400 && m_mou_x < 635 && m_mou_y>460 && m_mou_y < 520)
	{
		Font::StrDraw(L"��Choice���I������", 400, 500, 32, c);
		//�Q�[���I��
		if (m_mou_l == true)
		{
			m_and -= 0.1;
			exit(4);
		}
	}
	else
	{
		Font::StrDraw(L"Choice���I������", 400, 500, 32, c);
	}
	if (m_f == true)
	{
		m_and -= 0.01;
		if (m_and <= 0)
		{
			Scene::SetScene(new CSceneOP());
			m_f = false;
		}
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
