#pragma once
//�g�p����w�b�_�[
#include "../GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;



//�I�u�W�F�N�g�F�G�P
class CObjTimeLimit :public CObj
{
public:
	CObjTimeLimit() {};//�R���X�g���N�^�ʒu�������炤
	~CObjTimeLimit() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	int GETtime() { return m_time; }
private:
	int m_time;

};
