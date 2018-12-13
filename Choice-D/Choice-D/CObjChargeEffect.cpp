//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "CObjChargeEffect.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�A�j���[�V�����R�}�ύX�p
void CObjChargeEffect::Set(int a)
{
	m_ani = a;
}

//�C�j�V�����C�Y
void CObjChargeEffect::Init()
{
	m_eff.m_top = 0;
	m_eff.m_left = 96;
	m_eff.m_right = 128;
	m_eff.m_bottom = 32;
	m_ani = 0;
	m_ani_time = 0;//ObjHero���ŕύX�������B
}

//�A�N�V����
void CObjChargeEffect::Action()
{
	RECT_F ani_src[5] =
	{
		{ 0,  96, 128,  32 },
		{ 64,  32,  64,  96 },
		{ 96, 224, 256,  128 },
		{ 160, 160, 192, 192 },
		{ 224,  96, 128, 256 },
	};

	//�A�j���[�V�����̃R�}�Ԋu����
	if (m_ani_time > 4)
	{
		m_ani++;	//�A�j���[�V�����̃R�}���P�i�߂�
		m_ani_time = 0;

		m_eff = ani_src[m_ani];//�A�j���[�V������RECT�z�񂩂�m_ani�Ԗڂ�RECT���擾
	}
	else
	{
		m_ani_time++;
	}

	//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j��
	if (m_ani == 5)
	{
		this->SetStatus(false);
	}


	return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������
}

//�h���[
void CObjChargeEffect::Draw()
{
	//�`��J���[���  R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dst.m_top = -20.0f;
	dst.m_left = -20.0f;
	dst.m_right = 52.0f;
	dst.m_bottom = 52.0f;

	//8�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(8, &m_eff, &dst, c, 0.0f);
}