#pragma once
//使用するヘッダー
#include"../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵3
class CObjEnemy4 : public CObj
{
public:
	CObjEnemy4(float x, float y);//コンストラクタ位置情報をもらう
	~CObjEnemy4() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー
private:
	float m_x;	//ボス機のｘ方向の位置
	float m_y;	//ボス機のｙ方向の位置
	float m_vx; //ボス機移動ベクトルX
	float m_vy; //ボス機移動ベクトルY
	float m_r;	//サインカーブ用の角度
	int   m_time;//弾丸間隔用
	int   m_hp; //ボスのヒットポイント
	int   m_atk; //ボスの攻撃力
};