﻿#pragma once
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
	void SetX(float x) { m_x = x; }//位置情報X変更用
	void SetY(float y) { m_y = y; }//位置情報Y変更用
	float GetX() { return m_x; }	   //位置情報X取得用
	float GetY() { return m_y; }	   //位置情報Y取得用

private:
	float m_x;	//敵1のx方向の位置
	float m_y;	//敵1のy方向の位置
	float m_vx;	//敵1移動ベクトルx
	float m_vy;	//敵¹移動ベクトルy
	float m_r;	//sinカーブ用変数
	int   m_time;//弾丸間隔用

	bool m_f;
	float m_hp;	//ボスのヒットポイント
	float m_maxhp;
	int m_dtime;
	bool death;//敵機の生存管理フラグ
};