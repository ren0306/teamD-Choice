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
#include "SceneOP.h"
#include "../GameHead.h"

//コンストラクタ
CSceneOP::CSceneOP()
{
}

//デストラクタ
CSceneOP::~CSceneOP()
{
}

//ゲームOP初期化メソッド
void CSceneOP::InitScene()
{


	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"ゲームを始める");
	
	//OPオブジェクト作成
	CObjOP* obj = new CObjOP();
	Objs::InsertObj(obj, OBJ_OP, 10);
}

//ゲームタイトル実行中メソッド
void CSceneOP::Scene()
{
}
