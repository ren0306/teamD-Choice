//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL/DrawTexture.h"
#include"../GameL/Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain.h"
#include "SceneKuria3.h"
#include "../GameHead.h"

//コンストラクタ
CSceneKuria3::CSceneKuria3()
{
}

//デストラクタ
CSceneKuria3::~CSceneKuria3()
{
}

//バトルクリア初期化メソッド
void CSceneKuria3::InitScene()
{
	Audio::LoadAudio(0, L"勝利.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(0);


	//クリアオブジェクト作成
	CObjKuria3* obj = new CObjKuria3();
	Objs::InsertObj(obj, OBJ_KURIA3, 10);
}

//バトルクリア実行中メソッド
void CSceneKuria3::Scene()
{

}