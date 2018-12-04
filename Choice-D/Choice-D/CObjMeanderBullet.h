#pragma once
//使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵機弾丸1
class CObjMeanderBullet : public CObj
{
public:
	CObjMeanderBullet(float x, float y);
	~CObjMeanderBullet() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー
private:
	float m_x;	//オブジェクトの位置Ｘ
	float m_y;	//オブジェクトの位置Ｙ
	float m_vx;	//オブジェクトの移動用ベクトルＸ
	float m_vy;	//オブジェクトの移動用ベクトルＹ
	float m_r;	//サインカーブ用の角度

	int	   m_ani;	//着弾アニメーション用
	int	   m_ani_time;//着弾アニメーション間隔タイム
	bool   m_del;	//削除チェック
	RECT_F m_eff;	//着弾エフェクト描画用	
};