//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL\DrawTexture.h"
#include "../GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain.h"
#include "SceneNazo2.h"
#include "../GameHead.h"

//コンストラクタ
CSceneNazo2::CSceneNazo2()
{
}

//デストラクタ
CSceneNazo2::~CSceneNazo2()
{
}

//ゲームタイトル初期化メソッド
void CSceneNazo2::InitScene()
{
	//出力させる文字のグラフィックを作成
	//例　Font::SetStrTex(L"ゲームを始める");
	Draw::LoadImage(L"ss01.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tenkey.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"解答.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"問題.png", 13, TEX_SIZE_512);


	Audio::LoadAudio(0, L"door-old-open1 .wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(1, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(1);
	//オブジェクト作成
	CObjTenkey2* key = new CObjTenkey2();
	Objs::InsertObj(key, OBJ_TENKEY2, 2);

	CObjBGN* BGN = new CObjBGN();
	Objs::InsertObj(BGN, OBJ_BGN, 1);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 0);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);


}

//ゲームタイトル実行中メソッド
void CSceneNazo2::Scene()
{


}
