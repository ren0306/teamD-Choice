#pragma once
//�g�p����w�b�_�[
#include"../GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define QUESTION 5
#define ANSER 4

//�I�u�W�F�N�g�F�e���L�[
class CObjTenkey4 :public CObj
{
public:
	CObjTenkey4() {};
	~CObjTenkey4() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
	bool Anser();
	void Tenkey();

private:
	float m_mou_x;//�}�E�X�̈ʒuX
	float m_mou_y;//�}�E�X�̈ʒuY
	bool m_mou_r;//�}�E�X�̉EON�AOFF
	bool m_mou_l;//�}�E�X�̍�ON�AOFF
	int cnt = 0;
	float m_ps;
	bool m_flag[10];
	bool m_ok;
	int m_num[10];
	int m_anser;
	bool m_f;
};