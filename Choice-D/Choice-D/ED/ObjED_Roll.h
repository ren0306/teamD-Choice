#pragma once
//使用するヘッダー
#include"../GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：エンディング1
class CObjED_Roll :public CObj
{
public:
	CObjED_Roll() {};
	~CObjED_Roll() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_y;
};