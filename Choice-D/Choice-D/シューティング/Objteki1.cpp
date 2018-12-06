//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"
#include <stdlib.h>
#include <time.h>


#include "../GameHead.h"
#include "Objteki1.h"
#include "../謎解き/ObjTenkey.h"
#include "UtilityModule.h"
#include "../GameL/DrawFont.h"


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
	m_f = false;
	m_time = 0;
	m_r = 85.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	//当たり判定HitBox
	Hits::SetHitBox(this, m_x, m_y, 200, 170, ELEMENT_ENEMY, OBJ_TEKI1, 1);
}



//アクション
void CObjteki1::Action()
{
	//HitBox位置を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x +90, m_y +20);

	srand(time(NULL)); // ランダム情報を初期化


	m_time++;

	//通常弾発射
	if (m_time % 50 == 0)
	{
		//弾丸敵機オブジェクト
		CObjBulletTeki1* obj_b = new CObjBulletTeki1(m_x + 178, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_BULLET_TEKI1, 100);

	}

	//以下の拡散弾、誘導弾等のプログラムは
	//TEST用で一時的に追加してるだけなので
	//不要な場合はコメントアウトしてOK。

	//20°間隔で弾丸発射(拡散弾発射)
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

	//ショットガン風拡散弾発射(AngleBulletを応用している)
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

	//誘導弾発射
	if (m_time % 200 == 0)
	{
		//誘導弾丸作成
		CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x + 178, m_y + 95);//誘導弾丸作成
		Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 100);//誘導弾丸登録
	}

	//蛇行弾発射
	if (m_time % 50 == 0)
	{
		//蛇行弾丸作成
		CObjMeanderBullet* obj_b = new CObjMeanderBullet(m_x + 178, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_MEANDER_BULLET, 100);
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
	m_vx = sin(3.14 / 180 * m_r);
	m_vy = 0.0f;

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
	//HP０で
	if (m_hp <= 0)
	{
		m_endflag = true;
		m_tekicnt++;
		m_floor++;
		/*this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//敵機弾丸が所有するHItBoxに削除する*/
		Scene::SetScene(new CSceneKuria());

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

	//敵表示
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 984.0f;
	src.m_bottom = 760.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 400.0f + m_x;
	dst.m_bottom = 260.0f + m_y;

	//10番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(10, &src, &dst, c, 0.0f);





}

