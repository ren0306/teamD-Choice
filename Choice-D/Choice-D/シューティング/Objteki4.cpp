//�g�p����w�b�_�[�t�@�C��
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL/DrawFont.h"
#include "../GameHead.h"
#include "Objteki4.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjteki4::CObjteki4(float x, float y)
{
	m_hp = 25.f;
	m_floor++;

	m_maxhp = 25.f;
	m_dtime = 300;
	m_x = x;
	m_y = y;
	m_tekicnt++;

}

//�C�j�V�����C�Y
void CObjteki4::Init()
{
	m_time = 0;
	m_r = 42.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	death = false;
	//�����蔻��HitBox
	Hits::SetHitBox(this, m_x, m_y, 160, 210, ELEMENT_ENEMY, OBJ_TEKI4, 1);

}

//�A�N�V����
void CObjteki4::Action()
{
	if (death == true)
	{
		m_time++;

		if (m_time > 120)
		{
			this->SetStatus(false);
			m_tekicnt++;

			m_endflag = true;
			Scene::SetScene(new CSceneKuria4());
		}
		
		return;
	}

	m_time++;

	
	//�֍s�e����
	if (m_time % 30 == 0)
	{
		//�֍s�e�ۍ쐬
		CObjMeanderBullet* obj_b = new CObjMeanderBullet(m_x + 65, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_MEANDER_BULLET, 100);


		if (m_hp <= 0)
		{
			;
		}
		else
		{
		
		}
	}

	//�U���e����
	if (m_time % 100 == 0)
	{
		if (m_hp <= 0)
		{
			;
		}
		else
		{
			//�U���e�ۍ쐬
			CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x + 65, m_y + 95);//�U���e�ۍ쐬
			Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 100);//�U���e�ۓo�^
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

	//�ړ�����
	m_vx = sin(3.14f / 180 * m_r);
	m_vy = 0.0f;

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
	hit->SetPos(m_x , m_y );

	//�G�@�����S�ɗ̈�O�ɂł���G�@��j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);		//���g�ɍ폜����
		Hits::DeleteHitBox(this);
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		m_dtime--;
		if (m_dtime <= 10)
		{
			m_time = 0;
			
			//���G4�̍��W����ʊO�Ɉړ������鎖�ɂ��A�������悤�Ɍ�����B
			//���̌��death==true��if��(return�L)�ɓ���A
			//�G�@�����S�ɗ̈�O�ɂł���G�@��j������̖��߂�
			//���s����Ȃ����߁A���Ȃ��v���O���������삷��B
			m_x = -1000;
			m_y = -1000;

			Hits::DeleteHitBox(this);
			death = true;
		}
		//20���Ԋu�Œe�۔���(�g�U�e����)
		else if (m_time % 10 == 0)
		{
			//19����������
			CObjAngleBullet* obj_b;
			for (int i = 0; i < 360; i += 20)
			{
				//�p�xi�Ŋp�x�e�۔���
				obj_b = new CObjAngleBullet(m_x + 65, m_y + 95, i, 5.0f);
				Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
			}
		}
	
	}


	//�e�ۂƐڐG������HP�����炷
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}
	//�`���[�W�e�̃_���[�W�R
	if (hit->CheckObjNameHit(OBJ_CHARGE_BULLET) != nullptr)
	{
		m_hp -= 3;

	}


}

	//�h���[
	void CObjteki4::Draw()
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


		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1152.0f;
		src.m_bottom = 1772.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 160.0f + m_x;
		dst.m_bottom = 210.0f + m_y;

		//10�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}