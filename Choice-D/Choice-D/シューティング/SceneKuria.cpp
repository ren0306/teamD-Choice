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
#include "SceneKuria.h"
#include "../GameHead.h"

//コンストラクタ
CSceneKuria::CSceneKuria()
{
}

//デストラクタ
CSceneKuria::~CSceneKuria()
{
}

//ゲームタイトル初期化メソッド
void CSceneKuria::InitScene()
{
	
	
	
	//タイトルオブジェクト作成
	CObjKuria* obj = new CObjKuria();
	Objs::InsertObj(obj, OBJ_KURIA, 10);
}

//ゲームタイトル実行中メソッド
void CSceneKuria::Scene()
{

}
