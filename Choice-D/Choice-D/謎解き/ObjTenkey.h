#pragma once
//使用するヘッダー
#include"../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：テンキー
class CObjTenkey :public CObj
{
public:
	CObjTenkey() {};
	~CObjTenkey() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
	int m_f = 0;
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;	
	float cnt = 0.f;
	float m_ps ;
	bool m_flag[10];
	bool m_1;
	bool m_2;
	bool m_3;

};