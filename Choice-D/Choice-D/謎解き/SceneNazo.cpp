//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain.h"
#include "SceneNazo.h"
#include "../GameHead.h"

//コンストラクタ
CSceneNazo::CSceneNazo()
{
}

//デストラクタ
CSceneNazo::~CSceneNazo()
{
}

//ゲームタイトル初期化メソッド
void CSceneNazo::InitScene()
{
	//出力させる文字のグラフィックを作成
	//例　Font::SetStrTex(L"ゲームを始める");

	Draw::LoadImageW(L"tenkey.png", 2, TEX_SIZE_512);


	//オブジェクト作成
	CObjTenkey* key = new CObjTenkey();
	Objs::InsertObj(key, OBJ_TENKEY, 10);
}

//ゲームタイトル実行中メソッド
void CSceneNazo::Scene()
{
}
