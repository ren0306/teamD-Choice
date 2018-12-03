#pragma once
//使用するヘッダー
#include"../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define QUESTION 5
#define ANSER 4

//オブジェクト：テンキー
class CObjTenkey4 :public CObj
{
public:
	CObjTenkey4() {};
	~CObjTenkey4() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
	bool Anser();
	void Tenkey();

private:
	float m_mou_x;//マウスの位置X
	float m_mou_y;//マウスの位置Y
	bool m_mou_r;//マウスの右ON、OFF
	bool m_mou_l;//マウスの左ON、OFF
	int cnt = 0;
	float m_ps;
	bool m_flag[10];
	bool m_ok;
	int m_num[10];
	int m_anser;
	bool m_f;
};