//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "ObjBackGround.h"
#include "SceneMain.h"
#include "../GameHead.h"



//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjBackGround::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

}

//�A�N�V����
void CObjBackGround::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

}

//�h���[
void CObjBackGround::Draw()
{

	
	RECT_F src;
	RECT_F dst;

	


	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	//���C���X�e�[�W�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 320.0f;
	src.m_bottom = 160.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);
	//�h�A�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 650.0f;
	src.m_bottom = 946.0f;
	dst.m_top = 0.0f;
	dst.m_left = 100.0f;
	dst.m_right = 400.0f;
	dst.m_bottom = 500.0f;
	Draw::Draw(1, &src, &dst, d, 0.0f);


	/*float p[4] = { 1.0f,1.0f,1.0f,1.0f };

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 450.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);

	//�V���[�e�B���O
	float q[4] = { 1.0f,1.0f,01.0f,1.0f };

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1920.0f;
	src.m_bottom = 1080.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, d, 0.0f);*/


	
}
