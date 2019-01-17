#pragma once
//使用するヘッダー
#include"../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjTitle :public CObj
{
public :
	CObjTitle() {};
	~CObjTitle() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;
	float m_and=1;
	bool m_end;
	bool m_f;
	bool m_sousa;
	bool m_andf;
	bool m_flag;
	bool m_flag2;
	bool m_flag3;
	bool m_key_flag;//キーフラグ
};