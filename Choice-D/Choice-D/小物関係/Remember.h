#pragma once
#include "../GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;


class Remember :public CObj
{
public:
	Remember() {};//コンストラクタ位置情報をもらう
	~Remember() {};
	void Init();	//イニシャライズ
	void Action() ;	//アクション
	void Draw() {};	//ドロー
	void SETF(float x) { m_f4 = x; }
	bool GETF() { return m_f4; }

private:
	bool m_f1;
	bool m_f2;
	bool m_f3;
	bool m_f4;
	bool m_f5;

};