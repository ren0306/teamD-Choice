//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "ゲームメイン/SceneMain.h"
#include "Objteki5.h"
#include "SceneSTG5.h"
#include "GameHead.h"

//コンストラクタ
CSceneSTG5::CSceneSTG5()
{
}

//デストラクタ
CSceneSTG5::~CSceneSTG5()
{
}

//ゲームタイトル初期化メソッド
void CSceneSTG5::InitScene()
{

	//STGオブジェクト作成
	CObjSTG5* obj = new CObjSTG5();
	Objs::InsertObj(obj, OBJ_STG5, 10);

	//背景を読み込み0番に登録
	Draw::LoadImage(L"syu-haikei.png", 20, TEX_SIZE_512);

	//敵４を読み込み1番に登録
	Draw::LoadImage(L"teki5.png", 30, TEX_SIZE_512);

	//主人公を読み込み6番に登録
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_STG5, 10);

	CObjBackGround* q = new CObjBackGround();
	Objs::InsertObj(q, OBJ_BACKGROUND, 20);

	CObjteki5* objb = new CObjteki5(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI5, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);
}

//ゲームタイトル実行中メソッド
void CSceneSTG5::Scene()
{

}
