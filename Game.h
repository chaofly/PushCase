#pragma once
#include "BackGround.h"
#include <graphics.h>


//资源图片
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
	void StartGame(); //开始游戏
	void EndGame(); //结束游戏
	void ShowGame(); //显示游戏
	void Clear(); //清空屏幕

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
private:
	BackGround m_bk;
	IMAGE m_pCaseImage; //箱子图片
	IMAGE m_pCasePointImage; //箱子到达目的点图片
	IMAGE m_pPersonImage; //人物图片
	IMAGE m_pPointImage; //目的点图片
	IMAGE m_pWallImage; //墙体图片
	IMAGE m_pPersonPointImage; // 人物到达目的点图片
};

