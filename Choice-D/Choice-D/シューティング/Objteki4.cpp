//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"
#include "../GameL/DrawFont.h"
#include "../GameHead.h"
#include "Objteki4.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjteki4::CObjteki4(float x, float y)
{
	m_hp = 25.f;
	m_maxhp = 25.f;
	m_dtime = 300;
	m_x = x;
	m_y = y;

}

//イニシャライズ
void CObjteki4::Init()
{
	m_time = 0;
	m_r = 42.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	//当たり判定HitBox
	Hits::SetHitBox(this, m_x, m_y, 160, 210, ELEMENT_ENEMY, OBJ_TEKI4, 1);

}

//アクション
void CObjteki4::Action()
{
	m_time++;

	//通常弾発射
	if (m_time % 35 == 0)
	{
		if (m_hp <= 0)
		{
			;
		}
		else
		{
			//弾丸敵機オブジェクト
			CObjBulletTeki4* obj_b = new CObjBulletTeki4(m_x + 65, m_y + 95);
			Objs::InsertObj(obj_b, OBJ_BULLET_TEKI4, 100);
		}
	}

	//誘導弾発射
	if (m_time % 200 == 0)
	{
		if (m_hp <= 0)
		{
			;
		}
		else
		{
			//誘導弾丸作成
			CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x + 65, m_y + 95);//誘導弾丸作成
			Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 100);//誘導弾丸登録
		}
	}

	//m_timeの初期化
	if (m_time > 1000)
	{
		m_time = 0;
	}

	//角度加算
	m_r += 1.0f;

	//360°で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;

	//移動方向
	m_vx = sin(3.14f / 180 * m_r);
	m_vy = 0.0f;

	//移動ベクトル正規化
	UnitVec(&m_vy, &m_vx);

	//速度付ける。
	m_vx *= 2.5f;
	m_vy *= 2.5f;

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x , m_y );

	//敵機が完全に領域外にでたら敵機を破棄する
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);		//自身に削除命令
		Hits::DeleteHitBox(this);
	}
	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		m_dtime--;

		if (m_dtime <= 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			m_tekicnt++;
			m_floor++;

			m_endflag = true;
			Scene::SetScene(new CSceneKuria4());
		}
		//20°間隔で弾丸発射(拡散弾発射)
		else if (m_time % 10 == 0)
		{
			//19発同時発射
			CObjAngleBullet* obj_b;
			for (int i = 0; i < 360; i += 20)
			{
				//角度iで角度弾丸発射
				obj_b = new CObjAngleBullet(m_x + 65, m_y + 95, i, 5.0f);
				Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
			}
		}
	
	}


	//弾丸と接触したらHPを減らす
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}
	//チャージ弾のダメージ３
	if (hit->CheckObjNameHit(OBJ_CHARGE_BULLET) != nullptr)
	{
		m_hp -= 3;

	}


}

	//ドロー
	void CObjteki4::Draw()
	{
		//描画カラー情報　R=RED　G=Green　B=Blue　A=alpha(透過情報）A=alpha(透過情報）
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		RECT_F src;//描画元切り取り位置
		RECT_F dst;//描画先表示位置

		//敵HP表示
		float h[4] = { 1.0f,1.0f,1.0f,1.0f };
		Font::StrDraw(L"敵のHP", 0, 75, 28, h);

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1280.0f;
		src.m_bottom = 720.0f;

		//表示位置の設定
		dst.m_top = 100.0f;
		dst.m_left = 0.0f;
		dst.m_right = (m_hp / m_maxhp)*128.0f;
		dst.m_bottom = 125.0f;

		//5番目に登録したグラフィックをsrc・dst・cの元の情報に描画
		Draw::Draw(5, &src, &dst, h, 0.0f);


		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1152.0f;
		src.m_bottom = 1772.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 160.0f + m_x;
		dst.m_bottom = 210.0f + m_y;

		//10番めに登録したグラフィックをsrc・dst・cの情報を元に描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}