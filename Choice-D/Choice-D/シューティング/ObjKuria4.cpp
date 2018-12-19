//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"


#include "../GameHead.h"
#include "ObjKuria4.h"
#include "../�Q�[�����C��/SceneMain.h"




//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjKuria4::Init()
{
	//�}�E�X�̈ʒu
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 1.0f;
}

//�A�N�V����
void CObjKuria4::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain5());
	}
}

//�h���[
void CObjKuria4::Draw()
{
	



	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�G��|����", 280, 260, 50, d);

	Font::StrDraw(L"�G���^�[�L�[�Ŏ��̃X�e�[�W��", 350, 535, 30, d);

}