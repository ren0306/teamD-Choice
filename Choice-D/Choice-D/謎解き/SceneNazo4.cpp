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
#include "../ゲームメイン/SceneMain4.h"
#include "SceneNazo4.h"
#include "../GameHead.h"

//コンストラクタ
CSceneNazo4::CSceneNazo4()
{
}

//デストラクタ
CSceneNazo4::~CSceneNazo4()
{
}

//ゲームタイトル初期化メソッド
void CSceneNazo4::InitScene()
{
	Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"delete.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(2, L"warning.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(3, L"next.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(4, L"keyboardSE.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);

	//出力させる文字のグラフィックを作成
	//例　Font::SetStrTex(L"ゲームを始める");
	Draw::LoadImage(L"Main4.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tenkey.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"解答.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"問題4.png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"ヒント.png", 14, TEX_SIZE_512);
	Draw::LoadImage(L"ヒント４.png", 15, TEX_SIZE_512);

	//オブジェクト作成
	CObjTenkey4* key = new CObjTenkey4();
	Objs::InsertObj(key, OBJ_TENKEY4, 2);

	CObjBGN4* BGN = new CObjBGN4();
	Objs::InsertObj(BGN, OBJ_BGN, 1);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 0);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);


}

//ゲームタイトル実行中メソッド
void CSceneNazo4::Scene()
{


}
