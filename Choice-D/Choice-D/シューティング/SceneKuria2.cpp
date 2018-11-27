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
#include "SceneKuria2.h"
#include "../GameHead.h"

//コンストラクタ
CSceneKuria2::CSceneKuria2()
{
}

//デストラクタ
CSceneKuria2::~CSceneKuria2()
{
}

//バトルクリア初期化メソッド
void CSceneKuria2::InitScene()
{



	//クリアオブジェクト作成
	CObjKuria2* obj = new CObjKuria2();
	Objs::InsertObj(obj, OBJ_KURIA2, 10);
}

//バトルクリア実行中メソッド
void CSceneKuria2::Scene()
{

}