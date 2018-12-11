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
	Draw::LoadImage(L"OPtobira.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"OPteki.png", 2, TEX_SIZE_512);

	//OPオブジェクト作成
	CObjOP* abc = new CObjOP();
	Objs::InsertObj(abc, OBJ_OP, 10);

	//OPオブジェクト作成
	CObjOP* d = new CObjOP();
	Objs::InsertObj(d, OBJ_OP, 10);
}

//ゲームタイトル実行中メソッド
void CSceneOP::Scene()
{
}
