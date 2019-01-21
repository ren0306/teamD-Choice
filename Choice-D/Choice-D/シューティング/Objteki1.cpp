//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL/DrawFont.h"
#include "../GameHead.h"
#include <time.h>
#include "Objteki1.h"
#include "UtilityModule.h"
#include "../GameL/Audio.h"
#include <stdlib.h>
#include "../謎解き/ObjTenkey.h"





//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjteki1::CObjteki1(float x, float y)
{
	m_x = x;
	m_y = y;
}


//イニシャライズ
void CObjteki1::Init()
{
	m_hp = 30.f;
	m_maxhp = 30.f;
	m_f = true;
	m_time = 0;
	m_r = 85.0f;
	m_r2 = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_enemytime = 70;
	death = false;
	//当たり判定HitBox
	Hits::SetHitBox(this, m_x, m_y, 200, 170, ELEMENT_ENEMY, OBJ_TEKI1, 1);
}



//アクション
void CObjteki1::Action()
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

	RECT_F dst;//描画先表示位置

	//Audio::Start(0);
	//主人公（Hero）の生死を取得する
	CObjHero* Hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	Herodeath = Hero->GetDeath();

	
	//主人公（Hero）がもし死んでいたら音楽を止める
	if (Herodeath == true)
	{
		Audio::Stop(0);
	}
	//HitBox位置を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x +90, m_y +20);

	srand(time(NULL)); // ランダム情報を初期化


	m_time++;
	/*--敵弾製作所---------------------------------------------------------------------------------------------------
	//ほかの敵に使う場合はその部分をコピーしてね
	//※切り取りや削除はしないでね。してしまった場合Ctrl+Zを押したらたいてい戻るよ
	//----------------------------------------------------------------------------
	//通常弾発射プログラム
	if (m_time % 50 == 0)
	{
		//弾丸敵機オブジェクト
		CObjBulletTeki1* obj_b = new CObjBulletTeki1(m_x + 178, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_BULLET_TEKI1, 100);
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//20°間隔で弾丸発射(拡散弾発射)プログラム
	if (m_time % 100 == 0)
	{
		//19発同時発射
		CObjAngleBullet* obj_b;
		for (int i = 0; i < 360; i += 20)
		{
			//角度iで角度弾丸発射
			obj_b = new CObjAngleBullet(m_x + 178, m_y + 95, i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
		}
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//ショットガン風拡散弾発射(AngleBulletを応用している)プログラム
	//260°～ 280°の範囲(下方向)に2°間隔で弾丸発射
	if (m_time % 100 == 0)
	{
		//下方向に11発同時発射
		CObjAngleBullet* obj_b;
		for (int i = 260; i < 280; i += 2)
		{
			//角度iで角度弾丸発射
			obj_b = new CObjAngleBullet(m_x + 178, m_y + 95, i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
		}
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//誘導弾発射プログラム
	if (m_time % 200 == 0)
	{
		//誘導弾丸作成
		CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x + 178, m_y + 95);//誘導弾丸作成
		Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 100);//誘導弾丸登録
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//蛇行弾発射プログラム
	if (m_time % 50 == 0)
	{
		//蛇行弾丸作成
		CObjMeanderBullet* obj_b = new CObjMeanderBullet(m_x + 178, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_MEANDER_BULLET, 100);
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------------------*/
	//攻撃パターン
	if (m_time % 50 == 0)
	{
		if (m_hp <= 0)
		{
			;
		}
		else
		{
			//下方向に11発同時発射
			CObjAngleBullet* obj_b;
			for (float i = 260.0f; i < 280.0f; i += 2.0f)
			{
				//角度iで角度弾丸発射
				obj_b = new CObjAngleBullet(m_x + 178.0f, m_y + 95.0f, i, 5.0f);
				Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
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
	m_r2 += 0.5f;

	//360°で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;

	if (m_r2 > 360.0f)
		m_r2 = 0.0f;

	//移動方向
	m_vx = sin(3.14f / 180 * m_r);
	m_vy = sin(3.14f / 30 * m_r2);

	//移動ベクトル正規化
	UnitVec(&m_vy, &m_vx);

	//速度付ける。
	m_vx *= 2.5f;
	m_vy *= 2.5f;

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;


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
		//敵が死んだということを確認する用
		death = true;
		//爆破エフェクトが消えてから消滅させるための変数をデクリメント
		m_enemytime--;
		if (m_f == true)
		{
			Audio::Start(3);
			m_f = false;
		}
		else
		{
			;
		}
		//爆破エフェクト変数が０になったあと２階層へ
		if (m_enemytime <= 0)
		{
			//敵を１体でも倒すと反応するbool変数をtrueにする
			m_endflag = true;
			//階層数を管理しているグローバル変数をインクリメント
			m_floor++;
			//２階層へ
			Scene::SetScene(new CSceneKuria());
			g_CombatWaitTime = 300.f;//ここで必ず３００に再設定しておく

		}
	}
	else
	{
		obj->Set(false);

	}

}

//ドロー
void CObjteki1::Draw()
{


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//敵HP表示
	float h[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"敵のHP", 0, 75, 28, h);
	//敵表示
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


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
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 986.0f;
	src.m_bottom = 785.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 50.0f + m_x;
	dst.m_right = 350.0f + m_x;
	dst.m_bottom = 260.0f + m_y;

		//10番めに登録したグラフィックをsrc・dst・cの情報を元に描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//主人公（Hero）が死ぬか、敵が死んだらストップさせる
	if (Herodeath == true || death == true)
	{
		;
	}
	else
	{
		//戦闘が始まる３秒前からカウントダウンを画面に表示させるプログラム
		if (g_CombatWaitTime <= -100)
		{
			;
		}
		else if (g_CombatWaitTime <= 0)
		{
			Font::StrDraw(L"GO!", 380, 200, 100, c);
		}
		else if (g_CombatWaitTime <= 100)
		{
			Font::StrDraw(L"1", 400, 200, 100, c);
		}
		else if (g_CombatWaitTime <= 200)
		{
			Font::StrDraw(L"2", 400, 200, 100, c);
		}
		else if (g_CombatWaitTime >= 200)
		{
			Font::StrDraw(L"3", 400, 200, 100, c);
		}

	}

}

