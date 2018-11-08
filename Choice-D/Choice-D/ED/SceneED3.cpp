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
CSceneED3::CSceneED3()
{
}

//デストラクタ
CSceneED3::~CSceneED3()
{
}

//ゲームタイトル初期化メソッド
void CSceneED3::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"ゲームを始める");

	//タイトルオブジェクト作成
	CObjED3* obj = new CObjED3();
	Objs::InsertObj(obj, OBJ_ED3, 10);
}

//ゲームタイトル実行中メソッド
void CSceneED3::Scene()
{
}
