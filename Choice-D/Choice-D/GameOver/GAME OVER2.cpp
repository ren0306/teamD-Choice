//使用するヘッダーファイル
#include "../GameL\DrawFont.h"
#include "../GameL\WinInputs.h"

#include "../GameHead.h"
#include "GAME OVER2.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGAMEOVER2::Init()
{

}

//アクション
void CObjGAMEOVER2::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 280 && m_mou_x < 480 && m_mou_y>495 && m_mou_y < 516)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}
}

//ドロー
void CObjGAMEOVER2::Draw()
{
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };
	Font::StrDraw(L"GAME OVER", 270, 50, 50, c);
	float m[4] = { 0.5f,0.5f,0.5f,1.0f };

	Font::StrDraw(L"敵に倒された", 300, 400, 30, m);
	float s[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"タイトル画面へ", 280, 500, 30, s);

	

}