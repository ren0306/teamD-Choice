#pragma once
//使用するヘッダー
#include "../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjGAMEOVER :public CObj
{
	public :
		CObjGAMEOVER() {};
		~CObjGAMEOVER() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		float m_mou_x;
		float m_mou_y;
		bool m_mou_r;
		bool m_mou_l;
};