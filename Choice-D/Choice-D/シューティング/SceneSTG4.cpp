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
#include "Objteki4.h"
#include "SceneSTG4.h"
#include "../GameHead.h"

//コンストラクタ
CSceneSTG4::CSceneSTG4()
{
}

//デストラクタ
CSceneSTG4::~CSceneSTG4()
{
}

//ゲームタイトル初期化メソッド
void CSceneSTG4::InitScene()
{

	//STGオブジェクト作成
	CObjSTG4* obj = new CObjSTG4();
	Objs::InsertObj(obj, OBJ_STG3, 10);

	//外部グラフィックファイルを読み込み0番に登録
	Draw::LoadImageW(L"dou.png", 0, TEX_SIZE_512);

	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_STG3, 10);

	CObjBackGround* p = new CObjBackGround();
	Objs::InsertObj(p, OBJ_BACKGROUND, 0);


	//外部グラフィックファイルを読み込み1番に登録
	Draw::LoadImageW(L"teki4.png", 10, TEX_SIZE_512);

	CObjteki4* objb = new CObjteki4(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI1, 50);
}

//ゲームタイトル実行中メソッド
void CSceneSTG4::Scene()
{

}

