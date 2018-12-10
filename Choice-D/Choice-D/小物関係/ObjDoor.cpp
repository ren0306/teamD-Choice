//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "ObjDoor.h"
#include "../ゲームメイン/SceneMain.h"
#include "../GameHead.h"



//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjDoor::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 0.0f;
	m_f = true;
}

//アクション
void CObjDoor::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

//ドロー
void CObjDoor::Draw()
{


	RECT_F src;
	RECT_F dst;

	if (m_f == true)
	{
		m_and += 0.01f;
		if (m_and >= 1)
		{
			m_and = 1.0f;
			m_f = false;
		}
	}

	float d[4] = { 1.0f,1.0f,1.0f,m_and };
	//ドア1表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 650.0f;
	src.m_bottom = 946.0f;
	dst.m_top = 0.0f;
	dst.m_left = 100.0f;
	dst.m_right = 400.0f;
	dst.m_bottom = 500.0f;
	Draw::Draw(1, &src, &dst, d, 0.0f);




}
