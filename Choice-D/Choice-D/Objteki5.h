#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵5
class CObjteki5 :public CObj
{
public:
	CObjteki5(float x, float y);//コンストラクタ位置情報をもらう
	~CObjteki5() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	void SET(float x) { m_f = x; }
	bool GET() { return m_f; }

private:
	float m_x;	//敵5のx方向の位置
	float m_y;	//敵5のy方向の位置
	float m_vx;	//敵5移動ベクトルx
	float m_vy;	//敵5移動ベクトルy
	float m_r = 0.0f;
	int   m_time;//弾丸間隔用
	bool m_f5;
	float m_hp;	//ボスのヒットポイント
	float m_maxhp;
	bool m_f;
};