//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "STGBackground.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void STGBackground::Init()
{
	m_andf = true;
	m_and = 0.f;
}

//�A�N�V����
void STGBackground::Action()
{
	if (m_andf == true)
	{
		m_and += 0.1f;
		if (m_and >= 1)
		{
			m_and = 1.0;
			m_andf = false;
		}

	}

}

//�h���[
void STGBackground::Draw()
{
	// �`��J���[���  R = RED  G = Green  B = Blue A = alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,m_and };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 769.0f;
	src.m_bottom = 621.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}