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
	m_and = 0.0f;
	m_f = true;
}

//�A�N�V����
void CObjTimeLimit::Action()
{
	if (g_RTA == true)
	{
		;
	}
	else
	{
		m_TimeL--;
	}

	if (m_TimeL <= 0)
	{
		Scene::SetScene(new CSceneGameOver);
	}
}

//�h���[
void CObjTimeLimit::Draw()
{
	
	int second = (m_TimeL / 60) % 60; //�b
	int minute = (m_TimeL / 60) / 60; //��

	if (m_f == true)
	{
		m_and += 0.1f;
		if (m_and >= 1)
		{
			m_and=1.0f;
			m_f = false;
		}
	}
	float c[4] = { 1.0f,1.0f,1.0f,m_and };
	wchar_t str[128];
	if (second < 10)
	{
		swprintf_s(str, L"%d��0%d�b", minute, second);
	}
	else
	{
		swprintf_s(str, L"%d��%d�b", minute, second);
	}
	Font::StrDraw(str, 0, 0,  35, c);
}