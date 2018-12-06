//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjBGNazo.h"
#include "../ゲームメイン/SceneMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBGN::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_f = true;
	m_and = 0.0f;
}

//アクション
void CObjBGN::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

}

//ドロー
void CObjBGN::Draw()
{

	float c[4] = { 1,1,1,m_and };
	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	if (m_f == true)
	{
		m_and += 0.1;
		if (m_and >= 1)
		{
			m_and = 1.0f;
			m_f = false;
		}
	}

	float d[4] = { 1.0f,1.0f,1.0f,m_and};
	RECT_F src;
	RECT_F dst;
	//ドア1表示(切り取り位置)
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 650.0f;
	src.m_bottom = 946.0f;
	//ドア1表示(表示位置)
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 980.0f;
	Draw::Draw(1, &src, &dst, d, 0.0f);


}





