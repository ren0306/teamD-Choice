#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\SceneManager.h"

#include "ObjED3gazou.h"
#include "../ゲームメイン/SceneMain.h"
#include "../GameHead.h"



//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjED3gazou::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

}

//アクション
void CObjED3gazou::Action()
{
	//マウスの位置を取得
	//m_mou_x = (float)Input::GetPosX();
	//m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	//m_mou_r = Input::GetMouButtonR();
	//m_mou_l = Input::GetMouButtonL();

}

//ドロー
void CObjED3gazou::Draw()
{


	RECT_F src;
	RECT_F dst;




	float ED3[4] = { 1.0f,1.0f,1.0f,1.0f };
	//主人公表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 891.0f;
	src.m_bottom = 586.0f;
	dst.m_top = 130.0f;
	dst.m_left = 200.0f;
	dst.m_right = 650.0f;
	dst.m_bottom = 420.0f;
	Draw::Draw(3, &src, &dst, ED3, 0.0f);

	

}