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
#include "SceneNazo.h"
#include "../GameHead.h"

//コンストラクタ
CSceneNazo::CSceneNazo()
{
}

//デストラクタ
CSceneNazo::~CSceneNazo()
{
}

//ゲームタイトル初期化メソッド
void CSceneNazo::InitScene()
{
	//出力させる文字のグラフィックを作成
	//例　Font::SetStrTex(L"ゲームを始める");
	Draw::LoadImage(L"doukutu.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tenkey.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"1.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"2.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"3.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"4.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"5.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"6.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"7.png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"8.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"9.png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"解答.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"問題.png", 13, TEX_SIZE_512);


	Audio::LoadAudio(0, L"door-old-open1 .wav", SOUND_TYPE::EFFECT);

	//オブジェクト作成
	CObjTenkey* key = new CObjTenkey();
	Objs::InsertObj(key, OBJ_TENKEY, 2);

	CObjBGN* BGN = new CObjBGN();
	Objs::InsertObj(BGN, OBJ_BGN, 1);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 0);

	
}

//ゲームタイトル実行中メソッド
void CSceneNazo::Scene()
{
}
