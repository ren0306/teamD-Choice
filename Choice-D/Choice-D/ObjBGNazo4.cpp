//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjBGNazo4.h"
#include "ゲームメイン/SceneMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBGN4::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//アクション
void CObjBGN4::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

}

//ドロー
void CObjBGN4::Draw()
{

	float c[4] = { 1,1,1,1 };
	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);


	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	//ドア1表示(切り取り位置)
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 189.0f;
	src.m_bottom = 266.0f;
	//ドア1表示(表示位置)
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 980.0f;
	Draw::Draw(1, &src, &dst, d, 0.0f);


}





