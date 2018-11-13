//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjMain2.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjMain2::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0;
}

//アクション
void CObjMain2::Action()
{
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
	//謎画面遷移
	if (m_mou_x >170 && m_mou_x < 320 && m_mou_y>170 && m_mou_y < 455)
	{

	}


}

//ドロー
void CObjMain2::Draw()
{
	float c[4] = { 1,1,1,m_and };
	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);

}
