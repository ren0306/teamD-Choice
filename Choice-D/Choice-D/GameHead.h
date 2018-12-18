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
	OBJ_BULLET_TEKI1,
	OBJ_BULLET_TEKI2,
	OBJ_BULLET_TEKI3,
	OBJ_BULLET_TEKI4,
	OBJ_BULLET_TEKI5,
	OBJ_CHARGE_BULLET,
	OBJ_CHARGE_EFFECT,
	OBJ_ANGLE_BULLET,
	OBJ_HOMING_BULLET,
	OBJ_MEANDER_BULLET,
	OBJ_GAMEOVER,
	OBJ_MAIN,
	OBJ_MAIN2,
	OBJ_MAIN3,
	OBJ_MAIN4,
	OBJ_MAIN5,
	OBJ_BACKGROUND,
	OBJ_BACKGROUND2,
	OBJ_BACKGROUND3,
	OBJ_BACKGROUND4,
	OBJ_BACKGROUND5,
	OBJ_STGBACKGROUND,
	OBJ_GAMEOVER2,
	OBJ_ED1,
	OBJ_ED3,
	OBJ_ED2,
	OBJ_NAZO,
	OBJ_TENKEY,
	OBJ_TENKEY2,
	OBJ_TENKEY3,
	OBJ_TENKEY4,
	OBJ_TENKEY5,
	OBJ_TEKI1,
	OBJ_TEKI2,
	OBJ_TEKI3,
	OBJ_TEKI4,
	OBJ_TEKI5,
	OBJ_STG,
	OBJ_STG2,
	OBJ_STG3,
	OBJ_STG4,
	OBJ_STG5,
	OBJ_BGN,
	OBJ_DOOR,
	OBJ_DOOR2,
	OBJ_SOUSAGAMEN,
	OBJ_GAMEOVERGAMEN,
	OBJ_ED1GAZOU,
	OBJ_ED2GAZOU,
	OBJ_ED3GAZOU,
	OBJ_KURIA,
	OBJ_REMEMBER,
	OBJ_TIME,
	OBJ_KURIA2,
	OBJ_KURIA3,
	OBJ_KURIA4,
	OBJ_KURIA5,
	OBJ_OP,
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

//ED分岐用グローバル変数---------
extern bool m_endflag;
extern bool m_nazoflag;
extern int m_Nazocnt;
extern int m_tekicnt;
//-------------------------------
//ゲーム内時間管理グローバル変数------------------
extern int m_TimeL;
extern int m_floor;
//------------------------------------------------
extern float m_Mehp;
extern float m_misscnt;//間違えた時の時間を減らす表示をする変数	
extern float m_clearcnt;
extern bool m_clear;
extern bool m_miss;//答え間違いならtrue変数
extern float m_BGM;

//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "シューティング\ObjHero.h"
#include "シューティング\CObjBullet.h"
#include "CObjBulletTeki1.h"
#include "CObjBulletTeki2.h"
#include "CObjBulletTeki3.h"
#include "CObjBulletTeki4.h"
#include "CObjBulletTeki5.h"
#include "CObjAngleBullet.h"
#include "CObjHomingBullet.h"
#include "CObjMeanderBullet.h"
#include "シューティング\CObjChargeBullt.h"
#include "CObjChargeEffect.h"
//#include "CObjBulletMove.h"
#include "タイトル\ObjTitle.h"
#include "ゲームメイン\ObjMain.h"
#include "ゲームメイン\ObjMain2.h"
#include "ObjMain3.h"
#include "ObjMain4.h"
#include "ObjMain5.h"
#include "GameOver\GAMEOVER1.h"
#include "GameOver\GAME OVER2.h"
#include "小物関係\ObjBackGround.h"
#include "小物関係\ObjBackGround2.h"
#include "小物関係\ObjBackGround3.h"
#include "小物関係\ObjBackground4.h"
#include "小物関係\ObjBackground5.h"
#include "STGBackground.h"
#include "ED\ObjED2.h"
#include "ED\ObjED1.h"
#include "ED\ObjED3.h"
#include "謎解き\ObjTenkey.h"
#include "小物関係\ObjTenkey2.h"
#include "小物関係\ObjTenkey3.h"
#include "小物関係\ObjTenkey4.h"
#include "小物関係\ObjTenkey5.h"
#include "シューティング\Objteki1.h"
#include "シューティング\Objteki2.h"
#include "シューティング\Objteki3.h"
#include "シューティング\Objteki4.h"
#include "Objteki5.h"
#include "シューティング\ObjSTG.h"
#include "シューティング\ObjSTG2.h"
#include "シューティング\ObjSTG3.h"
#include "シューティング\ObjSTG4.h"
#include "ObjSTG5.h"
#include "謎解き\ObjBGNazo.h"
#include "ObjBGNazo2.h"
#include "ObjBGNazo3.h"
#include "ObjBGNazo4.h"
#include "ObjBGNazo5.h"
#include "小物関係\ObjDoor.h"
#include "小物関係\GameOvergamen.h"
#include "小物関係\ObjDoor2.h"
#include "タイトル\ObjSousagamen.h"
#include "小物関係\ObjED1gazou.h"
#include "小物関係\ObjED2gazou.h"
#include "小物関係\ObjED3gazou.h"
#include "シューティング\ObjKuria.h"
#include "小物関係\TimeLimit.h"
#include "シューティング\ObjKuria2.h"
#include "シューティング\ObjKuria3.h"
#include "シューティング\ObjKuria4.h"
#include "タイトル\ObjOP.h"
#include "ObjBulletMove.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "ゲームメイン\SceneMain.h"
#include "ゲームメイン\SceneMain2.h"
#include "ゲームメイン\SceneMain3.h"
#include "ゲームメイン\SceneMain4.h"
#include "ゲームメイン\SceneMain5.h"
#include "タイトル\SceneTitle.h"
#include "GameOver\GameOver.h"
#include "GameOver\GameOver2.h"
#include "ED\SceneED1.h"
#include "ED\SceneED2.h"
#include "ED\SceneED3.h"
#include "謎解き\SceneNazo.h"
#include "謎解き\SceneNazo2.h"
#include "謎解き\SceneNazo3.h"
#include "謎解き\SceneNazo4.h"
#include "謎解き\SceneNazo5.h"
#include "シューティング\SceneSTG.h"
#include "シューティング\SceneSTG2.h"
#include "シューティング\SceneSTG3.h"
#include "シューティング\SceneSTG4.h"
#include "SceneSTG5.h"
#include "タイトル\SceneSousagamen.h"
#include "シューティング\SceneKuria.h"
#include "シューティング\SceneKuria2.h"
#include "シューティング\SceneKuria3.h"
#include "シューティング\SceneKuria4.h"
#include "タイトル\SceneOP.h"

//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------