//�g�p����w�b�_�[�t�@�C��
#include "../GameL\DrawFont.h"
#include "../GameL\WinInputs.h"

#include "../GameHead.h"
#include "GAME OVER2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGAMEOVER2::Init()
{

}

//�A�N�V����
void CObjGAMEOVER2::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
	}
}

//�h���[
void CObjGAMEOVER2::Draw()
{
	//���������
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };
	Font::StrDraw(L"GAME OVER", 270, 50, 50, c);
	float m[4] = { 0.5f,0.5f,0.5f,1.0f };

	Font::StrDraw(L"�G�ɓ|���ꂽ", 300, 400, 30, m);
	float s[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�G���^�[�L�[�Ń^�C�g����", 350, 535, 30, s);

	Font::StrDraw(L"����Ă��܂���", 325, 250, 20, s);

}