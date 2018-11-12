//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain.h"
#include "Objteki2.h"
#include "SceneSTG2.h"
#include "../GameHead.h"
#include "ObjHero.h"

//コンストラクタ
CSceneSTG2::CSceneSTG2()
{
}

//デストラクタ
CSceneSTG2::~CSceneSTG2()
{
}

//ゲームタイトル初期化メソッド
void CSceneSTG2::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録
	Draw::LoadImage(L"ss01.png", 0, TEX_SIZE_512);
	//外部グラフィックファイルを読み込み10番に登録
	Draw::LoadImage(L"teki2.png", 10, TEX_SIZE_512);
	//外部グラフィックファイルを読み込み6番に登録
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//STGオブジェクト作成
	CObjSTG2* obj = new CObjSTG2();
	Objs::InsertObj(obj, OBJ_STG2, 10);

	CObjBackGround2* p = new CObjBackGround2();
	Objs::InsertObj(p, OBJ_BACKGROUND2, 0);


	CObjteki2* objb = new CObjteki2(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI2, 50);


	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);
}

//ゲームタイトル実行中メソッド
void CSceneSTG2::Scene()
{
}