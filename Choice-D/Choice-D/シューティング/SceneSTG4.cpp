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
#include "Objteki4.h"
#include "SceneSTG4.h"
#include "../GameHead.h"

//コンストラクタ
CSceneSTG4::CSceneSTG4()
{
}

//デストラクタ
CSceneSTG4::~CSceneSTG4()
{
}

//ゲームシューティング4初期化メソッド
void CSceneSTG4::InitScene()
{

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"STGBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(2, L"HERO弾丸　.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(3, L"消滅.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);

	//STGオブジェクト作成
	CObjSTG4* obj = new CObjSTG4();
	Objs::InsertObj(obj, OBJ_STG4, 10);

	//背景を読み込み0番に登録
	Draw::LoadImage(L"syu-haikei.png", 0, TEX_SIZE_512);

	//敵４を読み込み10番に登録
	Draw::LoadImage(L"teki4.png", 10, TEX_SIZE_512);

	//主人公を読み込み6番に登録
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//チャージエフェクトを読み込み8番に登録
	Draw::LoadImage(L"ChargeEffect.png", 8, TEX_SIZE_512);

	//敵弾丸を読み込み30番に登録
	Draw::LoadImage(L"Bullet4.png", 30, TEX_SIZE_512);

	//主人公弾丸を読み込み11番に登録
	Draw::LoadImage(L"HeroBullet.png", 11, TEX_SIZE_512);

	//敵HPバー表示
	Draw::LoadImage(L"HP.png", 5, TEX_SIZE_512);

	//ため攻撃
	Draw::LoadImage(L"tamedama.png", 12, TEX_SIZE_512);

	//爆破エフェクト２番
	Draw::LoadImage(L"EnemyEX.png", 2, TEX_SIZE_512);

	//背景オブジェクト作成
	STGBackground* back = new STGBackground();
	Objs::InsertObj(back, OBJ_STGBACKGROUND, 20);

	CObjteki4* objb = new CObjteki4(200, 10);
	Objs::InsertObj(objb, OBJ_TEKI4, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);

	CObjChargeEffect*ef = new CObjChargeEffect(-100, -100);
	Objs::InsertObj(ef, OBJ_CHARGE_EFFECT, 145);


	CObjEnemyEX* eef = new CObjEnemyEX(0, 0);
	Objs::InsertObj(eef, OBJ_EX, 200);

}

//ゲームシューティング4実行中メソッド
void CSceneSTG4::Scene()
{

}

