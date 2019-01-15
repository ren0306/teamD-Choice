#pragma once
//使用するヘッダーファイル
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：シューティング背景
class CObjBulletMove : public CObj
{
	public:
		CObjBulletMove();
		~CObjBulletMove() {};
		void Init();	//イニシャライズ
		void Action();  //アクション
		void Draw();	//ドロー
	private:
		float m_x;			//弾丸のX方向の位置用変数
		float m_y;			//弾丸のY方向の位置用変数
		float m_vx;			//弾丸のX方向の速度用変数
		float m_vy;			//弾丸のY方向の速度用変数
		int	   m_ani;		//着弾アニメーション用
		int	   m_ani_time;	//着弾アニメーション間隔タイム
		bool   m_del;		//削除チェック
		RECT_F m_eff;		//着弾エフェクト描画用	
};
