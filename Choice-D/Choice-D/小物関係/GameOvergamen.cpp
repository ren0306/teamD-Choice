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
	//�Q�[���I�[�o�[1�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 63.0f;
	src.m_bottom = 54.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 300.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(3, &src, &dst, ga, 0.0f);


	float ga2[4] = { 1.0f,1.0f,1.0f,1.0f }; //��l��
	//�Q�[���I�[�o�[2�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 63.0f;
	src.m_bottom = 54.0f;
	dst.m_top = 230.0f;
	dst.m_left = 320.0f;
	dst.m_right = 470.0f;
	dst.m_bottom = 360.0f;
	Draw::Draw(9, &src, &dst, ga, 0.0f);

	float ga3[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�Q�[���I�[�o�[2�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 230.0f;
	dst.m_left = 480.0f;
	dst.m_right = 650.0f;
	dst.m_bottom = 400.0f;
	Draw::Draw(12, &src, &dst, ga, 0.0f);

	float ga4[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�Q�[���I�[�o�[2�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 230.0f;
	dst.m_left = 300.0f;
	dst.m_right = 130.0f;
	dst.m_bottom = 400.0f;
	Draw::Draw(13, &src, &dst, ga, 0.0f);

	float ga5[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�Q�[���I�[�o�[2�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 120.0f;
	dst.m_left = 410.0f;
	dst.m_right = 580.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(14, &src, &dst, ga, 0.0f);

	float ga6[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�Q�[���I�[�o�[2�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 120.0f;
	dst.m_left = 380.0f;
	dst.m_right = 200.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(15, &src, &dst, ga, 0.0f);

}