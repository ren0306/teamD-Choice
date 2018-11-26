//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "TimeLimit.h"
#include "../ゲームメイン/SceneMain.h"
#include "../GameHead.h"


//使用するネームスペース
using namespace GameL;




//イニシャライズ
void CObjTimeLimit::Init()
{
	/*m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;*/
	m_time = 19856;
}

//アクション
void CObjTimeLimit::Action()
{
	//マウスの位置を取得
	//m_mou_x = (float)Input::GetPosX();
	//m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	//m_mou_r = Input::GetMouButtonR();
	//m_mou_l = Input::GetMouButtonL();
	m_time--;

}

//ドロー
void CObjTimeLimit::Draw()
{
	
	int second = (m_time / 60) % 60; //秒
	int minute = (m_time / 60) / 60; //分

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	if (second < 10)
	{
		swprintf_s(str, L"%d分0%d秒", minute, second);
	}
	else
	{
		swprintf_s(str, L"%d分%d秒", minute, second);
	}
	Font::StrDraw(str, 10, 10,  20, c);
}