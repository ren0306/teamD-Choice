//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawTexture.h"
#include "../GameL\DrawFont.h"
#include "../GameL\UserData.h"
#include "../GameL/Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain5.h"
#include "../GameHead.h"

//コンストラクタ
CSceneMain5::CSceneMain5()
{
}




//テストラクタ
CSceneMain5::~CSceneMain5()
{
}



//ゲームメイン初期化メソッド
void CSceneMain5::InitScene()
{
	//外部グラフィックファイルを読み込み０番に登録
	Draw::LoadImage(L"ss01.png", 0, TEX_SIZE_1024);
	Draw::LoadImage(L"door2.png", 2, TEX_SIZE_512);
	//敵２を読み込み2番に登録
	Draw::LoadImage(L"teki2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"sentaku.png", 3, TEX_SIZE_512);

	CObjMain2* m = new CObjMain2();
	Objs::InsertObj(m, OBJ_MAIN2, 140);

	CObjBackGround2* b = new CObjBackGround2();
	Objs::InsertObj(b, OBJ_BACKGROUND2, 120);

	CObjDoor2* Door2 = new CObjDoor2();
	Objs::InsertObj(Door2, OBJ_DOOR2, 130);



}



//ゲームメイン実行中メソッド
void CSceneMain5::Scene()
{
}
