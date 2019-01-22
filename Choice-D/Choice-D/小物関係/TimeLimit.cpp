//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "TimeLimit.h"
#include "../ゲームメイン/SceneMain.h"
#include "../GameHead.h"


//使用するネームスペース
using namespace GameL;




//イニシャライズ
void CObjTimeLimit::Init()
{
	m_and = 0.0f;
	m_f = true;
}

//アクション
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

//ドロー
void CObjTimeLimit::Draw()
{
	
	int second = (m_TimeL / 60) % 60; //秒
	int minute = (m_TimeL / 60) / 60; //分

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
		swprintf_s(str, L"%d分0%d秒", minute, second);
	}
	else
	{
		swprintf_s(str, L"%d分%d秒", minute, second);
	}
	Font::StrDraw(str, 0, 0,  35, c);
}