#pragma once
//�g�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G3
class CObjteki4 :public CObj
{
public:
	CObjteki4(float x, float y);//�R���X�g���N�^�ʒu�������炤
	~CObjteki4() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;	//�G3��x�����̈ʒu
	float m_y;	//�G3��y�����̈ʒu
	float m_vx;	//�G3�ړ��x�N�g��x
	float m_vy;	//�G3�ړ��x�N�g��y
	float m_r = 0.0f;

};