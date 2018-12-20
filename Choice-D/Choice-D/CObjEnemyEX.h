#pragma once
//�g�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�`���[�W�G�t�F�N�g
class CObjEnemyEX : public CObj
{
public:
	CObjEnemyEX(float x, float y);
	~CObjEnemyEX() {};
	void Init();	//�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();	//�h���[
	void Set(bool f) ;
private:
	float m_x;	//�I�u�W�F�N�g�̈ʒu�w
	float m_y;	//�I�u�W�F�N�g�̈ʒu�x
	int m_del;
	int	   m_ani;	//�`���[�W�A�j���[�V�����p
	int	   m_ani_time;//�`���[�W�A�j���[�V�����Ԋu�^�C��
	RECT_F m_eff;	//�`���[�W�G�t�F�N�g�`��p

	bool m_ani_flag;//true�ŃA�j���[�V��������Afalse�ŃA�j���[�V������~
};