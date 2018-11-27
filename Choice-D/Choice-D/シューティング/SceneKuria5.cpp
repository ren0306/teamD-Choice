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
#include "SceneKuria5.h"
#include "../GameHead.h"

//コンストラクタ
CSceneKuria5::CSceneKuria5()
{
}

//デストラクタ
CSceneKuria5::~CSceneKuria5()
{
}

//バトルクリア初期化メソッド
void CSceneKuria5::InitScene()
{



	//クリアオブジェクト作成
	CObjKuria5* obj = new CObjKuria5();
	Objs::InsertObj(obj, OBJ_KURIA5, 10);
}

//バトルクリア実行中メソッド
void CSceneKuria5::Scene()
{

}