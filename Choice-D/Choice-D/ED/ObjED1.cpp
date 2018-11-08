//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "../�^�C�g��/ObjTitle.h"
#include "../�Q�[�����C��/SceneMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjED1::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//�A�N�V����
void CObjED1::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 450 && m_mou_x < 730 && m_mou_y>525 && m_mou_y < 560)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}

}

//�h���[
void CObjED1::Draw()
{
	float c[4] = { 1,1,1,1 };
	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	
	float o[4] = { 0.5f,0.0f,1.0f,1.0f };
	Font::StrDraw(L"BAD END", 250, 50, 90, o);

	float a[4] = { 0.5f,0.5f,0.5f,1.0f };
	Font::StrDraw(L"�G�Ɛ���Ă����炽������̓G���W�܂��Ă��ĕ߂炦��ꂽ", 70, 450, 25, a);

	float s[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�N���b�N�Ń^�C�g����", 460, 535, 25, s);
}
