//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "Objteki5.h"
#include "�V���[�e�B���O\Objteki5.h"
#include "�V���[�e�B���O\UtilityModule.h"
#include "GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjteki5::CObjteki5(float x, float y)
{
	m_hp = 35.f;
	m_maxhp = 35.f;
	m_x = x;
	m_y = y;
	m_tekicnt++;
	m_f = true;
	m_floor=6;
}



//�C�j�V�����C�Y
void CObjteki5::Init()
{
	m_time = 0;
	m_dtime = 70;
	m_r = 45.0f;
	m_r2 = 90.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	death = false;
	//�����蔻��HitBox
	Hits::SetHitBox(this, m_x, m_y, 180-80, 170, ELEMENT_ENEMY, OBJ_TEKI5, 1);

}

//�A�N�V����
void CObjteki5::Action()
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


	m_time++;

	//�ʏ�e����
	if (m_time % 20 == 0)
	{
		if (m_hp <= 0)
		{
			;
		}
		else
		{
			//�e�ۓG�@�I�u�W�F�N�g
			CObjBulletTeki5* obj_b = new CObjBulletTeki5(m_x + 75, m_y + 95);
			Objs::InsertObj(obj_b, OBJ_BULLET_TEKI5, 100);
		}
	}

	if (m_time % 70== 0)
	{
		if (m_hp <= 0)
		{
			;
		}
		else
		{
			//19����������
			CObjAngleBullet* obj_b;
			for (float i = 0.f; i < 360.f; i += 20.f)
			{
				//�p�xi�Ŋp�x�e�۔���
				obj_b = new CObjAngleBullet(m_x + 75.f, m_y + 13.f, i, 5.f);
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

	//360���ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;

	if (m_r2 > 360.0f)
		m_r2 = 0.0f;

	

	//�ړ��x�N�g�����K��
	UnitVec(&m_vy, &m_vx);

	//���x�t����B
	m_vx *= 2.5f;
	m_vy *= 2.5f;

	

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x += m_vx;
	m_y += m_vy;
	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+35 , m_y );

	//�G�@�����S�ɗ̈�O�ɂł���G�@��j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);		//���g�ɍ폜����
		Hits::DeleteHitBox(this);
	}
	
	//HP��75%�ȉ�(26.25)�ɂȂ�����c�ړ�(����)��ǉ�����(�c�ړ��ɕύX����)
	if (m_hp <= 26.25)
	{
		//�p�x���Z
		m_r2 += 2.0f;

		//�ړ�����
		m_vx = 0.0f;
		m_vy = sin(3.14f / 180 * m_r2);
	}
	else
	{
	//�ړ�����
	m_vx = sin(3.14f / 180 * m_r);
	m_vy = 0.0f;
	}

	//���j�G�t�F�N�g�p�̃I�u�W�F�N�g�擾
	CObjEnemyEX* obj = (CObjEnemyEX*)Objs::GetObj(OBJ_EX);

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		obj->Set(true);
		//�G�����񂾂Ƃ������Ƃ��m�F����p
		death = true;
		//���j�G�t�F�N�g�������Ă�����ł����邽�߂̕ϐ����f�N�������g
		m_dtime--;
		//���j�G�t�F�N�g����p�O���[�o���ϐ���true�ɂ���
		g_teki = true;
		//���j���Đ�
		if (m_f == true)
		{
			Audio::Start(3);
			m_f = false;
		}
		else
		{
			;
		}
		//���j�G�t�F�N�g�ϐ����O�ɂȂ������Ƃ̍s��������߂�
		if (m_dtime <= 0)
		{
			//���j�G�t�F�N�g����p�O���[�o���ϐ���false�ɂ���
			g_teki = false;
			//�G���P�̂ł��|���Ɣ�������bool�ϐ���true�ɂ���
			m_endflag = true;
			//�q�b�g�{�b�N�X���폜����
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			//ED����p
			if (m_endflag == true)
			{
				//�����A�G�ƑS������������ŁA�m�[�_���[�W�Ȃ�HAPPYEND��
				if (m_Mehp == 20&&m_tekicnt>=4)
				{
					Scene::SetScene(new CSceneED3());
					g_CombatWaitTime = 300.f;//�����ŕK���R�O�O�ɍĐݒ肵�Ă���
				}
				//��������P��ł��N���A�����true�G���h��
				else if (m_nazoflag == true)
				{
					Scene::SetScene(new CSceneED2());
					g_CombatWaitTime = 300.f;//�����ŕK���R�O�O�ɍĐݒ肵�Ă���

				}
				//���ׂĂ̓G��r�ł���ƁABAD�G���h��
				else if (m_tekicnt >= 4)
				{
					Scene::SetScene(new CSceneED1());
					g_CombatWaitTime = 300.f;//�����ŕK���R�O�O�ɍĐݒ肵�Ă���

				}
				//Scene::SetScene(new CSceneED2());

			}
		}
	}
	else
	{
		obj->Set(false);
	}


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


}

//�h���[
void CObjteki5::Draw()
{
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��jA=alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�GHP�\��
	float h[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�G��HP", 0, 75, 28, h);

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
		src.m_right = 187.0f;
		src.m_bottom = 159.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 200.0f + m_x;
		dst.m_bottom = 200.0f + m_y;

		//10�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (g_CombatWaitTime >= 200)
	{
		Font::StrDraw(L"3", 400, 200, 100, c);
	}
	else if (g_CombatWaitTime <= -100)
	{
		;
		//Font::StrDraw(L" ", 400, 200, 100, c);
	}
	else if (g_CombatWaitTime <= 0)
	{
		Font::StrDraw(L"GO!", 400, 200, 100, c);
	}
	else if (g_CombatWaitTime <= 100)
	{
		Font::StrDraw(L"1", 400, 200, 100, c);
	}
	else if (g_CombatWaitTime <= 200)
	{
		Font::StrDraw(L"2", 400, 200, 100, c);
	}

}