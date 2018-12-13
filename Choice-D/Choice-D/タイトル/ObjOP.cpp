//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"
#include "../GameHead.h"
#include "../GameL/Audio.h"
#include "ObjOP.h"
#include "../ゲームメイン/SceneMain.h"




//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjOP::Init()
{
	//マウスの位置
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 0.0f;
	m_f = true;
	m_cnt = 1;
}

//アクション
void CObjOP::Action()
{
	//Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//Audio::Start(0);
	float k[4] = { 0.3,0.6,0.6,m_and };
	float c[4] = { 1,1,1,m_and };

	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//クリック処理
	if (m_mou_x >= 450 && m_mou_x <= 740 && m_mou_y >= 470 && m_mou_y <= 500)
	{
		if (m_cnt >= 5)
		{
			return;
		}

		if (m_mou_l == true)
		{

			if (m_flag == true)
			{
				m_cnt++;
				m_flag = false;

			}
		}
		else
		{
			m_flag = true;
		}
	}
	if (m_cnt >= 5)
	{
		return;
	}
	else
	{
		Font::StrDraw(L"ここをクリックで次へ", 450, 480, 30, c);
	}
}

//ドロー
void CObjOP::Draw()
{
	float c[4] = { 1,1,1,m_and };
	float k[4] = { 0.7,0.7,0.0,m_and };
	float d[4] = { 1.0f,1.0f,1.0f,m_and };

	RECT_F src;
	RECT_F dst;

	//フェードイン・フェードアウト
	if (m_f == true)
	{
		m_and += 0.1f;
		if (m_and >= 1.0)
		{
			m_and = 1.0f;
			m_f = false;
		}

	}


	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 565 && m_mou_x < 750 && m_mou_y>540 && m_mou_y < 570)
	{
		Font::StrDraw(L"◇脱出を試みる", 570, 550, 32, c);
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneMain());
		}
	}
	else
	{
		Font::StrDraw(L"脱出を試みる", 570, 550, 32, c);
	}
	if (m_cnt==1)
	{
		Font::StrDraw(L"モンスターに倒され、目覚めたら洞窟にいた", 115, 200, 30, k);
		Font::StrDraw(L"制限時間内にここから脱出をしよう！", 170, 250, 30, k);

	}
	
	if (m_cnt==2)
	{

		Font::StrDraw(L"ここから脱出するには、謎を解くか", 170, 200, 30, k);
		Font::StrDraw(L"敵を倒すしかありません", 175, 250, 30, k);
	}
	

	if (m_cnt == 3)
	{
		Font::StrDraw(L"謎を解いて次のステージに行く方法", 150, 100, 30, c);
		Font::StrDraw(L"扉をマウスでクリックし、問題が出てくるので",70,180,30,k);
		Font::StrDraw(L"問題を解いて次に行こう！",70,260,30,k);
		Font::StrDraw(L"ただし、問題を間違えると時間が30秒減るので注意",70,340,30,k);
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 763.0f;
		src.m_bottom = 567.0f;

		dst.m_top = 0.0f+380;
		dst.m_left = 50.0f;
		dst.m_right =420.0f+30;
		dst.m_bottom = 320.0f+300;
		Draw::Draw(1, &src, &dst, d, 0.0f);

	}

	if (m_cnt == 4)
	{
		Font::StrDraw(L"敵との戦闘について",250,100,35,c);
		Font::StrDraw(L"敵と戦うには敵をクリックすると、戦うか確認されるので",70,180,25,k);
		Font::StrDraw(L"「はい」を押すと戦える",70,260,25,k);
		Font::StrDraw(L"敵と戦うと戦いの音で他の敵に見つかるかもしれないので",70,340,25,k);
		Font::StrDraw(L"敵と戦うのはなるべく避けよう",450,420,25,k);
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 763.0f;
		src.m_bottom = 567.0f;

		dst.m_top = 0.0f + 380;
		dst.m_left = 50.0f;
		dst.m_right = 420.0f + 30;
		dst.m_bottom = 320.0f + 300;
		Draw::Draw(2, &src, &dst, d, 0.0f);

	}

	if (m_cnt == 5)
	{
		Font::StrDraw(L"準備ができたら下の「脱出を試みる」をクリックして",60,230,30, k);
		Font::StrDraw(L"脱出をしよう！",300,300,35, k);

	}
	if (m_cnt >= 6)
	{
		Scene::SetScene(new CSceneMain());

	}
	//Choice表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 455.0f;
	src.m_bottom = 180.0f;

	dst.m_top = 150.0f;
	dst.m_left = 150.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 400.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);



}