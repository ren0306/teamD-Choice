//�g�p����w�b�_�[�t�@�C��
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL\Audio.h"
#include "../GameHead.h"
#include "ObjHero.h"
#include "ObjEnemy2.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjEnemy2::CObjEnemy2()
{
	m_atk;
}

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
	m_hp = 20;
	m_x = 400;
	m_y = 550;
	m_f = true;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	//��l���@�̒e�۔���
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			//���ˉ���炷
			//Audio::Start(2);

			// �e�ۃI�u�W�F�N�g�쐬
			CObjBullet*  obj_b = new CObjBullet(m_x , m_y + -30.0f); //�e�ۃI�u�W�F�N�g�쐬
			Objs::InsertObj(obj_b, OBJ_BULLET, 100); //������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

			m_f = false;
		}
	}
	else
	{
		m_f = true;
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
//		m_hp -= m_atk;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//��l���@�����L����HitBox�ɍ폜����B

		//��l���@���łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
		/*���Q�[���I�[�o�[�̃V�[���͂܂�����ĂȂ����߃R�����g�A�E�g��*/
		//Scene::SetScene(new CSceneGameOver());
	}
}

//�h���[
void CObjHero::Draw()
{
	//�`��J���[���  R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  ob[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

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
	Draw::Draw(1, &src, &dst, ob, 0.0f);

}