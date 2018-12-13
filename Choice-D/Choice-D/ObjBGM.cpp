//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include "GameL/Audio.h"
#include "ObjBGM.h"
#include "ゲームメイン/SceneMain.h"




//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBGM::Init()
{
	//マウスの位置
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//アクション
void CObjBGM::Action()
{
	//Audio::LoadAudio(0, L"titleBGM.wav", SOUND_TYPE::BACK_MUSIC);
	//BGMを登録
	//Audio::LoadAudio(1, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//音楽情報の読み込み
	//Audio::LoadAudio(2, L"STGBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//Audio::Start(0);
	if (m_BGM == 1)
	{
		//Audio::Start(1);
	}
	float k[4] = { 0.3,0.6,0.6,0 };
	float c[4] = { 1,1,1,0 };

	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

//ドロー
void CObjBGM::Draw()
{



}