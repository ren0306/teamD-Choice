#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneSTG4 :public CScene
{
public:
	CSceneSTG4();
	~CSceneSTG4();
	void InitScene();//ゲームタイトルの初期化メソッド
	void Scene();	 //ゲームタイトルの実行中メソッド
private:

};
#pragma once
