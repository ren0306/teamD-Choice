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
	int m_f = 0;
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;	
	int cnt ;
	float m_ps ;
	bool m_flag[10];
	bool m_ok;
	int m_num[10];
	int m_anser;
	bool m_fnot;
	bool m_miss;
	float m_misscnt;
};