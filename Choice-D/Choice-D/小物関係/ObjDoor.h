#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "../GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F��
class CObjDoor :public CObj
{
public:
	CObjDoor() {};
	~CObjDoor() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;

};
