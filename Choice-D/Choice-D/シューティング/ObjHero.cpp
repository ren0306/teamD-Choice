//�g�p����w�b�_�[�t�@�C��
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL\Audio.h"
#include "../GameHead.h"
#include "../GameL/DrawFont.h"
#include "ObjHero.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�ʒu���X�ύX�p
void CObjHero::SetX(float x)
{
	m_x = x;
}

//�ʒu���Y�ύX�p
void CObjHero::SetY(float y)
{
	m_y = y;
}

//�ʒu���X�擾�p
float CObjHero::GetX()
{
	return m_x;
}

//�ʒu���Y�擾�p
float CObjHero::GetY()
{
	return m_y;
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_hp = 20.f;
	m_maxhp = 20.f;
	m_x = 400;
	m_y = 550;
	m_f = true;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 50.f;
	m_cnt = 7.f;
	m_maxcnt = 7.f;
	m_tame = 0.f;
	m_maxtame = 100.f;
	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//��l���@�̒e�۔���
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			m_cnt--;

			//���ˉ���炷
			//Audio::Start(2);
			if (m_cnt <= 0)
			{
				m_f = false;
			}
			else
			{
				// �e�ۃI�u�W�F�N�g�쐬
				CObjBullet*  i = new CObjBullet(m_x, m_y + -30.0f); //�e�ۃI�u�W�F�N�g�쐬
				Objs::InsertObj(i, OBJ_BULLET, 100); //������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

				m_f = false;
			}
		}
	}
	else
	{
		m_f = true;
	}
	//R�������ă����[�h
	if (Input::GetVKey('R') == true)
	{
		m_cnt = 7.f;
	}
	//A�𒷉����Ń`���[�W
	if (Input::GetVKey('A') == true)
	{
		m_tame++;
		if (m_tame >= 100)
		{
			if (m_cnt <= 0)
			{
				m_tame = 0;
			}
			else
			{
				// �e�ۃI�u�W�F�N�g�쐬
				CObjBullet*  i = new CObjBullet(m_x, m_y + -30.0f); //�e�ۃI�u�W�F�N�g�쐬
				Objs::InsertObj(i, OBJ_BULLET, 100); //������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

				m_tame = 0;
			}
		}
	}
	//��l���@�̈ړ��x�N�g��������
	m_vx = 0.0f;
	m_vy = 0.0f;

	//��l���@�̈ړ�
	//�L�[�̓��͕����Ƀx�N�g���̑��x������
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 5.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 5.0f;
	}

	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= 5.0f;
	}

	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 5.0f;
	}

	//�x�N�g���̒��������߂�(�O�����̒藝)
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);//���̃��[�g�����߂�

	//������0���ǂ������ׂ�
	if (r == 0.0f)
	{
		;//0�Ȃ牽�����Ȃ�
	}
	else
	{
		//���K�����s���B
		m_vx = 5.0f / r * m_vx;
		m_vy = 5.0f / r * m_vy;
	}

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x += m_vx;
	m_y += m_vy;

	//��l���@���̈�O�s���Ȃ�����
	if (m_x + 32.0f > 800.0f)
	{
		m_x = 800.0f - 32.0f;
	}
	if (m_y + 32.0f > 600.0f)
	{
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x, m_y);					//���������V�����ʒu(��l���@�̈ʒu�j���ɒu��������

	//ELEMENT_ENEMY�����I�u�W�F�N�g�ƐڐG������HP�����炷
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI1) != nullptr)
		{
			m_hp -= 1;
		}

		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI2) != nullptr)
		{
			m_hp -= 1;
		}
		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI3) != nullptr)
		{
			m_hp -= 2;
		}

		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI4) != nullptr)
		{
			m_hp -= 3;
		}
		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI5) != nullptr)
		{
			m_hp -= 3;
		}

		if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET) != nullptr)
		{
			m_hp -= 1;
		}

		if (hit->CheckObjNameHit(OBJ_HOMING_BULLET) != nullptr)
		{
			m_hp -= 1;
		}

		m_hp -= 1;
	}
	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		m_time--;
		if (m_time <= 0)
		{
			this->SetStatus(false);		//���g�ɍ폜���߂��o���B
			Hits::DeleteHitBox(this);	//��l���@�����L����HitBox�ɍ폜����B


			Scene::SetScene(new CSceneGameOver2());
		}
	}
}

//�h���[
void CObjHero::Draw()
{
	//�A�j���[�V����RECT���
	RECT_F ani_src[4] =
	{
		{ 32,  0,  32,  64},
		{ 32, 32,  64,  64},
		{ 32, 64,  96,  64},
		{ 32, 96, 128,  64},
	};
	
	//�`��J���[���  R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  ob[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	float h[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,0.0f,0
		.0f,1.0f };

	Font::StrDraw(L"������HP", 0, 126, 28, h);
	Font::StrDraw(L"�c�e��", 0, 175, 25, h);
	if (m_cnt <= 0)
	{
		Font::StrDraw(L"�c�e�O�ł��B�����[�h���Ă�������", 0, 200, 25, a);
	}
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1280.0f;
	src.m_bottom = 720.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 150.0f;
	dst.m_left = 0.0f;
	dst.m_right = (m_hp / m_maxhp)*128.0f;
	dst.m_bottom = 175.0f;

	
	//5�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̌��̏��ɕ`��
	Draw::Draw(5, &src, &dst, h, 0.0f);

	//�c�e���\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1280.0f;
	src.m_bottom = 720.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 200.0f;
	dst.m_left = 0.0f;
	dst.m_right = (m_cnt / m_maxcnt)*128.0f;
	dst.m_bottom = 225.0f;

	//5�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̌��̏��ɕ`��
	Draw::Draw(5, &src, &dst, h, 0.0f);

	//�`���[�W�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1280.0f;
	src.m_bottom = 720.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 250.0f;
	dst.m_left = 0.0f;
	dst.m_right = (m_tame / m_maxtame)*128.0f;
	dst.m_bottom = 275.0f;
	//5�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̌��̏��ɕ`��
	Draw::Draw(5, &src, &dst, h, 0.0f);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//1�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(6, &src, &dst, ob, 0.0f);

}

void Bullet(int c,float x,float y)
{

}