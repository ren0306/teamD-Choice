//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjMain5.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjMain5::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0f;
	m_f = false;
	m_key_flag = false;
	m_floor = 5;
}

//アクション
void CObjMain5::Action()
{
	float c[4] = { 1.f,1.f,1.f,m_and };

	/*if (m_f == true)
	{
	m_and += 0.1;
	if (m_and == 1.0)
	{
	m_f = false;
	}

	}*/
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();



}

//ドロー
void CObjMain5::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 0.0f,0.0f,0.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	
	////仮マウス位置表示
	//wchar_t str[256];
	//swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	//Font::StrDraw(str, 20, 20, 12, c);

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
			if (m_mou_x > 110 && m_mou_x < 360 && m_mou_y>238 && m_mou_y < 530)
			{
				Font::StrDraw(L"敵と戦うことを選ぶ", 455, 350, 32, c);
				//マウスのボタンが押されたら戦闘に遷移
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
						Scene::SetScene(new CSceneSTG5());
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
						Scene::SetScene(new CSceneMain5());
					}
				}
				else
				{
					Font::StrDraw(L"いいえ", 300, 150, 32, d);
				}

			}

			//謎画面遷移
			if (m_mou_x >455 && m_mou_x < 630 && m_mou_y>397 && m_mou_y < 584)
			{

				Font::StrDraw(L"謎解きを選ぶ", 455, 350, 32, c);

				if (m_mou_r == true || m_mou_l == true)
				{
					//仮でSceneNazoに繋いでいる。後でSceneNazo5に変更すべし。
					Scene::SetScene(new CSceneNazo5());
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
	src.m_right = 187.0f;
	src.m_bottom = 159.0f;

	//表示位置の設定
	dst.m_top = 0.0f + 200;
	dst.m_left = 0.0f + 50;
	dst.m_right = 200.0f + 250;
	dst.m_bottom = 160.0f + 400;

	//2番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(2, &src, &dst, c, 0.0f);
}
