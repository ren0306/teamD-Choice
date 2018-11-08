//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL\Audio.h"
#include "../GameHead.h"
#include "ObjHero.h"
#include "ObjEnemy2.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjEnemy2::CObjEnemy2()
{
	m_atk;
}

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
	m_hp = 20;
	m_x = 400;
	m_y = 550;
	m_f = true;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//主人公機の弾丸発射
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			//発射音を鳴らす
			//Audio::Start(2);

			// 弾丸オブジェクト作成
			CObjBullet*  obj_b = new CObjBullet(m_x , m_y + -30.0f); //弾丸オブジェクト作成
			Objs::InsertObj(obj_b, OBJ_BULLET, 100); //作った弾丸オブジェクトをオブジェクトマネージャーに登録

			m_f = false;
		}
	}
	else
	{
		m_f = true;
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
//		m_hp -= m_atk;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//主人公機が所有するHitBoxに削除する。

		//主人公機消滅でシーンをゲームオーバーに移行する
		/*↓ゲームオーバーのシーンはまだ作ってないためコメントアウト中*/
		//Scene::SetScene(new CSceneGameOver());
	}
}

//ドロー
void CObjHero::Draw()
{
	//描画カラー情報  R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  ob[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

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
	Draw::Draw(1, &src, &dst, ob, 0.0f);

}