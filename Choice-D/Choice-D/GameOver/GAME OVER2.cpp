//�g�p����w�b�_�[�t�@�C��
#include "../GameL\DrawFont.h"
#include "../GameL\WinInputs.h"

#include "../GameHead.h"
#include "GAME OVER2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGAMEOVER2::Init()
{

}

//�A�N�V����
void CObjGAMEOVER2::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 280 && m_mou_x < 480 && m_mou_y>495 && m_mou_y < 516)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}
}

//�h���[
void CObjGAMEOVER2::Draw()
{
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };
	Font::StrDraw(L"GAME OVER", 270, 50, 50, c);
	float m[4] = { 0.5f,0.5f,0.5f,1.0f };

	Font::StrDraw(L"�G�ɓ|���ꂽ", 300, 400, 30, m);
	float s[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�^�C�g����ʂ�", 280, 500, 30, s);

	

}