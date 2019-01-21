//�g�p����w�b�_�[�t�@�C��
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL/DrawFont.h"
#include "../GameHead.h"
#include <time.h>
#include "Objteki1.h"
#include "UtilityModule.h"
#include "../GameL/Audio.h"
#include <stdlib.h>
#include "../�����/ObjTenkey.h"





//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjteki1::CObjteki1(float x, float y)
{
	m_x = x;
	m_y = y;
}


//�C�j�V�����C�Y
void CObjteki1::Init()
{
	m_hp = 30.f;
	m_maxhp = 30.f;
	m_f = true;
	m_time = 0;
	m_r = 85.0f;
	m_r2 = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_enemytime = 70;
	death = false;
	//�����蔻��HitBox
	Hits::SetHitBox(this, m_x, m_y, 200, 170, ELEMENT_ENEMY, OBJ_TEKI1, 1);
}



//�A�N�V����
void CObjteki1::Action()
{

	//�퓬�ҋ@���Ԃ��Ǘ�����O���[�o���ϐ����O�ɂȂ�����퓬�J�n
	if (g_CombatWaitTime >= 0)
	{
		g_CombatWaitTime--;
		return;
	}
	else if (g_CombatWaitTime <= 0)
	{
		g_CombatWaitTime--;

		;
	}

	RECT_F dst;//�`���\���ʒu

	//Audio::Start(0);
	//��l���iHero�j�̐������擾����
	CObjHero* Hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	Herodeath = Hero->GetDeath();

	
	//��l���iHero�j����������ł����特�y���~�߂�
	if (Herodeath == true)
	{
		Audio::Stop(0);
	}
	//HitBox�ʒu���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x +90, m_y +20);

	srand(time(NULL)); // �����_������������


	m_time++;
	/*--�G�e���쏊---------------------------------------------------------------------------------------------------
	//�ق��̓G�Ɏg���ꍇ�͂��̕������R�s�[���Ă�
	//���؂����폜�͂��Ȃ��łˁB���Ă��܂����ꍇCtrl+Z���������炽���Ă��߂��
	//----------------------------------------------------------------------------
	//�ʏ�e���˃v���O����
	if (m_time % 50 == 0)
	{
		//�e�ۓG�@�I�u�W�F�N�g
		CObjBulletTeki1* obj_b = new CObjBulletTeki1(m_x + 178, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_BULLET_TEKI1, 100);
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//20���Ԋu�Œe�۔���(�g�U�e����)�v���O����
	if (m_time % 100 == 0)
	{
		//19����������
		CObjAngleBullet* obj_b;
		for (int i = 0; i < 360; i += 20)
		{
			//�p�xi�Ŋp�x�e�۔���
			obj_b = new CObjAngleBullet(m_x + 178, m_y + 95, i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
		}
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//�V���b�g�K�����g�U�e����(AngleBullet�����p���Ă���)�v���O����
	//260���` 280���͈̔�(������)��2���Ԋu�Œe�۔���
	if (m_time % 100 == 0)
	{
		//��������11����������
		CObjAngleBullet* obj_b;
		for (int i = 260; i < 280; i += 2)
		{
			//�p�xi�Ŋp�x�e�۔���
			obj_b = new CObjAngleBullet(m_x + 178, m_y + 95, i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
		}
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//�U���e���˃v���O����
	if (m_time % 200 == 0)
	{
		//�U���e�ۍ쐬
		CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x + 178, m_y + 95);//�U���e�ۍ쐬
		Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 100);//�U���e�ۓo�^
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//�֍s�e���˃v���O����
	if (m_time % 50 == 0)
	{
		//�֍s�e�ۍ쐬
		CObjMeanderBullet* obj_b = new CObjMeanderBullet(m_x + 178, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_MEANDER_BULLET, 100);
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------------------*/
	//�U���p�^�[��
	if (m_time % 50 == 0)
	{
		if (m_hp <= 0)
		{
			;
		}
		else
		{
			//��������11����������
			CObjAngleBullet* obj_b;
			for (float i = 260.0f; i < 280.0f; i += 2.0f)
			{
				//�p�xi�Ŋp�x�e�۔���
				obj_b = new CObjAngleBullet(m_x + 178.0f, m_y + 95.0f, i, 5.0f);
				Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
			}
		}
	}

	//m_time�̏�����
	if (m_time > 1000)
	{
		m_time = 0;
	}

	//�p�x���Z
	m_r += 1.0f;
	m_r2 += 0.5f;

	//360���ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;

	if (m_r2 > 360.0f)
		m_r2 = 0.0f;

	//�ړ�����
	m_vx = sin(3.14f / 180 * m_r);
	m_vy = sin(3.14f / 30 * m_r2);

	//�ړ��x�N�g�����K��
	UnitVec(&m_vy, &m_vx);

	//���x�t����B
	m_vx *= 2.5f;
	m_vy *= 2.5f;

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x += m_vx;
	m_y += m_vy;


	//�e�ۂƐڐG���Ă邵����HP�����炷
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;

	}
	//�`���[�W�e�̃_���[�W�R
	if (hit->CheckObjNameHit(OBJ_CHARGE_BULLET) != nullptr)
	{
		m_hp -= 8;

	}

	CObjEnemyEX* obj = (CObjEnemyEX*)Objs::GetObj(OBJ_EX);

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		obj->Set(true);
		//�G�����񂾂Ƃ������Ƃ��m�F����p
		death = true;
		//���j�G�t�F�N�g�������Ă�����ł����邽�߂̕ϐ����f�N�������g
		m_enemytime--;
		if (m_f == true)
		{
			Audio::Start(3);
			m_f = false;
		}
		else
		{
			;
		}
		//���j�G�t�F�N�g�ϐ����O�ɂȂ������ƂQ�K�w��
		if (m_enemytime <= 0)
		{
			//�G���P�̂ł��|���Ɣ�������bool�ϐ���true�ɂ���
			m_endflag = true;
			//�K�w�����Ǘ����Ă���O���[�o���ϐ����C���N�������g
			m_floor++;
			//�Q�K�w��
			Scene::SetScene(new CSceneKuria());
			g_CombatWaitTime = 300.f;//�����ŕK���R�O�O�ɍĐݒ肵�Ă���

		}
	}
	else
	{
		obj->Set(false);

	}

}

