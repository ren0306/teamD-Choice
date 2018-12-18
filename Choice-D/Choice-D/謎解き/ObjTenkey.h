#pragma once
//使用するヘッダー
#include"../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define QUESTION 5
#define ANSER 4

//オブジェクト：テンキー
class CObjTenkey :public CObj
{
public:
	CObjTenkey() {};
	~CObjTenkey() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
	bool Anser();
	void Tenkey();

private:
	//マウス関係--------------------------
	float m_mou_x;//マウスの位置X
	float m_mou_y;//マウスの位置Y
	bool m_mou_r;//マウスプッシュ確認
	bool m_mou_l;
	//------------------------------------
	//bool(フラグ)関係
	bool m_flag[10];//テンキー入力確認配列
	bool m_ok;//解答確認変数
	bool m_f;
	bool m_andf;
	bool m_delete;
	bool m_wannig;
	//------------------------------------
	int cnt ;//桁数チェックカウント	
	int m_num[10];//解答配列
	int m_anser;//答え確認変数
	float m_and;
	int m_time;

};