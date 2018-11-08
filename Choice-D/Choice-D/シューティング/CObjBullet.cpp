//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL\Audio.h"
#include "../GameHead.h"
#include "CObjBullet.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjBullet::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
	m_vy = 0.0f;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//アクション
void CObjBullet::Action()
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
	m_vy += -1.0f;
	m_y += m_vy;

	//弾丸のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);			 //HitBoxの位置を弾丸の位置に更新

	//領域外に出たら弾丸を破棄する
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);	//弾丸が所有するHitBoxを削除する。

		return;
	}

	//当たり判定を行うオブジェクト情報郡
	int data_base[1] =
	{
		OBJ_ENEMY1,
	};

	//オブジェクト情報郡と当たり判定を行い、当たっていれば削除
	for (int i = 0; i < 6; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			//Audio::Start(3);//着弾音を鳴らす

			m_del = true;				//消滅実行
			hit->SetInvincibility(true);//当たり判定無効
		}
	}
}

//ドロー
void CObjBullet::Draw()
{
	//描画カラー情報  R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //描画先表示位置

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(0, &m_eff, &dst, c, 0.0f);
}