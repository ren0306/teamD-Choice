#pragma once
//使用するヘッダー
#include"../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：OP
class CObjOP :public CObj
{
public:
	CObjOP() {};
	~CObjOP() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;
	bool m_mz;
	bool m_st;
	bool m_op;
	float m_and;
	bool m_f;
	bool m_andf;

};