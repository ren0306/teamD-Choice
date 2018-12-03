#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームシューティング2
class CSceneSTG2 :public CScene
{
public:
	CSceneSTG2();
	~CSceneSTG2();
	void InitScene();//ゲームシューティング2の初期化メソッド
	void Scene();	 //ゲームシューティング2の実行中メソッド
private:

};