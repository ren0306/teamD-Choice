//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"


#include "../GameHead.h"
#include "ObjKuria.h"
#include "../ゲームメイン/SceneMain.h"




//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjKuria::Init()
{
	//マウスの位置
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0f;
}

//アクション
void CObjKuria::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain2());
	}
}

//ドロー
void CObjKuria::Draw()
{
	
	

	RECT_F src;
	RECT_F dst;

	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"敵を倒した", 280, 260, 50, d);

	Font::StrDraw(L"次のステージへ", 480, 535, 40, d);

}