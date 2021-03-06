//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL/DrawFont.h"
#include "../GameHead.h"
#include "Objteki2.h"
#include "UtilityModule.h"
#include "../GameL/Audio.h"
//使用するネームスペース
using namespace GameL;
//コンストラクタ
CObjteki2::CObjteki2(float x, float y)
{

	m_hp	= 35.f;
	m_maxhp = 35.f;
	m_f = true;
	m_time = 0;
	m_dtime = 70;
	m_x = x;
	m_y = y;
	m_tekicnt++;
}

//イニシャライズ
void CObjteki2::Init()
{
	m_r = 45.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	death = false;
	//当たり判定HitBox
	Hits::SetHitBox(this, m_x , m_y, 85, 130, ELEMENT_ENEMY, OBJ_TEKI2, 1);
}

//アクション
void CObjteki2::Action()
{
	//戦闘待機時間を管理するグローバル変数が０になったら戦闘開始
	if (g_CombatWaitTime >= 0)
	{
		g_CombatWaitTime--;
		return;
	}
	else if (g_CombatWaitTime <= 0)
	{
		g_CombatWaitTime--;
		;
	}

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x +55, m_y +20);

	m_time++;

	//通常弾発射
	if (m_time % 45 == 0)
	{
		if (m_hp <= 0)
		{
			;
		}
		else
		{
			//弾丸敵機オブジェクト
			CObjBulletTeki2* obj_b = new CObjBulletTeki2(m_x + 78, m_y + 95);
			Objs::InsertObj(obj_b, OBJ_BULLET_TEKI2, 100);
		}
	}

	//ショットガン風拡散弾発射(AngleBulletを応用している)
	//260°〜 280°の範囲(下方向)に2°間隔で弾丸発射
	if (m_hp <= 27)
	{
		if (m_time % 65 == 0)
		{
			if (m_hp <= 0)
			{
				;
			}
			else
			{
				//下方向に11発同時発射
				CObjAngleBullet* obj_b;
				for (float i = 250.f; i < 290.f; i += 8.f)
				{
					//角度iで角度弾丸発射
					obj_b = new CObjAngleBullet(m_x + 55.f, m_y + 105.f, i, 5.5f);
					Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
				}
			}
		}

	}

	//ショットガン風拡散弾発射(AngleBulletを応用している)
	//260°〜 280°の範囲(下方向)に2°間隔で弾丸発射
	if (m_hp <= 27)
	{
		if (m_time % 60 == 0)
		{
			if (m_hp <= 0)
			{
				;
			}
			else
			{
				//下方向に11発同時発射
				CObjAngleBullet* obj_b;
				for (float i = 250.f; i < 290.f; i += 8.f)
				{
					//角度iで角度弾丸発射
					obj_b = new CObjAngleBullet(m_x + 115.f, m_y + 105.f, i, 5.5f);
					Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
				}
			}
		}
	}

	//ショットガン風拡散弾発射(AngleBulletを応用している)
	//260°〜 280°の範囲(下方向)に2°間隔で弾丸発射
	if (m_hp <= 10)
	{
		if (m_time % 75 == 0)
		{
			if (m_hp <= 0)
			{
				;
			}
			else
			{
				//下方向に11発同時発射
				CObjAngleBullet* obj_b;
				for (float i = 245.f; i < 305.f; i += 12.f)
				{
					//角度iで角度弾丸発射
					obj_b = new CObjAngleBullet(m_x + 85.f, m_y + 105.f, i, 5.0f);
					Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
				}
			}
		}

	}


	//m_timeの初期化
	if (m_time > 1000)
	{
		m_time = 0;
	}

	//角度加算
	m_r += 1.0f;

	//360°で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;

	//移動方向
	m_vx = sin(3.14f / 180 * m_r);
	m_vy = 0.0f;

	//移動ベクトル正規化
	UnitVec(&m_vy, &m_vx);

	//速度付ける。
	m_vx *= 2.5f;
	m_vy *= 2.5f;

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;

	//敵機が完全に領域外にでたら敵機を破棄する
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);		//自身に削除命令
		Hits::DeleteHitBox(this);
	}
	//弾丸と接触してるしたらHPを減らす
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//チャージ弾のダメージ３
	if (hit->CheckObjNameHit(OBJ_CHARGE_BULLET) != nullptr)
	{
		m_hp -= 8;

	}

	CObjEnemyEX* obj = (CObjEnemyEX*)Objs::GetObj(OBJ_EX);
	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		obj->Set(true);
		death = true;
		m_dtime--;
		if (m_f == true)
		{
			Audio::Start(3);
			m_f = false;
		}
		else
		{
			;
		}


		if (m_dtime <= 0)
		{
			m_endflag = true;
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			m_floor++;
			g_teki = false;
			Scene::SetScene(new CSceneKuria2());
			g_CombatWaitTime = 300.f;//ここで必ず３００に再設定しておく

		}
	}
	else
	{
		obj->Set(false);
	}
}

//ドロー
void CObjteki2::Draw()
{
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//敵HP表示
	float h[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"敵のHP", 0, 75, 28, h);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1280.0f;
	src.m_bottom = 720.0f;

	//表示位置の設定
	dst.m_top = 100.0f;
	dst.m_left = 0.0f;
	dst.m_right = (m_hp / m_maxhp)*128.0f;
	dst.m_bottom = 125.0f;

	//5番目に登録したグラフィックをsrc・dst・cの元の情報に描画
	Draw::Draw(5, &src, &dst, h, 0.0f);

	if (death == false)
	{
		//敵２表示
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };


		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1071.0f;
		src.m_bottom = 865.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 200.0f + m_x;
		dst.m_bottom = 160.0f + m_y;

		//10番めに登録したグラフィックをsrc・dst・cの情報を元に描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (g_CombatWaitTime >= 200)
	{
		Font::StrDraw(L"3", 400, 200, 100, c);
	}
	else if (g_CombatWaitTime <= -100)
	{
		;
		//Font::StrDraw(L" ", 400, 200, 100, c);
	}
	else if (g_CombatWaitTime <= 0)
	{
		Font::StrDraw(L"GO!", 400, 200, 100, c);
	}
	else if (g_CombatWaitTime <= 100)
	{
		Font::StrDraw(L"1", 400, 200, 100, c);
	}
	else if (g_CombatWaitTime <= 200)
	{
		Font::StrDraw(L"2", 400, 200, 100, c);
	}

}