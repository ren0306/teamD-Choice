#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CObjMain4 :public CObj
{
public:
	CObjMain4() {};
	~CObjMain4() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;
	float m_and;
	bool m_f;
	bool m_key_flag;//キーフラグ
};