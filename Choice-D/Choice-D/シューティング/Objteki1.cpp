//使用するヘッダーファイル
#include "../GameL\DrawTexture.h"
#include "../GameL\HitBoxManager.h"

#include "../GameHead.h"
#include "Objteki1.h"
#include "UtilityModule.h"
#include "../GameL/DrawFont.h"


//使用するネームスペース
using namespace GameL;


//コンストラクタ
CObjteki1::CObjteki1(float x, float y)
{
	m_x = x;
	m_y = y;
}












//イニシャライズ
void CObjteki1::Init()
{
	m_hp = 30.f;
	m_maxhp = 30.f;


	m_time = 0;
	m_vx = 0.0f;
	m_vy = 0.0f;
	//当たり判定HitBox
	Hits::SetHitBox(this, m_x, m_y, 200, 170, ELEMENT_ENEMY, OBJ_TEKI1, 1);
}

//アクション
void CObjteki1::Action()
{
	//HitBox位置を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x +90, m_y +20);


	m_time++;

	//通常弾発射
	if (m_time % 50 == 0)
	{
		//弾丸敵機オブジェクト
		CObjBulletTeki1* obj_b = new CObjBulletTeki1(m_x + 178, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_BULLET_TEKI1, 100);
	}

	//m_timeの初期化
	if (m_time > 1000)
	{
		m_time = 0;
	}

	//角度加算
	m_r += 2.0f;

	//360°で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;

	//移動方向
	m_vx = sin(3.14 / 180 * m_r);
	m_vy = 0.0f;

	//移動ベクトル正規化
	UnitVec(&m_vy, &m_vx);

	//速度付ける。
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;

	if (m_hp <= 15)
	{
		m_vx *= 1.5f*2;
		m_vy *= 1.5f*2;

	}


	//弾丸と接触してるしたらHPを減らす
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}
	if (m_hp <= 0)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//敵機弾丸が所有するHItBoxに削除する
		m_f = true;
		Scene::SetScene(new CSceneKuria());

	}



}

//ドロー
void CObjteki1::Draw()
{

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

	//敵表示
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 984.0f;
	src.m_bottom = 760.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 400.0f + m_x;
	dst.m_bottom = 260.0f + m_y;

	//10番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(10, &src, &dst, c, 0.0f);





}


