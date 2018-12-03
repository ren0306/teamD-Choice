//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL/DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain.h"
#include "SceneSousagamen.h"
#include "../GameHead.h"

//コンストラクタ
CSceneSousagamen::CSceneSousagamen()
{
}

//デストラクタ
CSceneSousagamen::~CSceneSousagamen()
{
}

//操作画面初期化メソッド
void CSceneSousagamen::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"ゲームを始める");
	Draw::LoadImage(L"ki-bo-do.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"mausu.png", 1, TEX_SIZE_512);
	//Draw::LoadImage(L"tenbin.png", 1, TEX_SIZE_512);

	//操作画面オブジェクト作成
	CObjSousagamen* s = new CObjSousagamen();
	Objs::InsertObj(s, OBJ_SOUSAGAMEN, 10);
}

//操作画面実行中メソッド
void CSceneSousagamen::Scene()
{

}
