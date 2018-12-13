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
#include "../ゲームメイン/SceneMain4.h"
#include "../GameHead.h"

//コンストラクタ
CSceneMain4::CSceneMain4()
{
}




//テストラクタ
CSceneMain4::~CSceneMain4()
{
}



//ゲームメイン初期化メソッド
void CSceneMain4::InitScene()
{

	//BGMを登録
	//Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);
	//float Volume = Audio::VolumeMaster(-0.9f);//マスターボリュームを0.8下げる

	//Audio::Start(0);

	//外部グラフィックファイルを読み込み1番に登録
	Draw::LoadImage(L"Main4.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"door2.png", 20, TEX_SIZE_512);
	//敵２を読み込み2番に登録
	Draw::LoadImage(L"teki4.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"sentaku.png", 3, TEX_SIZE_512);

	CObjMain4* m = new CObjMain4();
	Objs::InsertObj(m, OBJ_MAIN4, 140);

	CObjBackGround4* b = new CObjBackGround4();
	Objs::InsertObj(b, OBJ_BACKGROUND4, 120);

	CObjDoor2* Door2 = new CObjDoor2();
	Objs::InsertObj(Door2, OBJ_DOOR2, 130);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);




}



//ゲームメイン実行中メソッド
void CSceneMain4::Scene()
{
}
