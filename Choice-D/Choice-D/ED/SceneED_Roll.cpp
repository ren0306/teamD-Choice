//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL/Audio.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain.h"
#include "SceneED1.h"
#include "../GameHead.h"

//コンストラクタ
CSceneED_Roll::CSceneED_Roll()
{
}

//デストラクタ
CSceneED_Roll::~CSceneED_Roll()
{
}

//ゲームエンディング1初期化メソッド
void CSceneED_Roll::InitScene()
{
	Audio::LoadAudio(0, L"BADENDBGM .wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(0);

	//エンディング1オブジェクト作成
	CObjED_Roll* obj = new CObjED_Roll();
	Objs::InsertObj(obj, OBJ_ED_ROLL, 10);
}

//ゲームエンディング1実行中メソッド
void CSceneED_Roll::Scene()
{
}
