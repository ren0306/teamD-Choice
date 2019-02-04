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
void CObjED1::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//�A�N�V����
void CObjED1::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 450 && m_mou_x < 755 && m_mou_y>525 && m_mou_y < 560)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneED_Roll());
		}
	}

}

//�h���[
void CObjED1::Draw()
{
	float c[4] = { 1,1,1,1 };
	
	//ED�摜��ǂݍ���0�Ԃɓo�^
	Draw::LoadImage(L"ED1.png", 3, TEX_SIZE_512);

	CObjED1gazou* ED1 = new CObjED1gazou();
	Objs::InsertObj(ED1, OBJ_ED1GAZOU, 20);

	float o[4] = { 0.5f,0.0f,1.0f,1.0f };
	Font::StrDraw(L"BAD END", 250, 50, 90, o);

	float a[4] = { 0.5f,0.5f,0.5f,1.0f };
	Font::StrDraw(L"�G�Ɛ���Ă����炽������̓G���W�܂��Ă��ĕ߂炦��ꂽ", 70, 450, 25, a);
	Font::StrDraw(L"�m�[�_���[�W�ŃN���A����ƁE�E�H", 70, 480, 25, a);

	float s[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�N���b�N�ŃG���h���[����", 460, 535, 25, s);
}
