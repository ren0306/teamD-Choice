#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームシューティング3
class CSceneSTG3 :public CScene
{
public:
	CSceneSTG3();
	~CSceneSTG3();
	void InitScene();//ゲームシューティング3の初期化メソッド
	void Scene();	 //ゲームシューティング3の実行中メソッド
private:

};
