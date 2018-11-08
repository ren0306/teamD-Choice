#pragma once
//使用するヘッダー
#include "../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵3
class CObjteki4 :public CObj
{
public:
	CObjteki4(float x, float y);//コンストラクタ位置情報をもらう
	~CObjteki4() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;	//敵3のx方向の位置
	float m_y;	//敵3のy方向の位置
	float m_vx;	//敵3移動ベクトルx
	float m_vy;	//敵3移動ベクトルy
	float m_r = 0.0f;

};