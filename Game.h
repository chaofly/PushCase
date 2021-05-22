#pragma once
#include "BackGround.h"
#include <graphics.h>


//资源图片
const char CASE_IMAGE[] = "case.png";
const char CASE_POINT_IMAGE[] = "case_yellow.png";
const char PERSON_IMAGE[] = "person.png";
const char POINT_IMAGE[] = "point.png";
const char WALL_IMAGE[] = "wall.png";


class Game
{
public:
	Game();
	void StartGame(); //开始游戏
	void EndGame(); //结束游戏
	void ShowGame(); //显示游戏
private:
	BackGround m_bk;
	IMAGE m_pCaseImage; //箱子图片
	IMAGE m_pCasePointImage; //箱子到达目的点图片
	IMAGE m_pPersonImage; //人物图片
	IMAGE m_pPointImage; //目的点图片
	IMAGE m_pWallImage; //墙体图片
};

