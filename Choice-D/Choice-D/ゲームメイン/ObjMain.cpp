//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"
#include "../GameL/Audio.h"
#include "../GameHead.h"
#include "ObjMain.h"
#include "../小物関係/TimeLimit.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMain::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 0.0;
	m_f = false;
	m_key_flag = false;
	m_andf = true;
}

//アクション
void CObjMain::Action()
{
	float c[4] = { 1,1,1,m_and };


	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

}

//ドロー
void CObjMain::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,m_and };
	float d[4] = { 0.0f,0.0f,0.0f,m_and};
	if (m_andf == true)
	{
		m_and += 0.03;
		if (m_and >= 1)
		{
			m_and = 1.0;
			m_andf = false;
		}

	}
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	//階層表示
	wchar_t kaisou[4];
	swprintf_s(kaisou, L"%d階層", m_floor);
	Font::StrDraw(kaisou, 710, 0, 35, c);

	//前シーンから左または右クリックを押し続けている、
	//もしくはこのシーンに入って一度でもクリックを押してない状態に移行すると実行。
	if (m_mou_r == true || m_mou_l == true || m_key_flag == true)
	{
		//このシーンに入って一度でもクリックを押してない状態に移行すると実行。
		if (m_key_flag == true)
		{
			//戦闘画面遷移
			if (m_mou_x > 500 && m_mou_x < 765 && m_mou_y>220 && m_mou_y < 382)
			{
				Font::StrDraw(L"敵と戦うことを選ぶ", 400, 400, 32, c);
				//マウスのボタンが押されたら選択に遷移
				if (m_mou_r == true || m_mou_l == true)
				{
					m_f = true;

				}

			}
			if (m_f == true)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 768.0f;
				src.m_bottom = 614.0f;

				//表示位置の設定
				dst.m_top = 0.0f;
				dst.m_left = 0.0f;
				dst.m_right = 500.0f;
				dst.m_bottom = 300.0f;

				//3番めに登録したグラフィックをsrc・dst・cの情報を元に描画
				Draw::Draw(3, &src, &dst, c, 0.0f);
				if (m_mou_x > 100 && m_mou_x < 160 && m_mou_y>150 && m_mou_y < 175)
				{
					Font::StrDraw(L"◇はい", 100, 150, 32, d);
					if (m_mou_l == true)
					{
						Scene::SetScene(new CSceneSTG());
					}
				}
				else
				{
					Font::StrDraw(L"はい", 100, 150, 32, d);
				}
				if (m_mou_x > 300 && m_mou_x < 380 && m_mou_y>150 && m_mou_y < 175)
				{
					Font::StrDraw(L"◇いいえ", 300, 150, 32, d);
					if (m_mou_l == true)
					{
						Scene::SetScene(new CSceneMain());
					}
				}
				else
				{
					Font::StrDraw(L"いいえ", 300, 150, 32, d);
				}

			}

			//謎画面遷移
			if (m_mou_x >170 && m_mou_x < 320 && m_mou_y>170 && m_mou_y < 455)
			{

				Font::StrDraw(L"謎解きを選ぶ", 400, 400, 32, c);

				if (m_mou_r == true || m_mou_l == true)
				{
					Scene::SetScene(new CSceneNazo());
				}

			}
		}
	}
	else
	{
		m_key_flag = true;
	}

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 984.0f;
	src.m_bottom = 760.0f;

	//表示位置の設定
	dst.m_top = 0.0f+200;
	dst.m_left = 0.0f+500;
	dst.m_right = 800.0f ;
	dst.m_bottom = 260.0f+200;

	//2番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(2, &src, &dst, c, 0.0f);



}
