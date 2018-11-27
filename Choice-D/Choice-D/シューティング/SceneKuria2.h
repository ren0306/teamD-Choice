#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：バトルクリア2
class CSceneKuria2 :public CScene
{
public:
	CSceneKuria2();
	~CSceneKuria2();
	void InitScene();//ゲームタイトルの初期化メソッド
	void Scene();	 //ゲームタイトルの実行中メソッド
private:

};