//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjSTG5.h"
#include "�Q�[�����C��/SceneMain.h"
#include "SceneSTG5.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSTG5::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//�A�N�V����
void CObjSTG5::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

//�h���[
void CObjSTG5::Draw()
{
	//float c[4] = { 1,1,1,1 };
	////���}�E�X�ʒu�\��
	//wchar_t str[256];
	//swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	//Font::StrDraw(str, 20, 20, 12, c);


}