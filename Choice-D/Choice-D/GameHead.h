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
	OBJ_BULLET_TEKI1,
	OBJ_BULLET_TEKI2,
	OBJ_BULLET_TEKI3,
	OBJ_BULLET_TEKI4,
	OBJ_BULLET_TEKI5,
	OBJ_GAMEOVER,
	OBJ_MAIN,
	OBJ_MAIN2,
	OBJ_MAIN3,
	OBJ_MAIN4,
	OBJ_MAIN5,
	OBJ_BACKGROUND,
	OBJ_BACKGROUND2,
	OBJ_BACKGROUND3,
	OBJ_BACKGROUND4,
	OBJ_BACKGROUND5,
	OBJ_STGBACKGROUND,
	OBJ_GAMEOVER2,
	OBJ_ED1,
	OBJ_ED3,
	OBJ_ED2,
	OBJ_NAZO,
	OBJ_TENKEY,
	OBJ_TENKEY2,
	OBJ_TEKI1,
	OBJ_TEKI2,
	OBJ_TEKI3,
	OBJ_TEKI4,
	OBJ_TEKI5,
	OBJ_STG,
	OBJ_STG2,
	OBJ_STG3,
	OBJ_STG4,
	OBJ_STG5,
	OBJ_BGN,
	OBJ_DOOR,
	OBJ_DOOR2,
	OBJ_SOUSAGAMEN,
	OBJ_GAMEOVERGAMEN,
	OBJ_ED1GAZOU,
	OBJ_ED2GAZOU,
	OBJ_ED3GAZOU,
	OBJ_KURIA,
	OBJ_REMEMBER,
	OBJ_TIME,
	OBJ_KURIA2,
	OBJ_KURIA3,
	OBJ_KURIA4,
	OBJ_KURIA5,
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

extern bool m_f;

//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "�V���[�e�B���O\ObjHero.h"
#include "�V���[�e�B���O\CObjBullet.h"
#include "CObjBulletTeki1.h"
#include "CObjBulletTeki2.h"
#include "CObjBulletTeki3.h"
#include "CObjBulletTeki4.h"
#include "CObjBulletTeki5.h"
#include "�^�C�g��\ObjTitle.h"
#include "�Q�[�����C��\ObjMain.h"
#include "�Q�[�����C��\ObjMain2.h"
#include "ObjMain3.h"
#include "ObjMain4.h"
#include "ObjMain5.h"
#include "GameOver\GAMEOVER1.h"
#include "GameOver\GAME OVER2.h"
#include "�����֌W\ObjBackGround.h"
#include "�����֌W\ObjBackGround2.h"
#include "�����֌W\ObjBackGround3.h"
#include "�����֌W\ObjBackground4.h"
#include "�����֌W\ObjBackground5.h"
#include "STGBackground.h"
#include "ED\ObjED2.h"
#include "ED\ObjED1.h"
#include "ED\ObjED3.h"
#include "�����\ObjTenkey.h"
#include "�����֌W\ObjTenkey2.h"
#include "�V���[�e�B���O\Objteki1.h"
#include "�V���[�e�B���O\Objteki2.h"
#include "�V���[�e�B���O\Objteki3.h"
#include "�V���[�e�B���O\Objteki4.h"
#include "Objteki5.h"
#include "�V���[�e�B���O\ObjSTG.h"
#include "�V���[�e�B���O\ObjSTG2.h"
#include "�V���[�e�B���O\ObjSTG3.h"
#include "�V���[�e�B���O\ObjSTG4.h"
#include "ObjSTG5.h"
#include "�����\ObjBGNazo.h"
#include "ObjBGNazo2.h"
#include "ObjBGNazo3.h"
#include "ObjBGNazo4.h"
#include "ObjBGNazo5.h"
#include "�����֌W\ObjDoor.h"
#include "�����֌W\GameOvergamen.h"
#include "�����֌W\ObjDoor2.h"
#include "�^�C�g��\ObjSousagamen.h"
#include "�����֌W\ObjED1gazou.h"
#include "�����֌W\ObjED2gazou.h"
#include "�����֌W\ObjED3gazou.h"
#include "�V���[�e�B���O\ObjKuria.h"
#include "�����֌W\Remember.h"
#include "�����֌W\TimeLimit.h"
#include "�V���[�e�B���O\ObjKuria2.h"
#include "�V���[�e�B���O\ObjKuria3.h"
#include "�V���[�e�B���O\ObjKuria4.h"
#include "�V���[�e�B���O\ObjKuria5.h"


//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "�Q�[�����C��\SceneMain.h"
#include "�Q�[�����C��\SceneMain2.h"
#include "�Q�[�����C��\SceneMain3.h"
#include "�Q�[�����C��\SceneMain4.h"
#include "�Q�[�����C��\SceneMain5.h"
#include "�^�C�g��\SceneTitle.h"
#include "GameOver\GameOver.h"
#include "GameOver\GameOver2.h"
#include "ED\SceneED1.h"
#include "ED\SceneED2.h"
#include "ED\SceneED3.h"
#include "�����\SceneNazo.h"
#include "�����\SceneNazo2.h"
#include "�V���[�e�B���O\SceneSTG.h"
#include "�V���[�e�B���O\SceneSTG2.h"
#include "�V���[�e�B���O\SceneSTG3.h"
#include "�V���[�e�B���O\SceneSTG4.h"
#include "SceneSTG5.h"
#include "�^�C�g��\SceneSousagamen.h"
#include "�V���[�e�B���O\SceneKuria.h"
#include "�V���[�e�B���O\SceneKuria2.h"
#include "�V���[�e�B���O\SceneKuria3.h"
#include "�V���[�e�B���O\SceneKuria4.h"
#include "�V���[�e�B���O\SceneKuria5.h"


//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle
//-----------------------------------------------