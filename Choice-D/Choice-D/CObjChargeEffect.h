#pragma once
//�g�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�`���[�W�G�t�F�N�g
class CObjChargeEffect : public CObj
{
public:
	CObjChargeEffect() {};
	~CObjChargeEffect() {};
	void Init();	//�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();	//�h���[
	void Set(int a);//�A�j���[�V�����R�}�ύX�p
private:
	int	   m_ani;	//���e�A�j���[�V�����p
	int	   m_ani_time;//���e�A�j���[�V�����Ԋu�^�C��
	RECT_F m_eff;	//���e�G�t�F�N�g�`��p
};