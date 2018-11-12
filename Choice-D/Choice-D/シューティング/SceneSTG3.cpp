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
#include "Objteki3.h"
#include "SceneSTG3.h"
#include "../GameHead.h"

//コンストラクタ
CSceneSTG3::CSceneSTG3()
{
}

//デストラクタ
CSceneSTG3::~CSceneSTG3()
{
}

//ゲームタイトル初期化メソッド
void CSceneSTG3::InitScene()
{

	//STGオブジェクト作成
	CObjSTG3* obj = new CObjSTG3();
	Objs::InsertObj(obj, OBJ_STG3, 10);

	//外部グラフィックファイルを読み込み0番に登録
	Draw::LoadImage(L"syu-haikei.png", 20, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録
	Draw::LoadImage(L"teki3.png", 10, TEX_SIZE_512);

	//主人公を読み込み6番に登録
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//敵弾丸を読み込み30番に登録
	Draw::LoadImage(L"Bullet3.png", 30, TEX_SIZE_512);

	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_STG3, 10);

	CObjBackGround* q = new CObjBackGround();
	Objs::InsertObj(q, OBJ_BACKGROUND, 20);

	CObjteki3* objb = new CObjteki3(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI1, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);
}

//ゲームタイトル実行中メソッド
void CSceneSTG3::Scene()
{

}

