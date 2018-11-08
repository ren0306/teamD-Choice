//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "../タイトル/ObjTitle.h"
#include "../ゲームメイン/SceneMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjED1::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//アクション
void CObjED1::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 450 && m_mou_x < 730 && m_mou_y>525 && m_mou_y < 560)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}

}

//ドロー
void CObjED1::Draw()
{
	float c[4] = { 1,1,1,1 };
	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	
	float o[4] = { 0.5f,0.0f,1.0f,1.0f };
	Font::StrDraw(L"BAD END", 250, 50, 90, o);

	float a[4] = { 0.5f,0.5f,0.5f,1.0f };
	Font::StrDraw(L"敵と戦っていたらたくさんの敵が集まってきて捕らえられた", 70, 450, 25, a);

	float s[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"クリックでタイトルへ", 460, 535, 25, s);
}
