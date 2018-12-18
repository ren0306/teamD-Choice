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

//�C�j�V�����C�Y
void CObjSousagamen::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 0.0f;
	m_andf = true;
	m_title = false;
}

//�A�N�V����
void CObjSousagamen::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	if (m_andf == true)
	{
		m_and += 0.1f;
		if (m_and >= 1)
		{
			m_and = 1.0;
			m_andf = false;
		}

	}

	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 450 && m_mou_x < 723 && m_mou_y>525 && m_mou_y < 582)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			m_title = true;
		}
	}

	if (m_title == true)
	{
		m_and -= 0.03f;
		if (m_and <= 0)
		{
			m_and == 0.0f;
			Scene::SetScene(new CSceneTitle());

		}
	}

}

//�h���[
void CObjSousagamen::Draw()
{
	float c[4] = { 1,1,1,m_and};
	


	RECT_F src;
	RECT_F dst;

	float d[4] = { 1.0f,1.0f,1.0f,m_and };
	//�L�[�{�[�h�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 862.0f;
	src.m_bottom = 361.0f;

	dst.m_top = 150.0f;
	dst.m_left = 10.0f;
	dst.m_right = 430.0f;
	dst.m_bottom = 400.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);

	//�}�E�X�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 570.0f;
	src.m_bottom = 365.0f;

	dst.m_top = 170.0f;
	dst.m_left = 440.0f;
	dst.m_right = 770.0f;
	dst.m_bottom = 385.0f;
	Draw::Draw(1, &src, &dst, d, 0.0f);

	Font::StrDraw(L"�������N���b�N�Ń^�C�g����", 450, 535, 25, c);

}