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
	void Set(bool f);//アニメーションフラグ変更用
private:
	float m_x;	//オブジェクトの位置Ｘ
	float m_y;	//オブジェクトの位置Ｙ

	int	   m_ani;	//チャージアニメーション用
	int	   m_ani_time;//チャージアニメーション間隔タイム
	RECT_F m_eff;	//チャージエフェクト描画用

	bool m_ani_flag;//trueでアニメーション動作、falseでアニメーション停止
};