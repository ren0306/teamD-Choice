//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "CObjEnemyEX.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjEnemyEX::CObjEnemyEX(float x, float y)
{
	m_x = x;
	m_y = y;
}

////�A�j���[�V�����t���O�ύX�p
//void CObjEnemyEX::Set(bool f)
//{
//	m_ani_flag = f;
//}

//�C�j�V�����C�Y
void CObjEnemyEX::Init()
{
	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 32;
	m_ani = 0;
	m_ani_time = 0;
	m_ani_flag = false;
}

//�A�N�V����
void CObjEnemyEX::Action()
{
	RECT_F ani_src[8] =
	{
		{ 0,   0,  32,  32 },
		{ 0,  32,  64,  32 },
		{ 0,  64,  96,  32 },
		{ 0,  96, 128,  32 },
		{ 0,  128, 160,  32 },
		{0,160,192,32},
		{0,192,224,32},
		{0,224,256,32},
	};

	//�A�j���[�V������~����
	if (m_ani_flag == false)
	{
		m_eff = ani_src[8];//�A�j���[�V������RECT�z�񂩂�4�Ԗڂ�RECT���擾
	}

	//�A�j���[�V�������s����
	else
	{
		//�A�j���[�V�����̃R�}�Ԋu����
		if (m_ani_time > 2)
		{
			m_ani++;	//�A�j���[�V�����̃R�}���P�i�߂�
			m_ani_time = 0;

			m_eff = ani_src[m_ani];//�A�j���[�V������RECT�z�񂩂�m_ani�Ԗڂ�RECT���擾
		}
		else
		{
			m_ani_time++;
		}

	}
}

//�h���[
void CObjEnemyEX::Draw()
{
	//�`��J���[���  R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //�`���\���ʒu

				//��l���@�̈ʒu���擾
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_x = obj->GetX();
	m_y = obj->GetY();

	//�\���ʒu�̐ݒ�
	dst.m_top = -20.0f + m_y;
	dst.m_left = -24.0f + m_x;
	dst.m_right = 48.0f + m_x;
	dst.m_bottom = 52.0f + m_y;

	//8�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(8, &m_eff, &dst, c, 0.0f);
}