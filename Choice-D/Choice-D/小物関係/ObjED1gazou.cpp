#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "ObjED1gazou.h"
#include "../�Q�[�����C��/SceneMain.h"
#include "../GameHead.h"



//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjED1gazou::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

}

//�A�N�V����
void CObjED1gazou::Action()
{
	//�}�E�X�̈ʒu���擾
	//m_mou_x = (float)Input::GetPosX();
	//m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	//m_mou_r = Input::GetMouButtonR();
	//m_mou_l = Input::GetMouButtonL();

}

//�h���[
void CObjED1gazou::Draw()
{


	RECT_F src;
	RECT_F dst;




	float ED1[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�Q�[���I�[�o�[1�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 510.0f;
	src.m_bottom = 379.0f;
	dst.m_top = 100.0f;
	dst.m_left = 0.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 450.0f;
	Draw::Draw(3, &src, &dst, ED1, 0.0f);
}