#pragma once
//使用するヘッダー
#include"../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define QUESTION 5
#define ANSER 4

//オブジェクト：テンキー
class CObjTenkey2 :public CObj
{
public:
	CObjTenkey2() {};
	~CObjTenkey2() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
	bool Anser();
	int m_f = 0;
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;
	int cnt = 0;
	float m_ps;
	bool m_flag[10];
	bool m_ok;
	int m_num[10];
	int m_anser;
};