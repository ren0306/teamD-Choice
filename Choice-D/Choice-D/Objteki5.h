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
	void SetX(float x) { m_x = x; }		//�ʒu���X�ύX�p
	void SetY(float y) { m_y = y; }		//�ʒu���Y�ύX�p
	float GetX() { return m_x; }		//�ʒu���X�擾�p
	float GetY() { return m_y; }		//�ʒu���Y�擾�p


private:
	float m_x;		//�G5��x�����̈ʒu
	float m_y;		//�G5��y�����̈ʒu
	float m_vx;		//�G5�ړ��x�N�g��x
	float m_vy;		//�G5�ړ��x�N�g��y
	float m_r;		//sin�J�[�u�p�ϐ�
	float m_r2;		//sin�J�[�u�p�ϐ�2
	int   m_time;	//�e�ۊԊu�p
	int m_dtime;
	float m_hp;		//�{�X�̃q�b�g�|�C���g
	float m_maxhp;
	bool m_f5; 
	bool death;//�G�@�̐����Ǘ��t���O
};