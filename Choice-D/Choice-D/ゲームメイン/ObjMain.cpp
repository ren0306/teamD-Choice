//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

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

}

//アクション
void CObjMain::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 400 && m_mou_x < 620 && m_mou_y>190 && m_mou_y < 230)
	{
		//マウスのボタンが押されたら戦闘に遷移
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneGameOver());
		}
	}
	else if (m_mou_x > 200 && m_mou_x < 420 && m_mou_y>190 && m_mou_y < 230)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneNazo());
		}

	}


}

//ドロー
void CObjMain::Draw()
{
	float c[4] = { 1,1,1,1 };
	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);

}
