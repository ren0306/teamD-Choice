//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "../GameL\DrawTexture.h"
#include "../GameL\SceneObjManager.h"
#include "../GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "ShootingMain.h"
#include "../GameHead.h"

//�R���X�g���N�^
CShootingMain::CShootingMain()
{

}

//�f�X�g���N�^
CShootingMain::~CShootingMain()
{

}

//�Q�[�����C�����������\�b�h
void CShootingMain::InitScene()
{
	/*
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMGameMain.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMBoss.wav", BACK_MUSIC);

	Audio::LoadAudio(2, L"SETrigger.wav", EFFECT);
	Audio::LoadAudio(3, L"SEBom.wav", EFFECT);

	//�{�����[����1.5�ɑ��₷
	float v = Audio::VolumeMaster(1.5);

	//���y�X�^�[�g
	Audio::Start(0);
	*/

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"hero.png", 1, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���2�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"Enemy2.png", 2, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)
	//Draw::LoadImage(L"BossBack.png", 1, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();   //��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 10);//�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	/*
	//�w�i�I�u�W�F�N�g�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 5);
	*/

	//�^�C��������
	m_time = 0;
}

//�Q�[�����C�����s�����\�b�h
void CShootingMain::Scene()
{
	m_time++;

	if (m_time == 1)
	{
		CObjEnemy1* obj;
		obj = new CObjEnemy1(400, 200);
		Objs::InsertObj(obj, OBJ_ENEMY1, 50);
	}

	/*
	m_time++;

	if (m_time == 30)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 80)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 120)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 200);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 200)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(799.0f, 100);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 500);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 400)
	{
		CObjEnemy* obj1;
		obj1 = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj1, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 400);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);
	}
	else if (m_time == 550)
	{
		CObjEnemy* obj1;
		obj1 = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj1, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 300);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);
	}
	else if (m_time == 680)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 250);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 750)
	{
		CObjAttackEnemy* obj;
		obj = new CObjAttackEnemy(799, 300);
		Objs::InsertObj(obj, OBJ_ATTACK_ENEMY, 50);
	}
	else if (m_time == 1000)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i*32);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}
	}
	else if (m_time == 1100)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i * 32 + 64);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}
	}
	else if (m_time == 1200)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i * 32);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}
	}
	else if (m_time == 1300)
	{
		CObjSinEnemy* obj1;
		for (int i = 0; i < 15; i++)
		{
			obj1 = new CObjSinEnemy(799, i * 32);
			Objs::InsertObj(obj1, OBJ_SIN_ENEMY, 50);
		}

		CObjDiffusionEnemy* obj2;
		obj2 = new CObjDiffusionEnemy(799, 300);
		Objs::InsertObj(obj2, OBJ_DIFFUSION_ENEMY, 50);
	}
	else if (m_time == 1500)
	{
		CObjHomingEnemy* obj;
		obj = new CObjHomingEnemy(799, 500);
		Objs::InsertObj(obj, OBJ_HOMING_ENEMY, 50);
	}
	else if (m_time == 2000)
	{
		//���y�`�F���W
		Audio::Stop(0); //0�ԋȂ��X�g�b�v
		Audio::Start(1);//1�ԋȂ��X�^�[�g

		CObjBoss* obj;
		obj = new CObjBoss(300, 100);
		Objs::InsertObj(obj, OBJ_BOSS_ENEMY, 50);
	}
	*/
}
