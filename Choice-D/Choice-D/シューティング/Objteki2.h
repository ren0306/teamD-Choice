#pragma once
//使用するヘッダー
#include "../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵2
class CObjteki2 :public CObj
{
public:
	CObjteki2(float x, float y);//コンストラクタ位置情報をもらう
	~CObjteki2() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	bool GETF() { return m_f2; }

private:
	float m_x;	//敵1のx方向の位置
	float m_y;	//敵1のy方向の位置
	float m_vx;	//敵1移動ベクトルx
	float m_vy;	//敵¹移動ベクトルy
	float m_r = 0.0f;
	int   m_time;//弾丸間隔用

	bool m_f2;
	float m_hp;	//ボスのヒットポイント
	float m_maxhp;
};