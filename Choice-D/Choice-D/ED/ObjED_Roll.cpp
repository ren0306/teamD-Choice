//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjED_Roll.h"
#include "../ゲームメイン/SceneMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjED_Roll::Init()
{
	m_y = 0;
}

//アクション
void CObjED_Roll::Action()
{
	float c[4] = { 1,1,1,1 };
	m_y--;
	Font::StrDraw(L"テスト", 250, 400 + m_y, 100, c);














	if (m_y <= -450)
	{
		Scene::SetScene(new CSceneTitle());
	}
}

//ドロー
void CObjED_Roll::Draw()
{
}
