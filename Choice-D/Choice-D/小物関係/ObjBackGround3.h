#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲーム背景3
class CObjBackGround3 :public CObj
{
public:
	CObjBackGround3() {};
	~CObjBackGround3() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;

};
