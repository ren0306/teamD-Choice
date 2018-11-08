#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームオーバー
class CSceneGameOver:public CScene
{
	public:
		CSceneGameOver();
		~CSceneGameOver();
		void InitScene();	//ゲームオーバーの初期化メソッド
		void Scene();		//ゲームオーバーの実行中メソッド
	private:
		float m_mou_x;
		float m_mou_y;
		bool m_mou_r;
		bool m_mou_l;
};