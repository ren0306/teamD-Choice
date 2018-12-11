/*

#pragma once
//使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：自機爆発
class CObjHeroExplosion : public CObj
{
public:
	CObjHeroExplosion(float x, float y);
	~CObjHeroExplosion() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー
private:
	float m_x;	//取得した主人公の位置Ｘ
	float m_y;	//取得した主人公の位置Ｙ

	int	   m_ani;	//着弾アニメーション用
	int	   m_ani_time;//着弾アニメーション間隔タイム
	RECT_F m_eff;	//着弾エフェクト描画用
};

*/