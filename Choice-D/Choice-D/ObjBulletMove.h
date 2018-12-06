#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�V���[�e�B���O�w�i
class CObjBulletMove : public CObj
{
	public:
		CObjBulletMove();
		~CObjBulletMove() {};
		void Init();	//�C�j�V�����C�Y
		void Action();  //�A�N�V����
		void Draw();	//�h���[
	private:
		float m_x;		//�e�ۂ�X�����̈ʒu�p�ϐ�
		float m_y;		//�e�ۂ�Y�����̈ʒu�p�ϐ�
		float m_vx;		//�e�ۂ�X�����̑��x�p�ϐ�
		float m_vy;		//�e�ۂ�Y�����̑��x�p�ϐ�
		int	   m_ani;	//���e�A�j���[�V�����p
		int	   m_ani_time;//���e�A�j���[�V�����Ԋu�^�C��
		bool   m_del;	//�폜�`�F�b�N
		RECT_F m_eff;	//���e�G�t�F�N�g�`��p	
};
