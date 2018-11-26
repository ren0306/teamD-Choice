#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームシューティング4
class CSceneSTG4 :public CScene
{
public:
	CSceneSTG4();
	~CSceneSTG4();
	void InitScene();//ゲームシューティング4の初期化メソッド
	void Scene();	 //ゲームシューティング4の実行中メソッド
private:

};