//�h���[
void CObjteki1::Draw()
{


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	//�GHP�\��
	float h[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�G��HP", 0, 75, 28, h);
	//�G�\��
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1280.0f;
	src.m_bottom = 720.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 100.0f;
	dst.m_left = 0.0f;
	dst.m_right = (m_hp / m_maxhp)*128.0f;
	dst.m_bottom = 125.0f;

	//5�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̌��̏��ɕ`��
	Draw::Draw(5, &src, &dst, h, 0.0f);

	if (death == false)
	{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 986.0f;
	src.m_bottom = 785.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 50.0f + m_x;
	dst.m_right = 350.0f + m_x;
	dst.m_bottom = 260.0f + m_y;

		//10�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//��l���iHero�j�����ʂ��A�G�����񂾂�X�g�b�v������
	if (Herodeath == true || death == true)
	{
		;
	}
	else
	{
		//�퓬���n�܂�R�b�O����J�E���g�_�E������ʂɕ\��������v���O����
		if (g_CombatWaitTime <= -100)
		{
			;
		}
		else if (g_CombatWaitTime <= 0)
		{
			Font::StrDraw(L"GO!", 380, 200, 100, c);
		}
		else if (g_CombatWaitTime <= 100)
		{
			Font::StrDraw(L"1", 400, 200, 100, c);
		}
		else if (g_CombatWaitTime <= 200)
		{
			Font::StrDraw(L"2", 400, 200, 100, c);
		}
		else if (g_CombatWaitTime >= 200)
		{
			Font::StrDraw(L"3", 400, 200, 100, c);
		}

	}

}

