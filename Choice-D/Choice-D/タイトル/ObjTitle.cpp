//�g�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"
#include "../GameL/Audio.h"

#include "../GameHead.h"
#include "ObjTitle.h"
#include "../�Q�[�����C��/SceneMain.h"




//�g�p����l�[���X�y�[�X
using namespace GameL;

//GameHead.h�Œ�`�����O���[�o���ϐ��������ŏ�����----------------------
bool m_nazoflag = false;
int m_Nazocnt = 0;
bool m_endflag = false;
int m_tekicnt = 0;
int m_TimeL = 19800;
int m_floor = 1;
float m_Mehp = 20.f;
bool m_clear = false;
bool m_miss = false;//�����ԈႢ�Ȃ�true�ϐ�
float m_clearcnt=100.f;
float m_misscnt=100.f;//�ԈႦ�����̎��Ԃ����炷�\��������ϐ�	
float m_BGM = 0;
bool g_teki = false;
//----------------------------------------------------------------------

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	//�}�E�X�̈ʒu
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 0.0f;
	m_end = false;
	m_sousa = false;
	m_andf = true;
	m_flag = true;
	m_flag2 = true;
	m_flag3 = true;

}

//�A�N�V����
void CObjTitle::Action()
{
	if (m_andf == true)
	{
		m_and += 0.03f;
		if (m_and >= 1)
		{
			m_and = 1.0;
			m_andf = false;
		}

	}



	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//�O���[�o���ϐ����^�C�g���ɗ����炷�ׂď�����-------------------
	m_Nazocnt = 0;
	m_nazoflag = false;
	m_endflag = false;
	m_tekicnt = 0;
	m_floor = 1;
	m_TimeL = 19800;
	m_Mehp = 20.f;
	m_clear = false;
	m_miss = false;
	//---------------------------------------------------------------
}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,m_and };
	////���}�E�X�ʒu�\��
	//wchar_t str[256];
	//swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	//Font::StrDraw(str, 20, 20, 12,c);

	//�O�V�[�����獶�܂��͉E�N���b�N�����������Ă���A
	//�������͂��̃V�[���ɓ����Ĉ�x�ł��N���b�N�������ĂȂ���ԂɈڍs����Ǝ��s�B
	if (m_mou_r == true || m_mou_l == true || m_key_flag == true)
	{
		//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
		//OP�Ɉڍs
		if (m_mou_x > 400 && m_mou_x < 620 && m_mou_y>390 && m_mou_y < 430)
		{
			Font::StrDraw(L"���Q�[�����n�߂�", 400, 400, 32, c);
			//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
			if (m_mou_l == true)
			{

				m_f = true;

			}
		}
		else
		{
			Font::StrDraw(L"�Q�[�����n�߂�", 400, 400, 32, c);
		}
		//�����ʈڍs
		if (m_mou_x > 400 && m_mou_x < 620 && m_mou_y>430 && m_mou_y < 480)
		{

			Font::StrDraw(L"���������", 400, 450, 32, c);
			//�������
			if (m_mou_l == true)
			{

				m_sousa = true;
			}
		}
		else
		{
			Font::StrDraw(L"�������", 400, 450, 32, c);
		}
		//�Q�[���I��
		if (m_mou_x > 400 && m_mou_x < 635 && m_mou_y>493 && m_mou_y < 520)
		{

			Font::StrDraw(L"��Choice���I������", 400, 500, 32, c);
			//�Q�[���I��
			//���O�V�[������N���b�N���������ł�����N���b�N���Ȃ��悤�ɁA
			//���̃V�[���ɓ����Ĉ�x�ł��N���b�N�������ĂȂ���ԂɈڍs���Ȃ���
			//���s�o���Ȃ��悤�ɂ��Ă���B
			if (m_mou_l == true && m_key_flag == true)
			{

				m_end = true;
			}
		}
		else
		{
			Font::StrDraw(L"Choice���I������", 400, 500, 32, c);
		}
		//OP�ڍs�t���O
		if (m_f == true)
		{
			if (m_flag == true)
			{
				Audio::Start(1);
				m_flag = false;
			}
			m_and -= 0.02f;
			if (m_and <= 0)
			{

				Scene::SetScene(new CSceneOP());
				m_f = false;
			}
		}
		else
		{
			m_flag = true;
		}
		//�v���O�����I���t���O
		if (m_end == true)
		{
			if (m_flag2 == true)
			{
				Audio::Start(1);
				m_flag2 = false;
			}

			m_and -= 0.03f;
			if (m_and <= 0)
			{
				exit(4);
			}
		}
		else
		{
			m_flag2 = true;
		}
		//��������ڍs�t���O
		if (m_sousa == true)
		{
			if (m_flag3 == true)
			{
				Audio::Start(1);
				m_flag3 = false;
			}

			m_and -= 0.03f;
			if (m_and <= 0)
			{

				Scene::SetScene(new CSceneSousagamen());
			}

		}
		else
		{
			m_flag3 = true;
		}
	}
	else
	{
		m_key_flag = true;
	}

	RECT_F src;
	RECT_F dst;

	float d[4] = { 1.0f,1.0f,1.0f,m_and };
	//Choice�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 455.0f;
	src.m_bottom = 180.0f;
	
	dst.m_top = 150.0f;
	dst.m_left = 150.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 400.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);



}
