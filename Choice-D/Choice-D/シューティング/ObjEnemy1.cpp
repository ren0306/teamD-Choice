//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"

#include "../GameHead.h"
#include "ObjEnemy1.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjEnemy1::CObjEnemy1(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjEnemy1::Init()
{
	m_hp = 30;
	m_atk = 2;
	m_time = 0;
	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 150, 150, ELEMENT_ENEMY, OBJ_ENEMY1, 1);

}

//アクション
void CObjEnemy1::Action()
{
	m_time++;

	/*
	//通常弾発射
	if ( m_time % 50 == 0 )
	{
		//弾丸敵機オブジェクト
		CObjBulletEnemy* obj_b=new CObjBulletEnemy(m_x+68, m_y+114);
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	}
	*/

	//m_timeの初期化
	if ( m_time > 1000 )
	{
		m_time = 0;
	}
	
	//角度加算
	m_r += 2.0f;

	//360°で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;

	//移動方向
	m_vx = 0.0f;
	m_vy = sin(3.14/180*m_r);//sinθを求めてm_vyに入れる

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度付ける。
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;


	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//ボス機が完全に領域外に出たらボス機を破棄する
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//ボス機が所有するHitBoxを削除する。

		return;
	}

	//弾丸と接触したらHPを減らす
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HPが0になったら破棄
	if(m_hp<=0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//クリア後、次のステージに移行させる
		//Scene::SetScene(new CSceneClear());
	}
}

//ドロー
void CObjEnemy1::Draw()
{
	// 描画カラー情報  R = RED  G = Green  B = Blue A = alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 150.0f;
	src.m_bottom = 150.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 150.0f + m_x;
	dst.m_bottom = 150.0f + m_y;

	//2番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(2, &src, &dst, c, 0.0f);

}