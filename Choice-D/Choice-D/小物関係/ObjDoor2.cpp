//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "ObjDoor2.h"
#include "../�Q�[�����C��/SceneMain2.h"
#include "../GameHead.h"



//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjDoor2::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

}

//�A�N�V����
void CObjDoor2::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

}

//�h���[
void CObjDoor2::Draw()
{


	RECT_F src;
	RECT_F dst;

	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�h�A2�\��(SceneMain2)
	//�؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 188.0f;
	src.m_bottom = 266.0f;
	//�\���ʒu
	dst.m_top = 400.0f;
	dst.m_left = 450.0f;
	dst.m_right = 650.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, d, 0.0f);

	//�h�A2�\��(SceneMain3)
	//�؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 188.0f;
	src.m_bottom = 266.0f;
	//�\���ʒu
	dst.m_top = 65.0f;
	dst.m_left = 480.0f;
	dst.m_right = 720.0f;
	dst.m_bottom = 320.0f;
	Draw::Draw(10, &src, &dst, d, 0.0f);

	//�h�A2�\��(SceneMain4)
	//�؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 188.0f;
	src.m_bottom = 266.0f;
	//�\���ʒu
	dst.m_top = 400.0f;
	dst.m_left = 450.0f;
	dst.m_right = 650.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(20, &src, &dst, d, 0.0f);

	//�h�A2�\��(SceneMain5)
	//�؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 188.0f;
	src.m_bottom = 266.0f;
	//�\���ʒu
	dst.m_top = 400.0f;
	dst.m_left = 450.0f;
	dst.m_right = 650.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(30, &src, &dst, d, 0.0f);
}
