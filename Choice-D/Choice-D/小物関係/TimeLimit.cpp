//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "TimeLimit.h"
#include "../�Q�[�����C��/SceneMain.h"
#include "../GameHead.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;




//�C�j�V�����C�Y
void CObjTimeLimit::Init()
{
	/*m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;*/
}

//�A�N�V����
void CObjTimeLimit::Action()
{
	//�}�E�X�̈ʒu���擾
	//m_mou_x = (float)Input::GetPosX();
	//m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	//m_mou_r = Input::GetMouButtonR();
	//m_mou_l = Input::GetMouButtonL();
	m_TimeL--;

	if (m_TimeL == 0)
	{
		Scene::SetScene(new CSceneGameOver);
	}
}

//�h���[
void CObjTimeLimit::Draw()
{
	
	int second = (m_TimeL / 60) % 60; //�b
	int minute = (m_TimeL / 60) / 60; //��

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	if (second < 10)
	{
		swprintf_s(str, L"%d��0%d�b", minute, second);
	}
	else
	{
		swprintf_s(str, L"%d��%d�b", minute, second);
	}
	Font::StrDraw(str, 10, 10,  35, c);
}