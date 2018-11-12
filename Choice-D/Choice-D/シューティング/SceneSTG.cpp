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
#include "Objteki1.h"
#include "SceneSTG.h"
#include "../GameHead.h"

//コンストラクタ
CSceneSTG::CSceneSTG()
{
}

//デストラクタ
CSceneSTG::~CSceneSTG()
{
}

//ゲームタイトル初期化メソッド
void CSceneSTG::InitScene()
{
	

	//STGオブジェクト作成
	CObjSTG* obj = new CObjSTG();
	Objs::InsertObj(obj, OBJ_STG, 10);

	

	//背景を読み込み0番に登録
	Draw::LoadImage(L"syu-haikei.png", 20, TEX_SIZE_512);
	
	//敵１を読み込み1番に登録
	Draw::LoadImage(L"teki1.png", 10, TEX_SIZE_512);

	//主人公を読み込み6番に登録
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//敵弾丸を読み込み30番に登録
	Draw::LoadImage(L"Bullet1.png", 30, TEX_SIZE_512);

	CObjBackGround* q = new CObjBackGround();
	Objs::InsertObj(q, OBJ_BACKGROUND, 20);

	CObjteki1* objb = new CObjteki1(200,10);
	Objs::InsertObj(objb, OBJ_TEKI1, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);
}

//ゲームタイトル実行中メソッド
void CSceneSTG::Scene()
{
}

