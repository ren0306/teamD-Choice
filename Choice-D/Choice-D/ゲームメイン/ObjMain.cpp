//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"
#include "../GameL/Audio.h"
#include "../GameHead.h"
#include "ObjMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjMain::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0;
}

//�A�N�V����
void CObjMain::Action()
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
void CObjMain::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	//�퓬��ʑJ��
	if (m_mou_x > 500 && m_mou_x < 765 && m_mou_y>220 && m_mou_y < 382)
	{
		Font::StrDraw(L"�G�Ɛ키���Ƃ�I��", 400, 400, 32, c);

		//�}�E�X�̃{�^���������ꂽ��퓬�ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneSTG());
		}
	}

	//���ʑJ��
	if (m_mou_x >170 && m_mou_x < 320 && m_mou_y>170 && m_mou_y < 455)
	{

		Font::StrDraw(L"�������I��", 400, 400, 32, c);

		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneNazo());
		}

	}
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��jA=alpha(���ߏ��j

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	  //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 984.0f;
	src.m_bottom = 760.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+200;
	dst.m_left = 0.0f+500;
	dst.m_right = 800.0f ;
	dst.m_bottom = 260.0f+200;

	//2�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(2, &src, &dst, c, 0.0f);



}
