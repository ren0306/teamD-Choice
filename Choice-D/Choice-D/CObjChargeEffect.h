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
	CObjChargeEffect() {};
	~CObjChargeEffect() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー
	void Set(int a);//アニメーションコマ変更用
private:
	int	   m_ani;	//着弾アニメーション用
	int	   m_ani_time;//着弾アニメーション間隔タイム
	RECT_F m_eff;	//着弾エフェクト描画用
};