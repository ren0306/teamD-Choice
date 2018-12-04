//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL\Audio.h"
#include "../GameHead.h"
#include "../GameL/DrawFont.h"
#include "ObjHero.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//位置情報X変更用
void CObjHero::SetX(float x)
{
	m_x = x;
}

//位置情報Y変更用
void CObjHero::SetY(float y)
{
	m_y = y;
}

//位置情報X取得用
float CObjHero::GetX()
{
	return m_x;
}

//位置情報Y取得用
float CObjHero::GetY()
{
	return m_y;
}

//イニシャライズ
void CObjHero::Init()
{
	m_hp = 20.f;
	m_maxhp = 20.f;
	m_x = 400;
	m_y = 550;
	m_f = true;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 50.f;
	m_cnt = 7.f;
	m_maxcnt = 7.f;
	m_tame = 0.f;
	m_maxtame = 100.f;
	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//主人公機の弾丸発射
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			m_cnt--;

			//発射音を鳴らす
			//Audio::Start(2);
			if (m_cnt <= 0)
			{
				m_f = false;
			}
			else
			{
				// 弾丸オブジェクト作成
				CObjBullet*  i = new CObjBullet(m_x, m_y + -30.0f); //弾丸オブジェクト作成
				Objs::InsertObj(i, OBJ_BULLET, 100); //作った弾丸オブジェクトをオブジェクトマネージャーに登録

				m_f = false;
			}
		}
	}
	else
	{
		m_f = true;
	}
	//Rを押してリロード
	if (Input::GetVKey('R') == true)
	{
		m_cnt = 7.f;
	}
	//Aを長押しでチャージ
	if (Input::GetVKey('A') == true)
	{
		m_tame++;
		if (m_tame >= 100)
		{
			if (m_cnt <= 0)
			{
				m_tame = 0;
			}
			else
			{
				// 弾丸オブジェクト作成
				CObjBullet*  i = new CObjBullet(m_x, m_y + -30.0f); //弾丸オブジェクト作成
				Objs::InsertObj(i, OBJ_BULLET, 100); //作った弾丸オブジェクトをオブジェクトマネージャーに登録

				m_tame = 0;
			}
		}
	}
	//主人公機の移動ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//主人公機の移動
	//キーの入力方向にベクトルの速度を入れる
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 5.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 5.0f;
	}

	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= 5.0f;
	}

	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 5.0f;
	}

	//ベクトルの長さを求める(三平方の定理)
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);//ｒのルートを求める

	//長さが0かどうか調べる
	if (r == 0.0f)
	{
		;//0なら何もしない
	}
	else
	{
		//正規化を行う。
		m_vx = 5.0f / r * m_vx;
		m_vy = 5.0f / r * m_vy;
	}

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;

	//主人公機が領域外行かない処理
	if (m_x + 32.0f > 800.0f)
	{
		m_x = 800.0f - 32.0f;
	}
	if (m_y + 32.0f > 600.0f)
	{
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_x, m_y);					//入り口から新しい位置(主人公機の位置）情報に置き換える

	//ELEMENT_ENEMYを持つオブジェクトと接触したらHPを減らす
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI1) != nullptr)
		{
			m_hp -= 1;
		}

		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI2) != nullptr)
		{
			m_hp -= 1;
		}
		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI3) != nullptr)
		{
			m_hp -= 2;
		}

		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI4) != nullptr)
		{
			m_hp -= 3;
		}
		if (hit->CheckObjNameHit(OBJ_BULLET_TEKI5) != nullptr)
		{
			m_hp -= 3;
		}

		if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET) != nullptr)
		{
			m_hp -= 1;
		}

		if (hit->CheckObjNameHit(OBJ_HOMING_BULLET) != nullptr)
		{
			m_hp -= 1;
		}

		m_hp -= 1;
	}
	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		m_time--;
		if (m_time <= 0)
		{
			this->SetStatus(false);		//自身に削除命令を出す。
			Hits::DeleteHitBox(this);	//主人公機が所有するHitBoxに削除する。


			Scene::SetScene(new CSceneGameOver2());
		}
	}
}

//ドロー
void CObjHero::Draw()
{
	//アニメーションRECT情報
	RECT_F ani_src[4] =
	{
		{ 32,  0,  32,  64},
		{ 32, 32,  64,  64},
		{ 32, 64,  96,  64},
		{ 32, 96, 128,  64},
	};
	
	//描画カラー情報  R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  ob[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	float h[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,0.0f,0
		.0f,1.0f };

	Font::StrDraw(L"自分のHP", 0, 126, 28, h);
	Font::StrDraw(L"残弾数", 0, 175, 25, h);
	if (m_cnt <= 0)
	{
		Font::StrDraw(L"残弾０です。リロードしてください", 0, 200, 25, a);
	}
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1280.0f;
	src.m_bottom = 720.0f;

	//表示位置の設定
	dst.m_top = 150.0f;
	dst.m_left = 0.0f;
	dst.m_right = (m_hp / m_maxhp)*128.0f;
	dst.m_bottom = 175.0f;

	
	//5番目に登録したグラフィックをsrc・dst・cの元の情報に描画
	Draw::Draw(5, &src, &dst, h, 0.0f);

	//残弾数表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1280.0f;
	src.m_bottom = 720.0f;

	//表示位置の設定
	dst.m_top = 200.0f;
	dst.m_left = 0.0f;
	dst.m_right = (m_cnt / m_maxcnt)*128.0f;
	dst.m_bottom = 225.0f;

	//5番目に登録したグラフィックをsrc・dst・cの元の情報に描画
	Draw::Draw(5, &src, &dst, h, 0.0f);

	//チャージ表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1280.0f;
	src.m_bottom = 720.0f;

	//表示位置の設定
	dst.m_top = 250.0f;
	dst.m_left = 0.0f;
	dst.m_right = (m_tame / m_maxtame)*128.0f;
	dst.m_bottom = 275.0f;
	//5番目に登録したグラフィックをsrc・dst・cの元の情報に描画
	Draw::Draw(5, &src, &dst, h, 0.0f);

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//1番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(6, &src, &dst, ob, 0.0f);

}

void Bullet(int c,float x,float y)
{

}