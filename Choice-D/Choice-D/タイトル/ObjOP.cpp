//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"



#include "../GameHead.h"
#include "ObjOP.h"
#include "../ゲームメイン/SceneMain.h"




//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjOP::Init()
{
	//マウスの位置
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0f;
	m_mz = true;
	m_st = false;
	m_f = true;
	m_op = false;
}

//アクション
void CObjOP::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	
}

//ドロー
void CObjOP::Draw()
{
	float c[4] = { 1,1,1,m_and };
	if (m_f == true)
	{
		m_and += 0.1f;
		if (m_and >= 1.0)
		{
			m_and = 1.0f;
			m_f = false;
		}

	}
	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 590 && m_mou_x < 780 && m_mou_y>540 && m_mou_y < 570)
	{
		Font::StrDraw(L"脱出を試みる", 600, 550, 32, c);
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_l == true)
		{
			m_andf = true;
		}
	}
	else
	{
		Font::StrDraw(L"脱出を試みる", 600, 550, 32, c);
	}
	if (m_mou_x > 430 && m_mou_x < 720 && m_mou_y>325 && m_mou_y < 355)
	{
		if (m_mou_l == true)
		{
			if (m_f == true)
			{
				m_mz = false;
				if (m_mz == false)
				{
					m_st = true;
				}
				m_op = true;
				m_f = false;
			}
		}
		else
		{
			m_f = true;
		}
	}

	if (m_mz == true)
	{
		float k[4] = { 0.3,0.6,0.6,1.0f };
		Font::StrDraw(L"モンスターに倒され、目覚めたら洞窟にいた", 115, 200, 30, k);
		Font::StrDraw(L"制限時間内にここから脱出をしよう！", 170, 250, 30, k);

		Font::StrDraw(L"ここをクリックで次へ", 430, 330, 30, c);
	}
	
		if (m_st == true)
		{
			(m_mou_x > 430 && m_mou_x < 720 && m_mou_y>325 && m_mou_y < 355);

			float k[4] = { 0.3,0.6,0.6,1.0f };
			Font::StrDraw(L"ここから脱出するには、謎を解くか", 170, 200, 30, k);
			Font::StrDraw(L"敵を倒すしかありません", 175, 250, 30, k);
			Font::StrDraw(L"ここをクリックで次へ", 430, 365, 30, c);
		}
	

	if (m_op == true)
	{

	}

	RECT_F src;
	RECT_F dst;

	float d[4] = { 1.0f,1.0f,1.0f,m_and };
	//Choice表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 455.0f;
	src.m_bottom = 180.0f;

	dst.m_top = 150.0f;
	dst.m_left = 150.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 400.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);



}