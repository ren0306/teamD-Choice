//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjED_Roll.h"
#include "../�Q�[�����C��/SceneMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjED_Roll::Init()
{
	m_y = 0;
}

//�A�N�V����
void CObjED_Roll::Action()
{
	float c[4] = { 1,1,1,1 };
	m_y--;
	Font::StrDraw(L"�e�X�g", 250, 400 + m_y, 100, c);














	if (m_y <= -450)
	{
		Scene::SetScene(new CSceneTitle());
	}
}

//�h���[
void CObjED_Roll::Draw()
{
}
