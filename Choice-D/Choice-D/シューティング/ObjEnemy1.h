#pragma once
//�g�p����w�b�_�[
#include"../GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�Q
class CObjEnemy1 : public CObj
{
	public:
		CObjEnemy1(float x, float y);//�R���X�g���N�^�ʒu�������炤
		~CObjEnemy1() {};
		void Init();	//�C�j�V�����C�Y
		void Action();  //�A�N�V����
		void Draw();	//�h���[
	private:
		float m_x;	//�{�X�@�̂������̈ʒu
		float m_y;	//�{�X�@�̂������̈ʒu
		float m_vx; //�{�X�@�ړ��x�N�g��X
		float m_vy; //�{�X�@�ړ��x�N�g��Y
		float m_r;	//�T�C���J�[�u�p�̊p�x
		int   m_time;//�e�ۊԊu�p
		int   m_hp; //�{�X�̃q�b�g�|�C���g
		int   m_atk; //�{�X�̍U����
};