//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"


#include "../GameHead.h"
#include "ObjKuria2.h"
#include "../�Q�[�����C��/SceneMain.h"




//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjKuria2::Init()
{
	//�}�E�X�̈ʒu
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0f;
}

//�A�N�V����
void CObjKuria2::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 470 && m_mou_x < 750 && m_mou_y>525 && m_mou_y < 565)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneMain3());
		}
	}
}

//�h���[
void CObjKuria2::Draw()
{
	


	RECT_F src;
	RECT_F dst;

	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�G��|����", 280, 260, 50, d);

	Font::StrDraw(L"���̃X�e�[�W��", 480, 535, 40, d);

}