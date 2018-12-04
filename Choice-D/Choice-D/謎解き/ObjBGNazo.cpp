//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjBGNazo.h"
#include "../�Q�[�����C��/SceneMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBGN::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_f = true;
	m_and = 0.0f;
}

//�A�N�V����
void CObjBGN::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

}

//�h���[
void CObjBGN::Draw()
{

	float c[4] = { 1,1,1,m_and };
	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	if (m_f == true)
	{
		m_and += 0.1;
		if (m_and >= 1)
		{
			m_and = 1.0f;
			m_f = false;
		}
	}

	float d[4] = { 1.0f,1.0f,1.0f,m_and};
	RECT_F src;
	RECT_F dst;
	//�h�A1�\��(�؂���ʒu)
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 650.0f;
	src.m_bottom = 946.0f;
	//�h�A1�\��(�\���ʒu)
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 980.0f;
	Draw::Draw(1, &src, &dst, d, 0.0f);


}





