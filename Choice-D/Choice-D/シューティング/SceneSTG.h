#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームシューティング
class CSceneSTG :public CScene
{
public:
	CSceneSTG();
	~CSceneSTG();
	void InitScene();//ゲームシューティングの初期化メソッド
	void Scene();	 //ゲームシューティングの実行中メソッド
private:

};