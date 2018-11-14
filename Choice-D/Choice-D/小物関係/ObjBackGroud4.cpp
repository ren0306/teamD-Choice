//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "ObjBackGround4.h"
#include "../ゲームメイン/SceneMain4.h"
#include "../GameHead.h"
#include"../謎解き/ObjTenkey.h"


//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjBackGround4::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

}

//アクション
void CObjBackGround4::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

}

//ドロー
void CObjBackGround4::Draw()
{


	RECT_F src;
	RECT_F dst;

	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	//メインステージ2背景表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1920.0f;
	src.m_bottom = 1080.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);




}
