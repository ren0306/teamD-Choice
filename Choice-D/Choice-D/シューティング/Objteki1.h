#pragma once
//使用するヘッダー
#include "../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;



//オブジェクト：敵１
class CObjteki1 :public CObj
{
	public:
		CObjteki1(float x, float y);//コンストラクタ位置情報をもらう
		~CObjteki1() {};
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
		float m_vy;	//敵1移動ベクトルy
		float m_r;  //sinカーブ用変数
		float m_r2;//sinカーブ用変数2
		int   m_time;//弾丸間隔用
		int m_enemytime;
		float m_hp ;
		float m_maxhp;
		bool m_f;
		bool Herodeath;
};
