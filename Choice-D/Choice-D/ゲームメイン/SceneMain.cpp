//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawTexture.h"
#include "../GameL\DrawFont.h"
#include "../GameL\UserData.h"
#include "../GameL/Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "../GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{
}




//テストラクタ
CSceneMain::~CSceneMain()
{
}



//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイルを読み込み０番に登録
	Draw::LoadImage(L"doukutu.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door.png", 1, TEX_SIZE_512);
	//敵１を読み込み2番に登録
	Draw::LoadImage(L"teki1.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"sentaku.png", 3, TEX_SIZE_512);


	Font::SetStrTex(L"謎解きを選ぶ");

	//BGMを登録
	Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);
	float Volume = Audio::VolumeMaster(-0.9f);//マスターボリュームを0.8下げる

	Audio::Start(0);

	//扉音を登録
	Audio::LoadAudio(1, L"door-old-open1 .wav", SOUND_TYPE::EFFECT);
	

	Audio::Start(1);

	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_MAIN, 140);

	CObjBackGround* b = new CObjBackGround();
	Objs::InsertObj(b, OBJ_BACKGROUND, 120);

	CObjDoor* Door = new CObjDoor();
	Objs::InsertObj(Door, OBJ_DOOR, 130);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);



}



//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{
}
