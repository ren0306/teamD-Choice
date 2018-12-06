//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBulletMove.h"
#include "�V���[�e�B���O\UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBulletMove::CObjBulletMove()
{
	
}

//�C�j�V�����C�Y
void CObjBulletTeki1::Init()
{
	m_eff.m_top		= 32;
	m_eff.m_left	= 0;
	m_eff.m_right	= 32;
	m_eff.m_bottom	= 64;
	m_ani			= 0;
	m_ani_time		= 0;
	m_del			= false;

	m_vx = 0.0f;
	m_vy = 1.0f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_BULLET_TEKI1, 1);
}

//�A�N�V����
void CObjBulletTeki1::Action()
{
	//Resources�̕`�敨��RECT
	m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 2);

	//�e�ۏ��ŏ����@-----
	if (m_del == true)
	{
		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j��
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������
	}

	//�e�ێ��s�����@-----
	//�ړ�
	m_x += m_vx * 5.0f;
	m_y += m_vy * 5.0f;

	//�G�@�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y); 		 //HitBox�̈ʒu��G�@�e�ۂ̈ʒu�ɍX�V

									 //�G�@�e�ۂ����S�ɗ̈�O�ɏo����G�@�e�ۂ�j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//�G�@�e�ۂ����L����HitBox���폜����B

		return;
	}

	//��l���@�I�u�W�F�N�g�ƐڐG������G�@�e�ۍ폜
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		m_del = true;				//���Ŏ��s
		hit->SetInvincibility(true);//�����蔻�薳��
	}

	//�x�N�g���̒��������߂�
	float r = 0.0f;
	r = m_vx*m_vx + m_vy*m_vy;
	r = sqrt(r);

	//������0�����ׂ�
	if (r == 0.0f)
	{
		;//0�Ȃ牽�����Ȃ�
	}
	else
	{
		//���K�����s��
		m_vx = 1.0f / r*m_vx;
		m_vx = 1.0f / r*m_vy;
	}
}

//�h���[
void CObjBulletTeki1::Draw()
{
	//�`��J���[���  R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //�`���\���ʒu

				//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//30�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(30, &m_eff, &dst, c, 0.0f);
}

