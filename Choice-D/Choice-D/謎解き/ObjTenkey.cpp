//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjTenkey.h"
#include "../ゲームメイン/SceneMain.h"
#include "../GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTenkey::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_f = true;
	m_ps = 50.f;
	m_psf = 0;
	m_reset_flag = false;
}

//アクション
void CObjTenkey::Action()
{
	if (m_mou_x >= 500 && m_mou_x <= 666 && m_mou_y >= 442 && m_mou_y <= 470)
	{
		if (m_mou_l == true)
		{
			Font::ListDelete();
		}
	}
	if (m_mou_x >= 5 && m_mou_x <= 232 && m_mou_y >= 445 && m_mou_y <= 470)
	{
		if (m_mou_l == true)
		{
			if (m_flag[5] == true && m_flag[4] == true && m_flag[7] == true)
			{
				Scene::SetScene(new CSceneMain2);
				Audio::Start(0);
			}
		}
	}

	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


	//マウスの位置とクリックする場所で当たり判定
	/*
	789
	456
	123
	*/
	//741
	if (m_mou_x > 300 && m_mou_x < 345)
	{
		//７入力
			if (m_mou_y > 373 && m_mou_y < 410)
			{
				if (m_mou_l == true)
				{
					m_flag[7] = true;
					m_psf = 2;
				}
			}
			//4入力
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
				if (m_mou_l == true)
				{
					m_flag[4] = true;
				}
			}

		
			//1入力
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					m_flag[1] = true;
				}
			}

		}
	//852
	if (m_mou_x > 353 && m_mou_x < 395)
	{
		//8入力
		if (m_mou_y > 373 && m_mou_y < 410)
		{
			if (m_mou_l == true)
			{		
				m_flag[8] = true;
			}

		}
		//5入力
		else if (m_mou_y > 416 && m_mou_y < 450)
		{
			if (m_mou_l == true)
			{
				m_flag[5] = true;
			}

		}
		//2入力
		else if (m_mou_y > 460 && m_mou_y < 494)
		{
			if (m_mou_l == true)
			{
				m_flag[2] = true;
			}

		}

	}
	//963
	if (m_mou_x > 406 && m_mou_x < 445)
		{
			//9入力
			if (m_mou_y > 373 && m_mou_y < 410)
			{
				if (m_mou_l == true)
				{
					m_flag[9] = true;
				}

			}
			//6入力
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
				if (m_mou_l == true)
				{
					m_flag[6] = true;
				}


			}
			//3入力
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					m_flag[3] = true;
				}

			}

		}
	//[すべて削除]を押すと(未実装)
	if (m_reset_flag == true)
	{
		return;
	}
	if (cnt == 4)
	{
		Scene::SetScene(new CSceneGameOver2);
	}
		
			


}

//ドロー
void CObjTenkey::Draw()
{
	float f[4] = { 1.0f,1.0f,1.0f,1.0f };
	float s[4] = { 1.0f,1.0f,0.0f,1.0f };

	float c[4] = { 1,1,1,1 };
	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	Font::StrDraw(L"[すべて削除]", 500, 450, 30, f);
	Font::StrDraw(L"[答え決定ボタン]", 0, 450, 30, s);
	Font::StrDraw(L"[メイン画面に戻る]", 32, 32, 30, f);

	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	//テンキー出力（切り取り位置）
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 1024.0f;
	//テンキー出力（出力位置）
	dst.m_top = 50.0f+300;
	dst.m_left = 0.0f+255;
	dst.m_right = 400.0f+100;
	dst.m_bottom =250.0f+300;
	Draw::Draw(2, &src, &dst, d, 0.0f);



	//解答出力（切り取り位置）
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1008.0f;
	src.m_bottom = 647.0f;
	//解答出力（出力位置）
	dst.m_top = 50.0f +100;
	dst.m_left = 0.0f ;
	dst.m_right = 600.0f + 300;
	dst.m_bottom = 450.0f + 250;
	Draw::Draw(12, &src, &dst, d, 0.0f);

	//問題出力（切り取り位置）
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1008.0f;
	src.m_bottom = 647.0f;
	//問題出力（出力位置）
	dst.m_top = 50.0f;
	dst.m_left = 80.0f;
	dst.m_right = 800.f;
	dst.m_bottom = 250.0f;
	Draw::Draw(13, &src, &dst, d, 0.0f);


	float o[4] = { 0.5f,0.0f,1.0f,1.0f };
	Font::StrDraw(L"1 2 3 4 5 6 7 8 9", 250, 300, 30, o);

	//m_flag[]の制御
	if (m_flag[1] == true)
	{
		Font::StrDraw(L"〇", 237, 293, 40, o);
	}

	if (m_flag[2] == true)
	{
		Font::StrDraw(L"〇", 267, 293, 40, o);
	}
	if (m_flag[3] == true)
	{
		Font::StrDraw(L"〇", 297, 293, 40, o);
	}
	if (m_flag[4] == true)
	{
		Font::StrDraw(L"〇", 327, 293, 40, o);

	}
	if (m_flag[5] == true)
	{
		Font::StrDraw(L"〇", 357, 293, 40, o);

	}
	if (m_flag[6] == true)
	{
		Font::StrDraw(L"〇", 387, 293, 40, o);

	}
	if (m_flag[7] == true)
	{
		Font::StrDraw(L"〇", 417, 293, 40, o);

	}
	if (m_flag[8] == true)
	{
		Font::StrDraw(L"〇", 447, 293, 40, o);

	}
	if (m_flag[9] == true)
	{
		Font::StrDraw(L"〇", 477, 293, 40, o);

	}

}





