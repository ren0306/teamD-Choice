#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G5
class CObjteki5 :public CObj
{
public:
	CObjteki5(float x, float y);//�R���X�g���N�^�ʒu�������炤
	~CObjteki5() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	void SET(float x) { m_f = x; }
	bool GET() { return m_f; }

private:
	float m_x;	//�G5��x�����̈ʒu
	float m_y;	//�G5��y�����̈ʒu
	float m_vx;	//�G5�ړ��x�N�g��x
	float m_vy;	//�G5�ړ��x�N�g��y
	float m_r = 0.0f;
	int   m_time;//�e�ۊԊu�p
	bool m_f5;
	float m_hp;	//�{�X�̃q�b�g�|�C���g
	float m_maxhp;
	bool m_f;
};