#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneMain3 :public CScene
{
public:
	CSceneMain3();
	~CSceneMain3();
	void InitScene();//ゲームメインの初期化メソッド
	void Scene();	 //ゲームメインの実行中メソッド
private:

};