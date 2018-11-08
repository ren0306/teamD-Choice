#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームオーバー
class CSceneGameOver2:public CScene
{
public:
	CSceneGameOver2();
	~CSceneGameOver2();
	void InitScene();	//ゲームオーバーの初期化メソッド
	void Scene();		//ゲームオーバーの実行中メソッド
private:
};