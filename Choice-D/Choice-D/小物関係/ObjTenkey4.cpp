//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjTenkey4.h"
#include "../ゲームメイン/SceneMain4.h"
#include "../GameL/Audio.h"

#include <stdio.h>
//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTenkey4::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_f = true;
	m_andf = true;
	cnt = 0;
	m_and = 0.0f;
	m_flag[1] = false;
	m_flag[2] = false;
	m_flag[3] = false;
	m_flag[4] = false;
	m_flag[5] = false;
	m_flag[6] = false;
	m_flag[7] = false;
	m_flag[8] = false;
	m_flag[9] = false;
	m_cnt[1] = 0;
	m_cnt[2] = 0;
	m_cnt[3] = 0;
	m_cnt[4] = 0;
	m_cnt[5] = 0;
	m_cnt[6] = 0;
	m_cnt[7] = 0;
	m_cnt[8] = 0;
	m_cnt[9] = 0;

	m_clear = false;
	m_misscnt = 100.f;

	Hint_x = -904.0f;
	Hint_y = -383.0f;
}

//アクション
void CObjTenkey4::Action()
{
	if (m_andf == true)
	{
		m_and += 0.1f;
		if (m_and >= 1)
		{
			m_and = 1.0f;
			m_andf = false;
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
	Tenkey();
}

//ドロー
void CObjTenkey4::Draw()
{	//白
	float f[4] = { 1.0f,1.0f,1.0f,m_and };
	//赤
	float r[4] = { 1.0f,0.0f,0.0f,m_and };
	//黄色
	float s[4] = { 1.0f,1.0f,0.0f,m_and };
	//紫
	float o[4] = { 0.5f,0.0f,1.0f,m_and };
	//青
	float b[4] = { 0.0f,0.0f,1.0f,m_and };
	//緑
	float g[4] = { 0.0f,1.0f,0.0f,1.0 };

	Font::StrDraw(L"この問題は4桁の数字のみ入力可能です", 160, 550, 30, r);

	RECT_F src;
	RECT_F dst;

	////仮マウス位置表示
	//wchar_t str[256];
	//swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	//Font::StrDraw(str, 20, 20, 12, f);

	//メインに戻る
	if (m_mou_x >= 37 && m_mou_x <= 290 && m_mou_y >= 33 && m_mou_y <= 60)
	{
		Font::StrDraw(L"[◇メイン画面に戻る]", 32, 32, 30, f);
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneMain4);



		}
	}
	else
	{
		Font::StrDraw(L"[メイン画面に戻る]", 32, 32, 30, f);
		//BGMを登録
	}
	//謎解き答え正解にの場合3へ
	if (m_mou_x >= 5 && m_mou_x <= 232 && m_mou_y >= 445 && m_mou_y <= 470)
	{
		Font::StrDraw(L"[◇答え決定ボタン]", 0, 450, 25, s);

		if (m_mou_l == true)
		{
			//解答と答えを見比べる関数
			Anser();
			cnt = 0;
			if (m_f == true)
			{
				if (m_ok == true)
				{
					Audio::Start(3);
					//１つでも解くとtrueにする
					m_nazoflag = true;
					//ED分岐に関係
					m_Nazocnt++;
					//階層を一つ増やす
					m_floor++;
					//
					m_clear = true;
					m_TimeL += 1800;//３０秒増加

				}
				else
				{
					if (m_wannig == true)
					{
						Audio::Start(2);
						m_wannig = false;
					}
					m_TimeL -= 1800;//３０秒低下
					m_miss = true;
					m_flag[1] = false;
					m_flag[2] = false;
					m_flag[3] = false;
					m_flag[4] = false;
					m_flag[5] = false;
					m_flag[6] = false;
					m_flag[7] = false;
					m_flag[8] = false;
					m_flag[9] = false;
					m_num[1] = 0;
					m_num[2] = 0;
					m_num[3] = 0;
					m_num[4] = 0;
					m_num[5] = 0;
					m_num[6] = 0;
					m_num[7] = 0;
					m_num[8] = 0;
					m_num[9] = 0;
					m_cnt[1] = 0;
					m_cnt[2] = 0;
					m_cnt[3] = 0;
					m_cnt[4] = 0;
					m_cnt[5] = 0;
					m_cnt[6] = 0;
					m_cnt[7] = 0;
					m_cnt[8] = 0;
					m_cnt[9] = 0;


				}
				m_f = false;
			}

		}
		else
		{
			m_f = true;
			m_wannig = true;
		}

	}
	else
	{
		Font::StrDraw(L"[答え決定ボタン]", 0, 450, 30, s);
	}
	//間違えると３０秒低下したことを表示する処理
	if (m_miss == true)
	{
		Font::StrDraw(L"-30秒", 40, 50, 30, r);
		m_misscnt--;
		if (m_misscnt <= 0)
		{
			m_miss = false;
			m_misscnt = 100.f;
		}
	}
	if (m_clear == true)
	{
		m_and -= 0.02f;
		Font::StrDraw(L"+30秒", 40, 50, 30, g);
		if (m_and <= 0)
		{
			m_and = 0.0f;
			Scene::SetScene(new CSceneMain5);
			//ED分岐に関係
			m_Nazocnt++;
			//階層を一つ増やす
			m_floor++;

		}
	}

	//[すべて削除]を押すと
	if (m_mou_x >= 500 && m_mou_x <= 666 && m_mou_y >= 442 && m_mou_y <= 470)
	{
		Font::StrDraw(L"[◇すべて削除]", 500, 450, 30, f);

		if (m_mou_l == true)
		{
			if (m_f == true)
			{
				if (m_delete == true)
				{
					Audio::Start(1);
					m_delete = false;
				}
				m_flag[1] = false;
				m_flag[2] = false;
				m_flag[3] = false;
				m_flag[4] = false;
				m_flag[5] = false;
				m_flag[6] = false;
				m_flag[7] = false;
				m_flag[8] = false;
				m_flag[9] = false;
				m_num[1] = 0;
				m_num[2] = 0;
				m_num[3] = 0;
				m_num[4] = 0;
				m_num[5] = 0;
				m_num[6] = 0;
				m_num[7] = 0;
				m_num[8] = 0;
				m_num[9] = 0;
				m_cnt[1] = 0;
				m_cnt[2] = 0;
				m_cnt[3] = 0;
				m_cnt[4] = 0;
				m_cnt[5] = 0;
				m_cnt[6] = 0;
				m_cnt[7] = 0;
				m_cnt[8] = 0;
				m_cnt[9] = 0;

				cnt = 0;
				m_f = false;
			}
		}
		else
		{
			m_f = true;
			m_delete = true;
		}
	}
	else
	{

		Font::StrDraw(L"[すべて削除]", 500, 450, 30, f);
	}

	//ヒント箱クリックでヒント本体表示＆非表示
	if (m_mou_x >= 708 && m_mou_x <= 766 && m_mou_y >= 113 && m_mou_y <= 282)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			if (m_f == true)
			{
				m_f = false;

				//▼ヒント本体が非表示の場合、ヒント本体を表示させる
				if (Hint_x == -904.0f && Hint_y == -383.0f)
				{
					Hint_x = 0;
					Hint_y = 0;
				}
				//▼ヒント本体が表示の場合、ヒント本体を非表示させる
				else
				{
					Hint_x = -904.0f;
					Hint_y = -383.0f;
				}
			}
		}
		else
		{
			m_f = true;
		}
	}

	//テンキー出力（切り取り位置）
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 1024.0f;
	//テンキー出力（出力位置）
	dst.m_top = 50.0f + 300;
	dst.m_left = 0.0f + 255;
	dst.m_right = 400.0f + 100;
	dst.m_bottom = 250.0f + 300;
	Draw::Draw(2, &src, &dst, f, 0.0f);


	//解答出力（切り取り位置）
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1008.0f;
	src.m_bottom = 647.0f;
	//解答出力（出力位置）
	dst.m_top = 70.0f + 100;
	dst.m_left = 0.0f;
	dst.m_right = 700.0f + 300;
	dst.m_bottom = 450.0f + 250;
	Draw::Draw(12, &src, &dst, f, 0.0f);

	//問題出力（切り取り位置）
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 980.0f;
	src.m_bottom = 647.0f;
	//問題出力（出力位置）
	dst.m_top = 25.0f;
	dst.m_left = 60.0f;
	dst.m_right = 735.f;
	dst.m_bottom = 370.0f;
	Draw::Draw(13, &src, &dst, f, 0.0f);

	//ヒント箱出力（切り取り位置）
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 243.0f;
	src.m_bottom = 268.0f;
	//ヒント箱出力（出力位置）
	dst.m_top = 100.0f;
	dst.m_left = 670.0f;
	dst.m_right = 820.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(14, &src, &dst, f, 0.0f);

	//ヒント本体出力（切り取り位置）
	//▼切り取り位置を変化させる事で非表示と表示を切り替えている
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 600.0f + Hint_x;
	src.m_bottom = 420.0f + Hint_y;
	//ヒント本体出力（出力位置）
	dst.m_top = 50.0f;
	dst.m_left = 100.0f;
	dst.m_right = 700.f;
	dst.m_bottom = 260.0f;
	Draw::Draw(15, &src, &dst, f, 0.0f);

	Font::StrDraw(L"1 2 3 4 5 6 7 8 9", 250, 300, 30, o);

	//m_flag[]の制御
	if (m_flag[1] == true)
	{
		Font::StrDraw(L"〇", 237, 293, 40, o);
		m_num[1] = 1;
		if (m_cnt[1] == 2)
		{
			Font::StrDraw(L"〇", 237, 293, 40, s);
		}
		else if(m_cnt[1]==3)
		{
			Font::StrDraw(L"〇", 237, 293, 40, r);
		}
		else if (m_cnt[1] == 4)
		{
			Font::StrDraw(L"〇", 237, 293, 40, b);
		}

	}
	if (m_flag[2] == true)
	{
		Font::StrDraw(L"〇", 267, 293, 40, o);
		m_num[2] = 2;
		if (m_cnt[2] == 2)
		{
			Font::StrDraw(L"〇", 267, 293, 40, s);
		}
		else if (m_cnt[2] == 3)
		{
			Font::StrDraw(L"〇", 267, 293, 40, r);
		}
		else if (m_cnt[2] == 4)
		{
			Font::StrDraw(L"〇", 267, 293, 40, b);
		}


	}
	if (m_flag[3] == true)
	{
		Font::StrDraw(L"〇", 297, 293, 40, o);
		m_num[3] = 3;
		if (m_cnt[3] == 2)
		{
			Font::StrDraw(L"〇", 297, 293, 40, s);
		}
		else if (m_cnt[3] == 3)
		{
			Font::StrDraw(L"〇", 297, 293, 40, r);
		}
		else if (m_cnt[3] == 4)
		{
			Font::StrDraw(L"〇", 297, 293, 40, b);
		}

	}
	if (m_flag[4] == true)
	{
		Font::StrDraw(L"〇", 327, 293, 40, o);
		m_num[4] = 4;
		if (m_cnt[4] == 2)
		{
			Font::StrDraw(L"〇", 327, 293, 40, s);
		}
		else if (m_cnt[4] == 3)
		{
			Font::StrDraw(L"〇", 327, 293, 40, r);
		}
		else if (m_cnt[4] == 4)
		{
			Font::StrDraw(L"〇", 327, 293, 40, b);
		}

	}
	if (m_flag[5] == true)
	{
		Font::StrDraw(L"〇", 357, 293, 40, o);
		m_num[5] = 5;
		if (m_cnt[5] == 2)
		{
			Font::StrDraw(L"〇", 357, 293, 40, s);
		}
		else if (m_cnt[5] == 3)
		{
			Font::StrDraw(L"〇", 357, 293, 40, r);
		}
		else if (m_cnt[5] == 4)
		{
			Font::StrDraw(L"〇", 357, 293, 40, b);
		}


	}
	if (m_flag[6] == true)
	{
		Font::StrDraw(L"〇", 387, 293, 40, o);
		m_num[6] = 6;
		if (m_cnt[6] == 2)
		{
			Font::StrDraw(L"〇", 387, 293, 40, s);
		}
		else if (m_cnt[6] == 3)
		{
			Font::StrDraw(L"〇", 387, 293, 40, r);
		}
		else if (m_cnt[6] == 4)
		{
			Font::StrDraw(L"〇", 387, 293, 40, b);
		}

	}
	if (m_flag[7] == true)
	{
		Font::StrDraw(L"〇", 417, 293, 40, o);
		m_num[7] = 7;
		if (m_cnt[7] == 2)
		{
			Font::StrDraw(L"〇", 417, 293, 40, s);
		}
		else if (m_cnt[7] == 3)
		{
			Font::StrDraw(L"〇", 417, 293, 40, r);
		}
		else if (m_cnt[7] == 4)
		{
			Font::StrDraw(L"〇", 417, 293, 40, b);
		}


	}
	if (m_flag[8] == true)
	{
		Font::StrDraw(L"〇", 447, 293, 40, o);
		m_num[8] = 8;
		if (m_cnt[8] == 2)
		{
			Font::StrDraw(L"〇", 447, 293, 40, s);
		}
		else if (m_cnt[8] == 3)
		{
			Font::StrDraw(L"〇", 447, 293, 40, r);
		}
		else if (m_cnt[8] == 4)
		{
			Font::StrDraw(L"〇", 447, 293, 40, b);
		}

	}
	if (m_flag[9] == true)
	{
		Font::StrDraw(L"〇", 477, 293, 40, o);
		m_num[9] = 9;
		if (m_cnt[9] == 2)
		{
			Font::StrDraw(L"〇", 477, 293, 40, s);
		}
		else if (m_cnt[9] == 3)
		{
			Font::StrDraw(L"〇", 477, 293, 40, r);
		}
		else if (m_cnt[9] == 4)
		{
			Font::StrDraw(L"〇", 477, 293, 40, b);
		}

	}

}

