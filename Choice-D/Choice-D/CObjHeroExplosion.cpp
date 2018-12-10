/*

//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjHeroExplosion.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjHeroExplosion::CObjHeroExplosion(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjHeroExplosion::Init()
{
	m_eff.m_top = 0;
	m_eff.m_left = 96;
	m_eff.m_right = 128;
	m_eff.m_bottom = 32;
	m_ani = 0;
	m_ani_time = 0;
}

//アクション
void CObjHeroExplosion::Action()
{
	RECT_F ani_src[5] =
	{
		{ 0,  96, 128,  32 },
		{ 64,  32,  64,  96 },
		{ 96, 224, 256,  128 },
		{ 160, 160, 192, 192 },
		{ 224,  96, 128, 256 },
	};

	//アニメーションのコマ間隔制御
	if (m_ani_time > 4)
	{
		m_ani++;	//アニメーションのコマを１つ進める
		m_ani_time = 0;

		m_eff = ani_src[m_ani];//アニメーションのRECT配列からm_ani番目のRECT情報取得
	}
	else
	{
		m_ani_time++;
	}

	//着弾アニメーション終了で本当にオブジェクトの破棄
	if (m_ani == 5)
	{
		this->SetStatus(false);
	}


	return;//消滅処理は、ここでアクションメソッドを終了させる
}

//ドロー
void CObjHeroExplosion::Draw()
{
	//主人公機の位置を取る
	//CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float x = obj->GetX();
	//float y = obj->GetY();
	
	//描画カラー情報  R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //描画先表示位置

	//表示位置の設定
	dst.m_top = -20.0f + m_y;
	dst.m_left = -20.0f + m_x;
	dst.m_right = 52.0f + m_x;
	dst.m_bottom = 52.0f + m_y;

	//8番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(8, &m_eff, &dst, c, 0.0f);
}

*/