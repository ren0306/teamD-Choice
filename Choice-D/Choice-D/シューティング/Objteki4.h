#pragma once
//�g�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G4
class CObjteki4 :public CObj
{
public:
	CObjteki4(float x, float y);//�R���X�g���N�^�ʒu�������炤
	~CObjteki4() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	void SetX(float x) { m_x = x; }//�ʒu���X�ύX�p
	void SetY(float y) { m_y = y; }//�ʒu���Y�ύX�p
	float GetX() { return m_x; }	   //�ʒu���X�擾�p
	float GetY() { return m_y; }	   //�ʒu���Y�擾�p


private:
	float m_x;	//�G3��x�����̈ʒu
	float m_y;	//�G3��y�����̈ʒu
	float m_vx;	//�G3�ړ��x�N�g��x
	float m_vy;	//�G3�ړ��x�N�g��y
	float m_r;	//sin�J�[�u�p�ϐ�
	int   m_time;//�e�ۊԊu�p���I�u�W�F�N�g�폜�܂ł̎��ԊǗ��p

	bool m_f;
	float m_hp;	//�{�X�̃q�b�g�|�C���g
	float m_maxhp;
	int m_dtime;
	bool death;	//�G4�̐����Ǘ�
};