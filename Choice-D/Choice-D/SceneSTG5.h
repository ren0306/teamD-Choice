#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームシューティング5
class CSceneSTG5 :public CScene
{
public:
	CSceneSTG5();
	~CSceneSTG5();
	void InitScene();//ゲームシューティング5の初期化メソッド
	void Scene();	 //ゲームシューティング5の実行中メソッド
private:

};