#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "../GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���w�i4
class CObjBackGround4 :public CObj
{
public:
	CObjBackGround4() {};
	~CObjBackGround4() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;

};
