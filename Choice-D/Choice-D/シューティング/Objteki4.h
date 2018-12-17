#pragma once
//使用するヘッダー
#include "../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵4
class CObjteki4 :public CObj
{
public:
	CObjteki4(float x, float y);//コンストラクタ位置情報をもらう
	~CObjteki4() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	//bool GETF() { return m_f4; }
	bool m_f4;

private:
	float m_x;	//敵3のx方向の位置
	float m_y;	//敵3のy方向の位置
	float m_vx;	//敵3移動ベクトルx
	float m_vy;	//敵3移動ベクトルy
	float m_r;	//sinカーブ用変数
	int   m_time;//弾丸間隔用

	float m_hp;	//ボスのヒットポイント
	float m_maxhp;
	int m_dtime;
};