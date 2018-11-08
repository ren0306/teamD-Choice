#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_TITLE,
	OBJ_HERO,
	OBJ_BULLET,
	OBJ_ENEMY1,
	OBJ_ENEMY2,
	OBJ_ENEMY3,
	OBJ_ENEMY4,
	OBJ_BULLET_ENEMY,
	OBJ_GAMEOVER,
	OBJ_MAIN,
	OBJ_BACKGROUND,
	OBJ_GAMEOVER2,
	OBJ_ED1,
	OBJ_ED3,
	OBJ_ED2,
	OBJ_NAZO,
	OBJ_TENKEY,
	OBJ_TEKI1,
	OBJ_TEKI2,
	OBJ_STG,
	OBJ_STG3,
	OBJ_STG4,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,


};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "シューティング\ObjHero.h"
#include "シューティング\CObjBullet.h"
#include "シューティング\ObjEnemy1.h"
#include "シューティング\ObjEnemy2.h"
#include "シューティング\ObjEnemy3.h"
#include "シューティング\ObjEnemy4.h"
#include "シューティング\CObjBullteEnemy.h"
#include "タイトル\ObjTitle.h"
#include "ゲームメイン\ObjMain.h"
#include "GameOver\GAMEOVER1.h"
#include "GameOver\GAME OVER2.h"
#include "ゲームメイン\ObjBackGround.h"
#include "ED\ObjED2.h"
#include "ED\ObjED1.h"
#include "ED\ObjED3.h"
#include "謎解き\ObjTenkey.h"
#include "シューティング\Objteki1.h"
#include "シューティング\Objteki2.h"
#include "シューティング\ObjSTG.h"
#include "シューティング\ObjSTG2.h"
#include "シューティング\ObjSTG3.h"
#include "シューティング\ObjSTG4.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "ゲームメイン\SceneMain.h"
#include "タイトル\SceneTitle.h"
#include "GameOver\GameOver.h"
#include "シューティング\ShootingMain.h"
#include "GameOver\GameOver2.h"
#include "ED\SceneED1.h"
#include "ED\SceneED3.h"
#include "ED\SceneED2.h"
#include "謎解き\SceneNazo.h"
#include "シューティング\SceneSTG.h"
#include "シューティング\SceneSTG3.h"
#include "シューティング\SceneSTG2.h"
#include "シューティング\SceneSTG4.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------