//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "Objteki5.h"
#include "シューティング\Objteki1.h"
#include "シューティング\UtilityModule.h"
//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjteki5::CObjteki5(float x, float y)
{

	m_hp = 1.f;
	m_maxhp = 35.f;
	m_x = x;
	m_y = y;
}



//イニシャライズ
void CObjteki5::Init()
{
	m_time = 0;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定HitBox
	Hits::SetHitBox(this, m_x, m_y, 180-80, 170, ELEMENT_ENEMY, OBJ_TEKI5, 1);

}

//アクション
void CObjteki5::Action()
{

	m_time++;

	//通常弾発射
	if (m_time % 20 == 0)
	{
		//弾丸敵機オブジェクト
		CObjBulletTeki5* obj_b = new CObjBulletTeki5(m_x + 75, m_y + 95);
		Objs::InsertObj(obj_b, OBJ_BULLET_TEKI5, 100);
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
	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+35 , m_y );

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
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		//敵1の正と負を取得する
//		Remember* flag = (Remember*)Objs::GetObj(OBJ_REMEMBER);
	//	m_f5 = flag->GETF();
		

		Scene::SetScene(new CSceneED2());

	}
	if (m_f5 == true)
	{
		Scene::SetScene(new CSceneED1());
	}



	//弾丸と接触してるしたらHPを減らす
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}
}

//ドロー
void CObjteki5::Draw()
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
	src.m_right = 187.0f;
	src.m_bottom = 159.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 200.0f + m_x;
	dst.m_bottom = 200.0f + m_y;

	//10番めに登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(10, &src, &dst, c, 0.0f);
}
