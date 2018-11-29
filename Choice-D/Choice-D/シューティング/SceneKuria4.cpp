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
#include "SceneKuria4.h"
#include "../GameHead.h"

//コンストラクタ
CSceneKuria4::CSceneKuria4()
{
}

//デストラクタ
CSceneKuria4::~CSceneKuria4()
{
}

//バトルクリア初期化メソッド
void CSceneKuria4::InitScene()
{



	//クリアオブジェクト作成
	CObjKuria4* obj = new CObjKuria4();
	Objs::InsertObj(obj, OBJ_KURIA4, 10);
}

//バトルクリア実行中メソッド
void CSceneKuria4::Scene()
{

}