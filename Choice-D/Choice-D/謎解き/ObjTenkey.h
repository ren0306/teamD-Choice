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

private:
	//�}�E�X�֌W--------------------------
	float m_mou_x;//�}�E�X�̈ʒuX
	float m_mou_y;//�}�E�X�̈ʒuY
	bool m_mou_r;//�}�E�X�v�b�V���m�F
	bool m_mou_l;
	//------------------------------------
	//bool(�t���O)�֌W
	bool m_flag[10];//�e���L�[���͊m�F�z��
	bool m_ok;//�𓚊m�F�ϐ�
	bool m_f;
	bool m_andf;
	bool m_delete;
	bool m_wannig;
	//------------------------------------
	int cnt ;//�����`�F�b�N�J�E���g	
	int m_num[10];//�𓚔z��
	int m_anser;//�����m�F�ϐ�
	float m_and;
	int m_time;

};