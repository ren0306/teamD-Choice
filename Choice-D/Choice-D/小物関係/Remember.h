#pragma once
#include "../GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


class Remember :public CObj
{
public:
	Remember() {};//�R���X�g���N�^�ʒu�������炤
	~Remember() {};
	void Init();	//�C�j�V�����C�Y
	void Action() ;	//�A�N�V����
	void Draw() {};	//�h���[
	void SETF(float x) { m_f4 = x; }
	bool GETF() { return m_f4; }

private:
	bool m_f1;
	bool m_f2;
	bool m_f3;
	bool m_f4;
	bool m_f5;

};