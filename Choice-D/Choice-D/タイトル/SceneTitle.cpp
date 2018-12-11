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
	//音楽情報の読み込み
	Audio::LoadAudio(0, L"TitleBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float Volumu = Audio::VolumeMaster(-0.8f); //マスターボリュームを0.8下げる。
	Audio::Start(0);//音楽スタート

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
