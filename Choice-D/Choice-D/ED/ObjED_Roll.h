#pragma once
//�g�p����w�b�_�[
#include"../GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G���f�B���O1
class CObjED_Roll :public CObj
{
public:
	CObjED_Roll() {};
	~CObjED_Roll() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_y;
};