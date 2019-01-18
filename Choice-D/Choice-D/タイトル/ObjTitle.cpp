//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"
#include "../GameL/Audio.h"

#include "../GameHead.h"
#include "ObjTitle.h"
#include "../ゲームメイン/SceneMain.h"




//使用するネームスペース
using namespace GameL;

//GameHead.hで定義したグローバル変数をここで初期化----------------------
bool m_nazoflag = false;
int m_Nazocnt = 0;
bool m_endflag = false;
int m_tekicnt = 0;
int m_TimeL = 19800;
int m_floor = 1;
float m_Mehp = 20.f;
bool m_clear = false;
bool m_miss = false;//答え間違いならtrue変数
float m_clearcnt=100.f;
float m_misscnt=100.f;//間違えた時の時間を減らす表示をする変数	
float m_BGM = 0;
bool g_teki = false;
//----------------------------------------------------------------------

//イニシャライズ
void CObjTitle::Init()
{
	//マウスの位置
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 0.0f;
	m_end = false;
	m_sousa = false;
	m_andf = true;
	m_flag = true;
	m_flag2 = true;
	m_flag3 = true;

}

//アクション
void CObjTitle::Action()
{
	if (m_andf == true)
	{
		m_and += 0.03f;
		if (m_and >= 1)
		{
			m_and = 1.0;
			m_andf = false;
		}

	}



	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//グローバル変数をタイトルに来たらすべて初期化-------------------
	m_Nazocnt = 0;
	m_nazoflag = false;
	m_endflag = false;
	m_tekicnt = 0;
	m_floor = 1;
	m_TimeL = 19800;
	m_Mehp = 20.f;
	m_clear = false;
	m_miss = false;
	//---------------------------------------------------------------
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,m_and };
	////仮マウス位置表示
	//wchar_t str[256];
	//swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	//Font::StrDraw(str, 20, 20, 12,c);

	//前シーンから左または右クリックを押し続けている、
	//もしくはこのシーンに入って一度でもクリックを押してない状態に移行すると実行。
	if (m_mou_r == true || m_mou_l == true || m_key_flag == true)
	{
		//マウスの位置とクリックする場所で当たり判定
		//OPに移行
		if (m_mou_x > 400 && m_mou_x < 620 && m_mou_y>390 && m_mou_y < 430)
		{
			Font::StrDraw(L"◇ゲームを始める", 400, 400, 32, c);
			//マウスのボタンが押されたらメインに遷移
			if (m_mou_l == true)
			{

				m_f = true;

			}
		}
		else
		{
			Font::StrDraw(L"ゲームを始める", 400, 400, 32, c);
		}
		//操作画面移行
		if (m_mou_x > 400 && m_mou_x < 620 && m_mou_y>430 && m_mou_y < 480)
		{

			Font::StrDraw(L"◇操作説明", 400, 450, 32, c);
			//操作説明
			if (m_mou_l == true)
			{

				m_sousa = true;
			}
		}
		else
		{
			Font::StrDraw(L"操作説明", 400, 450, 32, c);
		}
		//ゲーム終了
		if (m_mou_x > 400 && m_mou_x < 635 && m_mou_y>493 && m_mou_y < 520)
		{

			Font::StrDraw(L"◇Choiceを終了する", 400, 500, 32, c);
			//ゲーム終了
			//▼前シーンからクリック押し続けでこれをクリックしないように、
			//このシーンに入って一度でもクリックを押してない状態に移行しないと
			//実行出来ないようにしている。
			if (m_mou_l == true && m_key_flag == true)
			{

				m_end = true;
			}
		}
		else
		{
			Font::StrDraw(L"Choiceを終了する", 400, 500, 32, c);
		}
		//OP移行フラグ
		if (m_f == true)
		{
			if (m_flag == true)
			{
				Audio::Start(1);
				m_flag = false;
			}
			m_and -= 0.02f;
			if (m_and <= 0)
			{

				Scene::SetScene(new CSceneOP());
				m_f = false;
			}
		}
		else
		{
			m_flag = true;
		}
		//プログラム終了フラグ
		if (m_end == true)
		{
			if (m_flag2 == true)
			{
				Audio::Start(1);
				m_flag2 = false;
			}

			m_and -= 0.03f;
			if (m_and <= 0)
			{
				exit(4);
			}
		}
		else
		{
			m_flag2 = true;
		}
		//操作説明移行フラグ
		if (m_sousa == true)
		{
			if (m_flag3 == true)
			{
				Audio::Start(1);
				m_flag3 = false;
			}

			m_and -= 0.03f;
			if (m_and <= 0)
			{

				Scene::SetScene(new CSceneSousagamen());
			}

		}
		else
		{
			m_flag3 = true;
		}
	}
	else
	{
		m_key_flag = true;
	}

	RECT_F src;
	RECT_F dst;

	float d[4] = { 1.0f,1.0f,1.0f,m_and };
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
