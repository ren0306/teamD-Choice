//STLデバッグ機能をOFFにする
#define _SECURE SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "ShootingMain.h"
#include "../GameHead.h"

//コンストラクタ
CShootingMain::CShootingMain()
{

}

//デストラクタ
CShootingMain::~CShootingMain()
{

}

//ゲームメイン初期化メソッド
void CShootingMain::InitScene()
{
	/*
	//音楽読み込み
	Audio::LoadAudio(0, L"BGMGameMain.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMBoss.wav", BACK_MUSIC);

	Audio::LoadAudio(2, L"SETrigger.wav", EFFECT);
	Audio::LoadAudio(3, L"SEBom.wav", EFFECT);

	//ボリュームを1.5に増やす
	float v = Audio::VolumeMaster(1.5);

	//音楽スタート
	Audio::Start(0);
	*/

	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)
	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)
	Draw::LoadImage(L"hero.png", 1, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み2番に登録(512×512ピクセル)
	Draw::LoadImage(L"Enemy2.png", 2, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)
	//Draw::LoadImage(L"BossBack.png", 1, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();   //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 10);//作った主人公オブジェクトをオブジェクトマネージャーに登録

	/*
	//背景オブジェクト作成
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 5);
	*/

	//タイム初期化
	m_time = 0;
}

//ゲームメイン実行中メソッド
void CShootingMain::Scene()
{
	m_time++;

	if (m_time == 1)
	{
		CObjEnemy1* obj;
		obj = new CObjEnemy1(400, 200);
		Objs::InsertObj(obj, OBJ_ENEMY1, 50);
	}

	/*
	m_time++;

	if (m_time == 30)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 80)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 120)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 200);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 200)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(799.0f, 100);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 500);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 400)
	{
		CObjEnemy* obj1;
		obj1 = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj1, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 400);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);
	}
	else if (m_time == 550)
	{
		CObjEnemy* obj1;
		obj1 = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj1, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 300);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);
	}
	else if (m_time == 680)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 250);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 750)
	{
		CObjAttackEnemy* obj;
		obj = new CObjAttackEnemy(799, 300);
		Objs::InsertObj(obj, OBJ_ATTACK_ENEMY, 50);
	}
	else if (m_time == 1000)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i*32);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}
	}
	else if (m_time == 1100)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i * 32 + 64);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}
	}
	else if (m_time == 1200)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i * 32);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}
	}
	else if (m_time == 1300)
	{
		CObjSinEnemy* obj1;
		for (int i = 0; i < 15; i++)
		{
			obj1 = new CObjSinEnemy(799, i * 32);
			Objs::InsertObj(obj1, OBJ_SIN_ENEMY, 50);
		}

		CObjDiffusionEnemy* obj2;
		obj2 = new CObjDiffusionEnemy(799, 300);
		Objs::InsertObj(obj2, OBJ_DIFFUSION_ENEMY, 50);
	}
	else if (m_time == 1500)
	{
		CObjHomingEnemy* obj;
		obj = new CObjHomingEnemy(799, 500);
		Objs::InsertObj(obj, OBJ_HOMING_ENEMY, 50);
	}
	else if (m_time == 2000)
	{
		//音楽チェンジ
		Audio::Stop(0); //0番曲をストップ
		Audio::Start(1);//1番曲をスタート

		CObjBoss* obj;
		obj = new CObjBoss(300, 100);
		Objs::InsertObj(obj, OBJ_BOSS_ENEMY, 50);
	}
	*/
}
