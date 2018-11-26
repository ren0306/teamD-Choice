//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneManager.h"
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

//ゲームオーバー初期化メソッド
void CSceneGameOver::InitScene()
{
	//ゲームオーバー1画像を読み込み0番に登録
	Draw::LoadImage(L"GameOver kuuhuku.png", 3, TEX_SIZE_512);

	CObjGameOvergamen* ga = new CObjGameOvergamen();
	Objs::InsertObj(ga, OBJ_GAMEOVERGAMEN, 20);

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GAME OVER");

	//ゲームオーバーオブジェクト1作成
	CObjGAMEOVER* obj = new CObjGAMEOVER();		//ゲームオーバーオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);		//主人公オブジェクト登録
}

//ゲームオーバー1実行中メソッド
void CSceneGameOver::Scene()
{

}