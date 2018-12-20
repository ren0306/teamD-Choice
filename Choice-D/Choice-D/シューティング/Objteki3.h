#pragma once
//使用するヘッダー
#include "../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵3
class CObjteki3 :public CObj
{
public:
	CObjteki3(float x, float y);//コンストラクタ位置情報をもらう
	~CObjteki3() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	void SetX(float x) { m_x = x; }//位置情報X変更用
	void SetY(float y) { m_y = y; }//位置情報Y変更用
	float GetX() { return m_x; }	   //位置情報X取得用
	float GetY() { return m_y; }	   //位置情報Y取得用


private:
	float m_x;	//敵3のx方向の位置
	float m_y;	//敵3のy方向の位置
	float m_vx;	//敵3移動ベクトルx
	float m_vy;	//敵3移動ベクトルy
	float m_r;	//sinカーブ用変数
	int   m_time;//弾丸間隔用
	int   m_hit;
	int m_cnt;

	bool m_f3;
	float m_hp;	//ボスのヒットポイント
	float m_maxhp;
	int m_dtime;
};