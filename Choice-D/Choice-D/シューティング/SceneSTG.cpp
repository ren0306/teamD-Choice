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
#include "Objteki1.h"
#include "SceneSTG.h"
#include "../GameHead.h"

//コンストラクタ
CSceneSTG::CSceneSTG()
{
}

//デストラクタ
CSceneSTG::~CSceneSTG()
{
}

//ゲームシューティング初期化メソッド
void CSceneSTG::InitScene()
{

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"STGBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(2, L"HeroBullet.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);



	//STGオブジェクト作成
	CObjSTG* obj = new CObjSTG();
	Objs::InsertObj(obj, OBJ_STG, 10);

	//背景を読み込み0番に登録
	Draw::LoadImage(L"syu-haikei.png", 0, TEX_SIZE_512);
	
	//敵１を読み込み10番に登録
	Draw::LoadImage(L"teki1.png", 10, TEX_SIZE_512);

	//主人公を読み込み6番に登録
	Draw::LoadImage(L"hero.png", 6, TEX_SIZE_512);

	//チャージエフェクトを読み込み8番に登録
	Draw::LoadImage(L"ChargeEffect.png", 8, TEX_SIZE_512);

	//敵弾丸を読み込み30番に登録
	Draw::LoadImage(L"Bullet1.png", 30, TEX_SIZE_512);

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

	CObjteki1* objb = new CObjteki1(200,10);
	Objs::InsertObj(objb, OBJ_TEKI1, 50);

	CObjHero*ob = new CObjHero();
	Objs::InsertObj(ob, OBJ_HERO, 150);

	CObjTimeLimit* t = new CObjTimeLimit();
	Objs::InsertObj(t, OBJ_TIME, 150);

	CObjChargeEffect*ef = new CObjChargeEffect(-100, -100);
	Objs::InsertObj(ef, OBJ_CHARGE_EFFECT, 145);
}

//ゲームシューティング実行中メソッド
void CSceneSTG::Scene()
{
}

