#pragma once
//使用するヘッダー
#include"../GameL\DrawTexture.h"
#include"../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵機弾丸2
class CObjBulletTeki2 : public CObj
{
public:
	CObjBulletTeki2(float x, float y);
	~CObjBulletTeki2() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー
private:
	float m_x;	//オブジェクトの位置Ｘ
	float m_y;	//オブジェクトの位置Ｙ
	float m_vx;	//オブジェクトの移動用ベクトルＸ
	float m_vy;	//オブジェクトの移動用ベクトルＹ

	int	   m_ani;	//着弾アニメーション用
	int	   m_ani_time;//着弾アニメーション間隔タイム
	bool   m_del;	//削除チェック
	RECT_F m_eff;	//着弾エフェクト描画用	
};