//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "Objteki5.h"
#include "�V���[�e�B���O\Objteki1.h"
#include "�V���[�e�B���O\UtilityModule.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjteki5::CObjteki5(float x, float y)
{

	m_hp = 1.f;
	m_maxhp = 35.f;
	m_x = x;
	m_y = y;
}



//�C�j�V�����C�Y
void CObjteki5::Init()
{
	m_time = 0;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��HitBox
	Hits::SetHitBox(this, m_x, m_y, 180-80, 170, ELEMENT_ENEMY, OBJ_TEKI5, 1);

}

//�A�N�V����
void CObjteki5::Action()
{

	//�G1�̐��ƕ����擾����
	CObjteki1* flag = (CObjteki1*)Objs::GetObj(OBJ_TEKI1);
	m_f=flag->GET();

	m_time++;

	//�ʏ�e����
	if (m_time % 20 == 0)
	{
		//�e�ۓG�@�I�u�W�F�N�g
		CObjBulletTeki5* obj_b = new CObjBulletTeki5(m_x + 75, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_BULLET_TEKI5, 100);
	}

	//m_time�̏�����
	if (m_time > 1000)
	{
		m_time = 0;
	}

	//�p�x���Z
	m_r += 2.0f;

	//360���ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;

	//�ړ�����
	m_vx = sin(3.14 / 180 * m_r);
	m_vy = 0.0f;

	//�ړ��x�N�g�����K��
	UnitVec(&m_vy, &m_vx);

	//���x�t����B
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	

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
	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		/*this->SetStatus(false);
		Hits::DeleteHitBox(this);*/
		if (m_f == true)
		{
			Scene::SetScene(new CSceneKuria5());
		}

	}


	//�e�ۂƐڐG���Ă邵����HP�����炷
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
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