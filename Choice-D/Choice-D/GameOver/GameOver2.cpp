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
CSceneGameOver2::CSceneGameOver2()
{

}

//デストラクタ
CSceneGameOver2::~CSceneGameOver2()
{

}

//ゲームメイン初期化メソッド
void CSceneGameOver2::InitScene()
{
	//外部グラフィック画像を読み込み15番に登録
	Draw::LoadImage(L"teki3.png", 15, TEX_SIZE_512);

	CObjGameOvergamen* ga6 = new CObjGameOvergamen();
	Objs::InsertObj(ga6, OBJ_GAMEOVERGAMEN, 24);

	//外部グラフィック画像を読み込み14番に登録
	Draw::LoadImage(L"teki3.png", 14, TEX_SIZE_512);

	CObjGameOvergamen* ga5 = new CObjGameOvergamen();
	Objs::InsertObj(ga5, OBJ_GAMEOVERGAMEN, 23);

	//外部グラフィック画像を読み込み13番に登録
	Draw::LoadImage(L"teki3.png", 13, TEX_SIZE_512);

	CObjGameOvergamen* ga4 = new CObjGameOvergamen();
	Objs::InsertObj(ga4, OBJ_GAMEOVERGAMEN, 22);

	//外部グラフィック画像を読み込み12番に登録
	Draw::LoadImage(L"teki3.png", 12, TEX_SIZE_512);

	CObjGameOvergamen* ga3 = new CObjGameOvergamen();
	Objs::InsertObj(ga3, OBJ_GAMEOVERGAMEN, 21);

	//外部グラフィック画像を読み込み9番に登録
	Draw::LoadImage(L"yarareta.png", 9, TEX_SIZE_512);

	CObjGameOvergamen* ga2 = new CObjGameOvergamen();
	Objs::InsertObj(ga2, OBJ_GAMEOVERGAMEN, 20);

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GAME OVER");

	//ゲームオーバーオブジェクト作成
	CObjGAMEOVER2* obj = new CObjGAMEOVER2();		//ゲームオーバーオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAMEOVER2, 10);		//主人公オブジェクト登録
}

//ゲームメイン実行中メソッド
void CSceneGameOver2::Scene()
{

}