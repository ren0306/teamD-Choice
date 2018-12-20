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



//�C�j�V�����C�Y
void CObjEnemyEX::Init()
{
	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 100;
	m_eff.m_bottom = 100;
	m_ani = 0;
	m_ani_time = 0;
	m_ani_flag = false;
}
//�A�j���[�V�����t���O�ύX�p
void CObjEnemyEX::Set(bool f)
{
	m_ani_flag = f;
}

//�A�N�V����
void CObjEnemyEX::Action()
{

	RECT_F ani_src[16] =
	{
		{ 0,   0,  100,  100},
		{ 0,  100, 200,  100 },
		{ 0,  200, 300,  100 },
		{ 0,  300, 400,  100 },
		{ 0,  400, 500,  100 },
		{ 0,500,600,100 },
		{ 0,600,700,100 },
		{ 0,700,800,100 },
		{100,0,100,200},
		{100,100,200,200},
		{100,200,300,200},
		{100,300,400,200},
		{100,400,500,200},
		{100,500,600,200},
		{100,600,700,200},
		{100,700,800,200},
	};

	if (m_ani_flag == false)
	{
		m_eff = ani_src[-1];//�A�j���[�V������RECT�z�񂩂�4�Ԗڂ�RECT���擾
	}
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
	if (m_ani == 16)
	{

	}
}
//�h���[
void CObjEnemyEX::Draw()
{
	//�`��J���[���  R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //�`���\���ʒu

	//�G��|�����Ƃ��̍��W�擾
	if (m_floor==1)
	{
		//��l���@�̈ʒu���擾
		CObjteki1* obj = (CObjteki1*)Objs::GetObj(OBJ_TEKI1);
		m_x = obj->GetX() + 45;
		m_y = obj->GetY() - 30;
	}
	//�G��|����t
	else if ( m_floor == 2)
	{
		CObjteki2*obj2 = (CObjteki2*)Objs::GetObj(OBJ_TEKI2);
		m_x = obj2->GetX() -15;
		m_y = obj2->GetY() - 100;
	}
	else if ( m_floor == 3)
	{
		CObjteki3*obj3 = (CObjteki3*)Objs::GetObj(OBJ_TEKI3);
		m_x = obj3->GetX() - 15;
		m_y = obj3->GetY() - 100;
	}
	else if ( m_floor == 4)
	{
		CObjteki4*obj4 = (CObjteki4*)Objs::GetObj(OBJ_TEKI4);
		m_x = obj4->GetX() - 15;
		m_y = obj4->GetY() - 100;

	}
	else if ( m_floor == 5)
	{
		CObjteki5*obj5 = (CObjteki5*)Objs::GetObj(OBJ_TEKI5);
		m_x = obj5->GetX() - 15;
		m_y = obj5->GetY() - 100;

	}

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 300.0f + m_x;
	dst.m_bottom =300.0f + m_y;

	//8�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(2, &m_eff, &dst, c, 0.0f);
}