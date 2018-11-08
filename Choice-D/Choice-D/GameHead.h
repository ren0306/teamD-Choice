#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_TITLE,
	OBJ_HERO,
	OBJ_BULLET,
	OBJ_ENEMY1,
	OBJ_ENEMY2,
	OBJ_ENEMY3,
	OBJ_ENEMY4,
	OBJ_BULLET_ENEMY,
	OBJ_GAMEOVER,
	OBJ_MAIN,
	OBJ_BACKGROUND,
	OBJ_GAMEOVER2,
	OBJ_ED1,
	OBJ_ED3,
	OBJ_ED2,
	OBJ_NAZO,
	OBJ_TENKEY,
	OBJ_TEKI1,
	OBJ_TEKI2,
	OBJ_STG,
	OBJ_STG3,
	OBJ_STG4,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,


};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "�V���[�e�B���O\ObjHero.h"
#include "�V���[�e�B���O\CObjBullet.h"
#include "�V���[�e�B���O\ObjEnemy1.h"
#include "�V���[�e�B���O\ObjEnemy2.h"
#include "�V���[�e�B���O\ObjEnemy3.h"
#include "�V���[�e�B���O\ObjEnemy4.h"
#include "�V���[�e�B���O\CObjBullteEnemy.h"
#include "�^�C�g��\ObjTitle.h"
#include "�Q�[�����C��\ObjMain.h"
#include "GameOver\GAMEOVER1.h"
#include "GameOver\GAME OVER2.h"
#include "�Q�[�����C��\ObjBackGround.h"
#include "ED\ObjED2.h"
#include "ED\ObjED1.h"
#include "ED\ObjED3.h"
#include "�����\ObjTenkey.h"
#include "�V���[�e�B���O\Objteki1.h"
#include "�V���[�e�B���O\Objteki2.h"
#include "�V���[�e�B���O\ObjSTG.h"
#include "�V���[�e�B���O\ObjSTG2.h"
#include "�V���[�e�B���O\ObjSTG3.h"
#include "�V���[�e�B���O\ObjSTG4.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "�Q�[�����C��\SceneMain.h"
#include "�^�C�g��\SceneTitle.h"
#include "GameOver\GameOver.h"
#include "�V���[�e�B���O\ShootingMain.h"
#include "GameOver\GameOver2.h"
#include "ED\SceneED1.h"
#include "ED\SceneED3.h"
#include "ED\SceneED2.h"
#include "�����\SceneNazo.h"
#include "�V���[�e�B���O\SceneSTG.h"
#include "�V���[�e�B���O\SceneSTG3.h"
#include "�V���[�e�B���O\SceneSTG2.h"
#include "�V���[�e�B���O\SceneSTG4.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle
//-----------------------------------------------