//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"
#include "../GameL/Audio.h"
#include "../GameHead.h"
#include "ObjMain.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjMain::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0;
}

//アクション
void CObjMain::Action()
{
	float c[4] = { 1,1,1,m_and };

	if (m_f == true)
	{
		m_and += 0.1;
		if (m_and == 1.0)
		{
			m_f = false;
		}

	}
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
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	//戦闘画面遷移
	if (m_mou_x > 500 && m_mou_x < 765 && m_mou_y>220 && m_mou_y < 382)
	{
		Font::StrDraw(L"敵と戦うことを選ぶ", 400, 400, 32, c);

		//マウスのボタンが押されたら戦闘に遷移
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneSTG());
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
	//描画カラー情報　R=RED　G=Green　B=Blue　A=alpha(透過情報）A=alpha(透過情報）

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

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
