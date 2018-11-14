#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：シューティング背景
class STGBackground : public CObj
{
	public:
		STGBackground() {};
		~STGBackground() {};
		void Init();	//イニシャライズ
		void Action();  //アクション
		void Draw();	//ドロー
	private:

};