//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL/DrawTexture.h"
#include "../GameL\Audio.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain.h"
#include "SceneTitle.h"
#include "../GameHead.h"
#include "../ObjBGM.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{
}

//デストラクタ
CSceneTitle::~CSceneTitle()
{
}

//ゲームタイトル初期化メソッド
void CSceneTitle::InitScene()
{
	Audio::LoadAudio(0, L"titleBGM.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::Start(0);

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"ゲームを始める");
	Draw::LoadImage(L"Title.png", 0, TEX_SIZE_512);
	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);
}

//ゲームタイトル実行中メソッド
void CSceneTitle::Scene()
{
}
