#pragma once
//�g�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjGAMEOVER2 :public CObj
{
public:
	CObjGAMEOVER2() {};
	~CObjGAMEOVER2() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
	private:
		float m_mou_x;
		float m_mou_y;
		bool m_mou_r;
		bool m_mou_l;
}; 
