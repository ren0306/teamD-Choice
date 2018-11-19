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
#include "../ゲームメイン/SceneMain3.h"
#include "../GameHead.h"

//コンストラクタ
CSceneMain3::CSceneMain3()
{
}




//テストラクタ
CSceneMain3::~CSceneMain3()
{
}



//ゲームメイン初期化メソッド
void CSceneMain3::InitScene()
{
	//外部グラフィックファイルを読み込み０番に登録
	Draw::LoadImage(L"Main3.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 2, TEX_SIZE_512);

	CObjBackGround3* b = new CObjBackGround3();
	Objs::InsertObj(b, OBJ_BACKGROUND3, 0);

	CObjDoor2* Door2 = new CObjDoor2();
	Objs::InsertObj(Door2, OBJ_DOOR2, 130);



}



//ゲームメイン実行中メソッド
void CSceneMain3::Scene()
{
}
