//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"

#include "../GameHead.h"
#include "CObjMeanderBullet.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjMeanderBullet::CObjMeanderBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjMeanderBullet::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	m_vx = 0.0f;
	m_vy = 0.0f;
	m_r = 0.0f;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_MEANDER_BULLET, 1);
}

//アクション
void CObjMeanderBullet::Action()
{
	//Resourcesの描画物のRECT
	m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 2);

	//弾丸消滅処理　-----
	if (m_del == true)
	{
		//着弾アニメーション終了で本当にオブジェクトの破棄
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		return;//消滅処理は、ここでアクションメソッドを終了させる
	}

	//弾丸実行処理　-----
	//角度加算
	m_r += 2.0f;

	//360°で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;

	//移動方向
	m_vx = sin(3.14f / 90 * m_r);
	m_vy = 1.0f;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度付ける。
	m_vx *= 10.0f;
	m_vy *= 5.0f;

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;

	//蛇行弾丸のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);			 //HitBoxの位置を蛇行弾丸の位置に更新

	//蛇行弾丸が完全に領域外に出たら蛇行弾丸を破棄する
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//敵機弾丸が所有するHitBoxを削除する。

		return;
	}

	//主人公機オブジェクトと接触したら蛇行弾丸削除
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		m_del = true;				//消滅実行
		hit->SetInvincibility(true);//当たり判定無効
	}
}

//ドロー
void CObjMeanderBullet::Draw()
{
	//描画カラー情報  R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //描画先表示位置

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//30番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(30, &m_eff, &dst, c, 0.0f);
}