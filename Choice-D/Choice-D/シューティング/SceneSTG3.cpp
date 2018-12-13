//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL\Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain.h"
#include "Objteki3.h"
#include "SceneSTG3.h"
#include "../GameHead.h"

//コンストラクタ
CSceneSTG3::CSceneSTG3()
{
}

//デストラクタ
CSceneSTG3::~CSceneSTG3()
{
}

//ゲームシューティング3初期化メソッド
void CSceneSTG3::InitScene()
{

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"STGBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(2, L"HeroBullet.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);

	//STGオブジェクト作成
	CObjSTG3* obj = new CObjSTG3();
	Objs::InsertObj(obj, OBJ_STG3, 10);

	//バックミュージックスタート
	//float Volumu = Audio::VolumeMaster(-0.8f); //マスターボリュームを0.8下げる。
	//Audio::Start(0);//音楽スタート

	//背景を読み込み0番に登録
	Draw::LoadImage(L"syu-haikei.png", 0, TEX_SIZE_512);

	//敵３を読み込み10番に登録
	Draw::LoadImage(L"teki3.png", 10, TEX_SIZE_512);

	//主人公を読み込み6番に登録
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//敵弾丸を読み込み30番に登録
	Draw::LoadImage(L"Bullet3.png", 30, TEX_SIZE_512);

	//主人公弾丸を読み込み11番に登録
	Draw::LoadImage(L"HeroBullet.png", 11, TEX_SIZE_512);

	//敵HPバー表示
	Draw::LoadImage(L"HP.png", 5, TEX_SIZE_512);

	//ため攻撃
	Draw::LoadImage(L"tamedama.png", 12, TEX_SIZE_512);


	//背景オブジェクト作成
	STGBackground* back = new STGBackground();
	Objs::InsertObj(back, OBJ_STGBACKGROUND, 20);

	CObjteki3* objb = new CObjteki3(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI3, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);

}

//ゲームシューティング3実行中メソッド
void CSceneSTG3::Scene()
{

}

