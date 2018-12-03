#pragma once
//使用するヘッダー
#include "../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;



//オブジェクト：敵１
class CObjTimeLimit :public CObj
{
public:
	CObjTimeLimit() {};//コンストラクタ位置情報をもらう
	~CObjTimeLimit() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	int GETtime() { return m_time; }
private:
	int m_time;

};
