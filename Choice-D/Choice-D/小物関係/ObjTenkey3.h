#pragma once
//�g�p����w�b�_�[
#include"../GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define QUESTION 5
#define ANSER 4

//�I�u�W�F�N�g�F�e���L�[
class CObjTenkey3 :public CObj
{
public:
	CObjTenkey3() {};
	~CObjTenkey3() {};
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
	bool m_miss;//�����ԈႢ�Ȃ�true�ϐ�
	bool m_f;
	bool m_andf;
	bool m_delete;
	bool m_wannig;
	//------------------------------------
	float m_misscnt;//�ԈႦ�����̎��Ԃ����炷�\��������ϐ�	
	int cnt;//�����`�F�b�N�J�E���g	
	int m_num[10];//�𓚔z��
	int m_cnt[10];
	int m_anser;//�����m�F�ϐ�
	float m_and;

	//------------------------------------
	//�q���g�֌W
	float Hint_x;//�q���g�{�̕\��/��\���p�ϐ�X
	float Hint_y;//�q���g�{�̕\��/��\���p�ϐ�Y
};