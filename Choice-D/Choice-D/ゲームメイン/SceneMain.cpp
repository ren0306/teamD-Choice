//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawTexture.h"
#include "../GameL\DrawFont.h"
#include "../GameL\UserData.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "../GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{
}




//テストラクタ
CSceneMain::~CSceneMain()
{
}



//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイルを読み込み０番に登録
	Draw::LoadImageW(L"doukutu.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"door.png", 1, TEX_SIZE_512);

	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_MAIN, 12);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 120);

	



}



//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{
}