void CObjTenkey4::Tenkey()
{
	//4桁のみ入力可能
	if (cnt != 4)
	{
		//741
		if (m_mou_x > 300 && m_mou_x < 345)
		{
			//７入力
			if (m_mou_y > 373 && m_mou_y < 410)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						Audio::Start(4);

						m_flag[7] = true;
						m_cnt[7]+=1;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}
			}
			//4入力
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_cnt[4] += 1;
						Audio::Start(4);

						m_flag[4] = true;
						cnt++;
						m_f = false;
					}

				}
				else
				{
					m_f = true;
				}

			}


			//1入力
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_cnt[1] += 1;
						Audio::Start(4);

						m_flag[1] = true;
						cnt++;
						m_f = false;
					}

				}
				else
				{
					m_f = true;
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
					if (m_f == true)
					{
						m_cnt[8] += 1;
						Audio::Start(4);

						m_flag[8] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}


			}
			//5入力
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_cnt[5] += 1;
						Audio::Start(4);

						m_flag[5] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}


			}
			//2入力
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_cnt[2] += 1;
						Audio::Start(4);

						m_flag[2] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
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
					if (m_f == true)
					{
						m_cnt[9] += 1;
						Audio::Start(4);

						m_flag[9] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}

			}
			//6入力
			else if (m_mou_y > 416 && m_mou_y < 450)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_cnt[6] += 1;
						Audio::Start(4);

						m_flag[6] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}


			}
			//3入力
			else if (m_mou_y > 460 && m_mou_y < 494)
			{
				if (m_mou_l == true)
				{
					if (m_f == true)
					{
						m_cnt[3] += 1;
						Audio::Start(4);

						m_flag[3] = true;
						cnt++;
						m_f = false;
					}
				}
				else
				{
					m_f = true;
				}

			}

		}
	}
	return;
}

bool CObjTenkey4::Anser()
{
	//答え
	int m_anser[QUESTION][ANSER] = {
		{ 4 },
		{ 1,5 },
		{ 7,4,8 },
		{ 2,2,4,2 },
		{ 5,6,7,9 },
	};
	cnt = 0;
	//答え確認処理
	for (int j = 0; j<4; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (m_num[i + 1] == m_anser[3][j])//答えた数字と正解を見比べる
			{
				cnt++;
				if (cnt == 4)
				{
					m_ok = true;
					return m_ok;
				}
				break;
			}
			else
			{
				;
			}
		}
	}
	m_ok = false;
	return m_ok;

}





