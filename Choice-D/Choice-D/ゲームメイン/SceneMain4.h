#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneMain4 :public CScene
{
public:
	CSceneMain4();
	~CSceneMain4();
	void InitScene();//ゲームメインの初期化メソッド
	void Scene();	 //ゲームメインの実行中メソッド
private:

};