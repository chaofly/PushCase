#pragma once
#include "BackGround.h"
#include <graphics.h>


//��ԴͼƬ
const TCHAR CASE_IMAGE[] = _T("case.png");
const TCHAR CASE_POINT_IMAGE[] = _T("case_yellow.png");
const TCHAR PERSON_IMAGE[] = _T("person.png");
const TCHAR POINT_IMAGE[] = _T("point.png");
const TCHAR WALL_IMAGE[] = _T("wall.png");
const TCHAR POINT_PERSON_IMAGE[] = _T("point_person.png");


class Game
{
public:
	Game();
	void StartGame(); //��ʼ��Ϸ
	void EndGame(); //������Ϸ
	void ShowGame(); //��ʾ��Ϸ
	void Clear(); //�����Ļ

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
private:
	BackGround m_bk;
	IMAGE m_pCaseImage; //����ͼƬ
	IMAGE m_pCasePointImage; //���ӵ���Ŀ�ĵ�ͼƬ
	IMAGE m_pPersonImage; //����ͼƬ
	IMAGE m_pPointImage; //Ŀ�ĵ�ͼƬ
	IMAGE m_pWallImage; //ǽ��ͼƬ
	IMAGE m_pPersonPointImage; // ���ﵽ��Ŀ�ĵ�ͼƬ
};

