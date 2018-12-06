//�g�p����w�b�_�[�t�@�C��
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"
#include <stdlib.h>
#include <time.h>


#include "../GameHead.h"
#include "Objteki1.h"
#include "../�����/ObjTenkey.h"
#include "UtilityModule.h"
#include "../GameL/DrawFont.h"


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
	m_f = false;
	m_time = 0;
	m_r = 85.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	//�����蔻��HitBox
	Hits::SetHitBox(this, m_x, m_y, 200, 170, ELEMENT_ENEMY, OBJ_TEKI1, 1);
}



//�A�N�V����
void CObjteki1::Action()
{
	//HitBox�ʒu���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x +90, m_y +20);

	srand(time(NULL)); // �����_������������


	m_time++;

	//�ʏ�e����
	if (m_time % 50 == 0)
	{
		//�e�ۓG�@�I�u�W�F�N�g
		CObjBulletTeki1* obj_b = new CObjBulletTeki1(m_x + 178, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_BULLET_TEKI1, 100);

	}

	//�ȉ��̊g�U�e�A�U���e���̃v���O������
	//TEST�p�ňꎞ�I�ɒǉ����Ă邾���Ȃ̂�
	//�s�v�ȏꍇ�̓R�����g�A�E�g����OK�B

	//20���Ԋu�Œe�۔���(�g�U�e����)
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

	//�V���b�g�K�����g�U�e����(AngleBullet�����p���Ă���)
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

	//�U���e����
	if (m_time % 200 == 0)
	{
		//�U���e�ۍ쐬
		CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x + 178, m_y + 95);//�U���e�ۍ쐬
		Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 100);//�U���e�ۓo�^
	}

	//�֍s�e����
	if (m_time % 50 == 0)
	{
		//�֍s�e�ۍ쐬
		CObjMeanderBullet* obj_b = new CObjMeanderBullet(m_x + 178, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_MEANDER_BULLET, 100);
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
	m_vx = sin(3.14 / 180 * m_r);
	m_vy = 0.0f;

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
	//HP�O��
	if (m_hp <= 0)
	{
		m_endflag = true;
		m_tekicnt++;
		m_floor++;
		/*this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//�G�@�e�ۂ����L����HItBox�ɍ폜����*/
		Scene::SetScene(new CSceneKuria());

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

	//�G�\��
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 984.0f;
	src.m_bottom = 760.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 400.0f + m_x;
	dst.m_bottom = 260.0f + m_y;

	//10�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(10, &src, &dst, c, 0.0f);





}

