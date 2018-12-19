//�g�p����w�b�_�[�t�@�C��
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL/DrawFont.h"

#include "../GameHead.h"
#include "Objteki3.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
//�R���X�g���N�^
CObjteki3::CObjteki3(float x, float y)
{
	m_hp = 40.f;
	m_maxhp = 40.f;
	m_x = x;
	m_y = y;
	m_hit = 0;


}

//�C�j�V�����C�Y
void CObjteki3::Init()
{
	m_time = 0;
	m_r = 45.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_hit = 0;
	//�����蔻��HitBox
	Hits::SetHitBox(this, m_x, m_y, 150 - m_hit, 13 - m_hit, ELEMENT_ENEMY, OBJ_TEKI3, 1);

}

//�A�N�V����
void CObjteki3::Action()
{
	m_time++;

	//�ʏ�e����
	if (m_time % 35 == 0)
	{
		//19����������
		CObjAngleBullet* obj_b;
		for (int i = 0; i < 360; i += 20)
		{
			//�p�xi�Ŋp�x�e�۔���
			obj_b = new CObjAngleBullet(m_x, m_y , i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
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
	m_vy = sin(3.14f / 10 * m_r);
	//�ړ��x�N�g�����K��z
	UnitVec(&m_vy, &m_vx);

	//���x�t����B
	m_vx *= 3.5f;
	m_vy *= 2.5f;

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x += m_vx;
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + 10, m_y + 20);

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
		m_tekicnt++;
		m_floor++;
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		m_endflag = true;
		Scene::SetScene(new CSceneKuria3());
	}


	//�e�ۂƐڐG���Ă邵����HP�����炷
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
		//�_���[�W���󂯂�Ɖ摜�Ɠ����蔻�肪�������Ȃ�
		m_hit += 4;
		Hits::DeleteHitBox(this);

		//�����蔻��HitBox
		Hits::SetHitBox(this, m_x, m_y, 150 - m_hit, 13, ELEMENT_ENEMY, OBJ_TEKI3, 1);

	}
	//�`���[�W�e�̃_���[�W�R
	if (hit->CheckObjNameHit(OBJ_CHARGE_BULLET) != nullptr)
	{
		m_hp -= 3;
		//�_���[�W���󂯂�Ɖ摜�Ɠ����蔻�肪�������Ȃ�
		m_hit += 12;
		Hits::DeleteHitBox(this);

		//�����蔻��HitBox
		Hits::SetHitBox(this, m_x, m_y, 150 - m_hit, 13, ELEMENT_ENEMY, OBJ_TEKI3, 1);

	}

	

}

//�h���[
void CObjteki3::Draw()
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

	//�G3�\��
   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 200.0f + m_x - m_hit;
	dst.m_bottom = 200.0f + m_y - m_hit;

	//10�Ԃ߂ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(10, &src, &dst, c, 0.0f);
}