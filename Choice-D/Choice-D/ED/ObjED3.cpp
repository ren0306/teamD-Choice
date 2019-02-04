//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "../�^�C�g��/ObjTitle.h"
#include "../�Q�[�����C��/SceneMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjED3::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//�A�N�V����
void CObjED3::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 470 && m_mou_x < 780 && m_mou_y>520 && m_mou_y < 555)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneED_Roll());
		}
	}

}

//�h���[
void CObjED3::Draw()
{
	
	float c[4] = { 1,1,1,1 };

	//ED�摜��ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"ED3.png", 3, TEX_SIZE_512);

	CObjED3gazou* ED3 = new CObjED3gazou();
	Objs::InsertObj(ED3, OBJ_ED3GAZOU, 20);


	

	float o[4] = { 1.0f,1.0f,0.0f,1.0f };
	Font::StrDraw(L"HAPPY END", 200, 50, 90, o);

	float s[4] = { 0.2f,1.0f,0.9f,1.0f };
	Font::StrDraw(L"������ˁI�����ŒE�o���邱�Ƃ��ł����I", 150, 450, 30, s);

	Font::StrDraw(L"�N���b�N�ŃG���h���[����", 480, 535, 25, c);

}