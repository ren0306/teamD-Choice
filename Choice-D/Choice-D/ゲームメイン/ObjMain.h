#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "../GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class CObjMain :public CObj
{
public:
	CObjMain() {};
	~CObjMain() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;
	float m_and;
	bool m_f;
	bool m_key_flag;//�L�[�t���O
	bool m_andf;
	bool m_Trans;
};