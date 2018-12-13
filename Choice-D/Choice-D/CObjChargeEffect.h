#pragma once
//使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：チャージエフェクト
class CObjChargeEffect : public CObj
{
public:
	CObjChargeEffect(float x, float y);
	~CObjChargeEffect() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー
	void Set(int a);//アニメーションコマ変更用
private:
	float m_x;	//オブジェクトの位置Ｘ
	float m_y;	//オブジェクトの位置Ｙ

	int	   m_ani;	//着弾アニメーション用
	int	   m_ani_time;//着弾アニメーション間隔タイム
	RECT_F m_eff;	//着弾エフェクト描画用
};