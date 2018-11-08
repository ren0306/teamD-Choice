//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"


//使用するネームスペース
using namespace GameL;
//使用ヘッダー
#include "../main.h"
#include "../GameHead.h"


//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//ゲームメイン初期化メソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GAME OVER");

	//ゲームオーバーオブジェクト作成
	CObjGAMEOVER* obj = new CObjGAMEOVER();		//ゲームオーバーオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);		//主人公オブジェクト登録
}

//ゲームメイン実行中メソッド
void CSceneGameOver::Scene()
{

}