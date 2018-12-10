/*

//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjHeroExplosion.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjHeroExplosion::CObjHeroExplosion(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjHeroExplosion::Init()
{
	m_eff.m_top = 0;
	m_eff.m_left = 96;
	m_eff.m_right = 128;
	m_eff.m_bottom = 32;
	m_ani = 0;
	m_ani_time = 0;
}

//�A�N�V����
void CObjHeroExplosion::Action()
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
void CObjHeroExplosion::Draw()
{
	//��l���@�̈ʒu�����
	//CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float x = obj->GetX();
	//float y = obj->GetY();
	
	//�`��J���[���  R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dst.m_top = -20.0f + m_y;
	dst.m_left = -20.0f + m_x;
	dst.m_right = 52.0f + m_x;
	dst.m_bottom = 52.0f + m_y;

	//8�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(8, &m_eff, &dst, c, 0.0f);
}

*/