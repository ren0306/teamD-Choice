#pragma once
//使用するヘッダー
#include"../GameL\SceneObjManager.h"
#include"../GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero : public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー
	void SetX(float x);//位置情報X変更用
	void SetY(float y);//位置情報Y変更用
	float GetX();	   //位置情報X取得用
	float GetY();	   //位置情報Y取得用
private:
	float m_x;		//主人公機のｘ方向移動用変数
	float m_y;		//主人公機のｙ方向移動用変数
	bool  m_f;      //弾丸発射制御用
	float m_vx;		//主人公機のｘ方向移動ベクトル用変数
	float m_vy;		//主人公機のｙ方向移動ベクトル用変数
	float   m_hp;	//自機のヒットポイント
	float m_maxhp;
	float m_time;
	float m_cnt;
	float m_maxcnt;
	float m_tame;
	float m_maxtame;
	float m_and;
	int m_ani;
	float m_ani_time;
	float m_del;
	bool m_andf;
	bool death;		//主人公機の生存管理
	float size1;	//主人公→爆破時、大きさ変更用変数1
	float size2;	//主人公→爆破時、大きさ変更用変数2
	RECT_F m_eff;	//自機爆発エフェクト描画用	
};