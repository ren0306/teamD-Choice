//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "GameOvergamen.h"
#include "../�Q�[�����C��/SceneMain.h"
#include "../GameHead.h"



//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjGameOvergamen::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

}

//�A�N�V����
void CObjGameOvergamen::Action()
{
	//�}�E�X�̈ʒu���擾
	//m_mou_x = (float)Input::GetPosX();
	//m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	//m_mou_r = Input::GetMouButtonR();
	//m_mou_l = Input::GetMouButtonL();

}

//�h���[
void CObjGameOvergamen::Draw()
{


	RECT_F src;
	RECT_F dst;




	float ga[4] = { 1.0f,1.0f,1.0f,1.0f };
	//���C���X�e�[�W1�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 63.0f;
	src.m_bottom = 54.0f;
	dst.m_top =180.0f;
	dst.m_left = 280.0f;
	dst.m_right = 500.0f;
	dst.m_bottom = 360.0f;
	Draw::Draw(3, &src, &dst, ga, 0.0f);




}