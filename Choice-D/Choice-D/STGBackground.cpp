//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "STGBackground.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void STGBackground::Init()
{
	m_andf = true;
	m_and = 0.f;
}

//アクション
void STGBackground::Action()
{
	if (m_andf == true)
	{
		m_and += 0.1f;
		if (m_and >= 1)
		{
			m_and = 1.0;
			m_andf = false;
		}

	}

}

//ドロー
void STGBackground::Draw()
{
	// 描画カラー情報  R = RED  G = Green  B = Blue A = alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,m_and };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 769.0f;
	src.m_bottom = 621.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}