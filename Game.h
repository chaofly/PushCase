#pragma once
#include "BackGround.h"
#include <graphics.h>


//��ԴͼƬ
const char CASE_IMAGE[] = "case.png";
const char CASE_POINT_IMAGE[] = "case_yellow.png";
const char PERSON_IMAGE[] = "person.png";
const char POINT_IMAGE[] = "point.png";
const char WALL_IMAGE[] = "wall.png";


class Game
{
public:
	Game();
	void StartGame(); //��ʼ��Ϸ
	void EndGame(); //������Ϸ
	void ShowGame(); //��ʾ��Ϸ
private:
	BackGround m_bk;
	IMAGE m_pCaseImage; //����ͼƬ
	IMAGE m_pCasePointImage; //���ӵ���Ŀ�ĵ�ͼƬ
	IMAGE m_pPersonImage; //����ͼƬ
	IMAGE m_pPointImage; //Ŀ�ĵ�ͼƬ
	IMAGE m_pWallImage; //ǽ��ͼƬ
};

