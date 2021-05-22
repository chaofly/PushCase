#include "Game.h"
#include "BackGround.h"
#include <graphics.h>
#include <stdio.h>

Game::Game()
{
	loadimage(&m_pCaseImage, CASE_IMAGE, SCREEN_WIDTH/COL, SCREEN_HEIGHT/ROW, true);
	loadimage(&m_pCasePointImage, CASE_POINT_IMAGE, SCREEN_WIDTH / COL, SCREEN_HEIGHT / ROW, true);
	loadimage(&m_pPersonImage, PERSON_IMAGE, SCREEN_WIDTH / COL, SCREEN_HEIGHT / ROW, true);
	loadimage(&m_pPointImage, POINT_IMAGE, SCREEN_WIDTH / COL, SCREEN_HEIGHT / ROW, true);
	loadimage(&m_pWallImage, WALL_IMAGE, SCREEN_WIDTH / COL, SCREEN_HEIGHT / ROW, true);
}

void Game::StartGame()
{
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);	// 创建绘图窗口
	putimage(0, 0, &m_pPersonImage);
	ShowGame();
}

void Game::EndGame()
{
	closegraph(); // 关闭绘图窗口
}

void Game::ShowGame()
{
	auto pBKData = m_bk.GetMap();
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{	
			switch (pBKData[i][j])
			{
			default:
				break;
			case PERSON:
				putimage(j*POINT_SIZE, i*POINT_SIZE, &m_pPersonImage);
				break;
			case CASE:
				putimage(j*POINT_SIZE, i*POINT_SIZE, &m_pCaseImage);
				break;
			case TPOINT:
				putimage(j*POINT_SIZE, i*POINT_SIZE, &m_pPointImage);
				break;
			case POINT_CASE:
				putimage(j*POINT_SIZE, i*POINT_SIZE, &m_pCasePointImage);
				break;
			case WALL:
				putimage(j*POINT_SIZE, i*POINT_SIZE, &m_pWallImage);
				break;
			}
		}
	}
}
