//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjMain::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

}

//�A�N�V����
void CObjMain::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 400 && m_mou_x < 620 && m_mou_y>190 && m_mou_y < 230)
	{
		//�}�E�X�̃{�^���������ꂽ��퓬�ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneGameOver());
		}
	}
	else if (m_mou_x > 200 && m_mou_x < 420 && m_mou_y>190 && m_mou_y < 230)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneNazo());
		}

	}


}

//�h���[
void CObjMain::Draw()
{
	float c[4] = { 1,1,1,1 };
	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);

}
