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

	//外部グラフィックファイルを読み込み1番に登録
	Draw::LoadImageW(L"teki1.png", 10, TEX_SIZE_512);

	CObjteki1* objb = new CObjteki1(200,10);
	Objs::InsertObj(objb, OBJ_TEKI1, 50);
}

//ゲームタイトル実行中メソッド
void CSceneSTG::Scene()
{
}

