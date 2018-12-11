//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "ゲームメイン/SceneMain.h"
#include "Objteki5.h"
#include "SceneSTG5.h"
#include "GameHead.h"

//コンストラクタ
CSceneSTG5::CSceneSTG5()
{
}

//デストラクタ
CSceneSTG5::~CSceneSTG5()
{
}

//ゲームシューティング5初期化メソッド
void CSceneSTG5::InitScene()
{

	//STGオブジェクト作成
	CObjSTG5* obj = new CObjSTG5();
	Objs::InsertObj(obj, OBJ_STG5, 10);

	//バックミュージックスタート
	float Volumu = Audio::VolumeMaster(-0.8f); //マスターボリュームを0.8下げる。
	Audio::Start(0);//音楽スタート

	//背景を読み込み0番に登録
	Draw::LoadImage(L"syu-haikei.png", 0, TEX_SIZE_512);

	//敵５を読み込み10番に登録
	Draw::LoadImage(L"teki5.png", 10, TEX_SIZE_512);

	//主人公を読み込み6番に登録
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//敵弾丸を読み込み30番に登録
	Draw::LoadImage(L"Bullet5.png", 30, TEX_SIZE_512);

	//主人公弾丸を読み込み11番に登録
	Draw::LoadImage(L"HeroBullet.png", 11, TEX_SIZE_512);

	//敵HPバー表示
	Draw::LoadImage(L"HP.png", 5, TEX_SIZE_512);

	//背景オブジェクト作成
	STGBackground* back = new STGBackground();
	Objs::InsertObj(back, OBJ_STGBACKGROUND, 20);

	CObjteki5* objb = new CObjteki5(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI5, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);
	
	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);

	
}

//ゲームシューティング5実行中メソッド
void CSceneSTG5::Scene()
{

}
