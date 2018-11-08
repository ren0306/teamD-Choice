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
#include "../タイトル/SceneTitle.h"
#include "../GameHead.h"

//コンストラクタ
CSceneED1::CSceneED1()
{
}

//デストラクタ
CSceneED1::~CSceneED1()
{
}

//ゲームタイトル初期化メソッド
void CSceneED1::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"ゲームを始める");

	//タイトルオブジェクト作成
	CObjED1* obj = new CObjED1();
	Objs::InsertObj(obj, OBJ_ED1, 10);
}

//ゲームタイトル実行中メソッド
void CSceneED1::Scene()
{
}
