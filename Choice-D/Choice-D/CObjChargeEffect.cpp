//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "CObjChargeEffect.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjChargeEffect::CObjChargeEffect(float x, float y)
{
	m_x = x;
	m_y = y;
}

//アニメーションコマ変更用
void CObjChargeEffect::Set(int a)
{
	m_ani = a;
}

//イニシャライズ
void CObjChargeEffect::Init()
{
	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 32;
	m_ani = 0;
	m_ani_time = 0;//ObjHero内で変更したい。
}

//アクション
void CObjChargeEffect::Action()
{
	//主人公機の位置を取得
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_x = obj->GetX();
	m_y = obj->GetY();

	RECT_F ani_src[4] =
	{
		{ 0,   0,  32,  32 },
		{ 0,  32,  64,  32 },
		{ 0,  64,  96,  32 },
		{ 0,  96, 128,  32 },
	};

	//アニメーションのコマ間隔制御
	if (m_ani_time > 2)
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
	if (m_ani == 3)
	{
		m_ani = 0;
	}


	return;//消滅処理は、ここでアクションメソッドを終了させる
}

//ドロー
void CObjChargeEffect::Draw()
{
	//描画カラー情報  R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //描画先表示位置

	//表示位置の設定
	dst.m_top = -20.0f + m_y;
	dst.m_left = -24.0f + m_x;
	dst.m_right = 48.0f + m_x;
	dst.m_bottom = 52.0f + m_y;

	//8番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(8, &m_eff, &dst, c, 0.0f);
}