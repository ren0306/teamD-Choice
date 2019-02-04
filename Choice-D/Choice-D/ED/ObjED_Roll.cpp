//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"
#include "../GameL/DrawTexture.h"
#include "../GameHead.h"
#include "ObjED_Roll.h"
#include "../ゲームメイン/SceneMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjED_Roll::Init()
{
	m_y = 0;
	m_and = 1.0f;
}

//アクション
void CObjED_Roll::Action()
{
	float c[4] = { 1,1,1,1 };
	float f[4] = { 1.0f,1.0f,1.0f,m_and };
	m_y--;
	//エンターキーで早送り機能
	if (Input::GetVKey(VK_RETURN) == true)
	{
		m_y -= 10;
	}
	//3秒後にだんだん消えていく
	if (m_y <= -300)
	{
		Font::StrDraw(L"Enterキー長押しで早送りできます", 0, 0, 32, f);

		m_and -= 0.02f;
	}
	else
	{
		Font::StrDraw(L"Enterキー長押しで早送りできます", 0, 0, 32, f);
	}

	Font::StrDraw(L"音源提供", 200, 600 + m_y, 32, c);

	Font::StrDraw(L"魔王魂", 200, 650 + m_y, 50, c);
	Font::StrDraw(L"https://maoudamashii.jokersounds.com/", 200, 700 + m_y, 32, c);

	Font::StrDraw(L"効果音ラボ", 200, 750 + m_y, 50, c);
	Font::StrDraw(L"https://soundeffect-lab.info/", 200, 800 + m_y, 32, c);

	Font::StrDraw(L"企画", 200, 850 + m_y, 50, c);
	Font::StrDraw(L"井ノ坂　裕貴", 200, 900 + m_y, 32, c);
	Font::StrDraw(L"後庵　穣", 200, 930 + m_y, 32, c);
	Font::StrDraw(L"清水　蓮", 200, 960 + m_y, 32, c);
	Font::StrDraw(L"田中　良明", 200, 990 + m_y, 32, c);
	Font::StrDraw(L"福田　広司", 200, 1020 + m_y, 32, c);

	Font::StrDraw(L"敵キャラクター製作者", 200, 1070 + m_y, 50, c);
	Font::StrDraw(L"敵１", 200, 1120 + m_y, 40, c);
	Font::StrDraw(L"後庵　穣", 200, 1160 + m_y, 32, c);

	Font::StrDraw(L"敵２", 200, 1400 + m_y, 40, c);
	Font::StrDraw(L"田中　良明", 200, 1440 + m_y, 32, c);

	Font::StrDraw(L"敵３", 200, 1700 + m_y, 40, c);
	Font::StrDraw(L"清水　蓮", 200, 1740 + m_y, 32, c);

	Font::StrDraw(L"敵４", 200, 2000 + m_y, 40, c);
	Font::StrDraw(L"井ノ坂　裕貴", 200, 2040 + m_y, 32, c);

	Font::StrDraw(L"敵５", 200, 2300 + m_y, 40, c);
	Font::StrDraw(L"福田　広司", 200, 2340 + m_y, 32, c);

	Font::StrDraw(L"制作に使ったソフト", 180, 2700 + m_y, 50, c);
	Font::StrDraw(L"Microsoft Visual Studio 2015", 180, 2750 + m_y, 32, c);

	Font::StrDraw(L"監督", 200, 3000 + m_y, 50, c);
	Font::StrDraw(L"清水　蓮", 200, 3100 + m_y, 40, c);

	if (m_y <= -3200)
	{
		Scene::SetScene(new CSceneTitle());
	}
}

//ドロー
void CObjED_Roll::Draw()
{
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//敵表示
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	//----------------------------------------------------------
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 986.0f;
	src.m_bottom = 785.0f;

	//表示位置の設定
	dst.m_top = 1210.0f + m_y;
	dst.m_left = 300.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 1470.0f + m_y;

	//1番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
	//----------------------------------------------------------
	//----------------------------------------------------------
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1071.0f;
	src.m_bottom = 865.0f;

	//表示位置の設定
	dst.m_top = 1490.0f + m_y;
	dst.m_left = 300.0f ;
	dst.m_right = 500.0f ;
	dst.m_bottom = 1650.0f + m_y;

	//2番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(2, &src, &dst, c, 0.0f);
	//----------------------------------------------------------
	//----------------------------------------------------------
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = 1770.0f + m_y;
	dst.m_left = 300.0f ;
	dst.m_right = 500.0f ;
	dst.m_bottom = 1930.0f + m_y;

	//3番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(3, &src, &dst, c, 0.0f);
	//-----------------------------------------------------------
	//-----------------------------------------------------------
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1152.0f;
	src.m_bottom = 1772.0f;

	//表示位置の設定
	dst.m_top = 2150.0f + m_y;
	dst.m_left = 300.0f;
	dst.m_right = 460.0f;
	dst.m_bottom = 2310.0f + m_y;

	//4番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(4, &src, &dst, c, 0.0f);
	//-----------------------------------------------------------
	//-----------------------------------------------------------
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 187.0f;
	src.m_bottom = 159.0f;

	//表示位置の設定
	dst.m_top = 2430.0f + m_y;
	dst.m_left = 300.0f ;
	dst.m_right = 500.0f;
	dst.m_bottom = 2590.0f + m_y;

	//10番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(5, &src, &dst, c, 0.0f);
	//-----------------------------------------------------------
}
