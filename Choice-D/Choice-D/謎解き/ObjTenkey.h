#pragma once
//�g�p����w�b�_�[
#include"../GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define QUESTION 5
#define ANSER 4

//�I�u�W�F�N�g�F�e���L�[
class CObjTenkey :public CObj
{
public:
	CObjTenkey() {};
	~CObjTenkey() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
	bool Anser();
	void Tenkey();
	int m_f = 0;
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;	
	int cnt ;
	float m_ps ;
	bool m_flag[10];
	bool m_ok;
	int m_num[10];
	int m_anser;
	bool m_fnot;
	bool m_miss;
	float m_misscnt;
};