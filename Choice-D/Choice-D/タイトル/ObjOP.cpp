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
	m_gazo = false;
	m_flag = true;
	m_kesu = false;
}

//アクション
void CObjOP::Action()
{
	//Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//Audio::Start(0);
	float k[4] = { 0.3f,0.6f,0.6f,m_and };
	float c[4] = { 1.f,1.f,1.f,m_and };

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
				Audio::Start(1);
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
	float c[4] = { 1.f,1.f,1.f,m_and };
	float k[4] = { 0.7f,0.7f,0.0f,m_and };
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


	////仮マウス位置表示
	//wchar_t str[256];
	//swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	//Font::StrDraw(str, 20, 20, 12, c);
	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 565 && m_mou_x < 750 && m_mou_y>540 && m_mou_y < 570)
	{
		Font::StrDraw(L"◇脱出を試みる", 570, 550, 32, c);
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_l == true)
		{
			if (m_flag == true)
			{
				m_kesu = true;
				Audio::Start(2);

				m_flag = false;
			}
		}
		else
		{
			m_flag = true;
		}
	}
	else
	{
		Font::StrDraw(L"脱出を試みる", 570, 550, 32, c);
	}
	if (m_kesu == true)
	{
		m_and -= 0.02f;
		if (m_and <= 0)
		{
			Scene::SetScene(new CSceneMain());
		}
	}
	if (m_cnt==1)
	{
		Font::StrDraw(L"モンスターに捕まり、目覚めたら洞窟にいた", 115, 230, 30, k);
		Font::StrDraw(L"制限時間内にここから脱出をしよう！", 170, 320, 30, k);
	}
	
	if (m_cnt==2)
	{

		Font::StrDraw(L"ここから脱出するには、謎を解くか", 170, 230, 30, k);
		Font::StrDraw(L"敵を倒すしかありません", 175, 320, 30, k);
	}
	

	if (m_cnt == 3)
	{
		Font::StrDraw(L"謎を解いて次のステージに行く方法", 150, 80, 30, c);
		Font::StrDraw(L"扉をマウスでクリックし、問題が出てくるので",70,160,30,k);
		Font::StrDraw(L"問題を解いて次に行こう！",70,240,30,k);
		Font::StrDraw(L"ただし、問題を間違えると時間が30秒減るので注意",70,320,30,k);
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 763.0f;
		src.m_bottom = 567.0f;

		dst.m_top = 0.0f+360;
		dst.m_left = 50.0f;
		dst.m_right =410.0f+30;
		dst.m_bottom = 300.0f+300;
		Draw::Draw(2, &src, &dst, d, 0.0f);

	}

	if (m_cnt == 4)
	{
		Font::StrDraw(L"敵との戦闘について",250,30,35,c);
		Font::StrDraw(L"敵と戦うには敵をクリックすると、戦うか確認されるので",70,110,25,k);
		Font::StrDraw(L"「はい」を押すと戦える",70,170,25,k);
		Font::StrDraw(L"敵と戦うと戦いの音で他の敵に見つかるかもしれないので",70,230,25,k);
		Font::StrDraw(L"敵と戦うのはなるべく避けよう",70,290,25,k);
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 763.0f;
		src.m_bottom = 567.0f;

		dst.m_top = 0.0f + 360;
		dst.m_left = 50.0f;
		dst.m_right = 410.0f + 30;
		dst.m_bottom = 300.0f + 300;
		Draw::Draw(1, &src, &dst, d, 0.0f);

	}

	if (m_cnt == 5)
	{
		Font::StrDraw(L"準備ができたら下の「脱出を試みる」をクリックして",50,250,30, k);
		Font::StrDraw(L"脱出をしよう！",300,330,35, k);

	}
	/*if (m_cnt >= 6)
	{
		Scene::SetScene(new CSceneMain());

	}*/
	//Choice表示
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 455.0f;
	src.m_bottom = 180.0f;

	dst.m_top	 = 150.0f;
	dst.m_left	 = 150.0f;
	dst.m_right	 = 600.0f;
	dst.m_bottom = 400.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);



}