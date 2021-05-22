#include "Game.h"
#include "BackGround.h"
#include <graphics.h>

Game::Game()
{
	loadimage(&m_pCaseImage, _T(CASE_IMAGE), SCREEN_WIDTH/COL, SCREEN_HEIGHT/ROW, true);
	loadimage(&m_pCasePointImage, _T(CASE_POINT_IMAGE), SCREEN_WIDTH / COL, SCREEN_HEIGHT / ROW, true);
	loadimage(&m_pPersonImage, _T(PERSON_IMAGE), SCREEN_WIDTH / COL, SCREEN_HEIGHT / ROW, true);
	loadimage(&m_pPointImage, _T(POINT_IMAGE), SCREEN_WIDTH / COL, SCREEN_HEIGHT / ROW, true);
	loadimage(&m_pWallImage, _T(WALL_IMAGE), SCREEN_WIDTH / COL, SCREEN_HEIGHT / ROW, true);
}

void Game::StartGame()
{
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);	// ������ͼ����
	ShowGame();
}

void Game::EndGame()
{
	closegraph(); // �رջ�ͼ����
}

void Game::ShowGame()
{
	auto pBKData = m_bk.GetMap();
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{

		}
	}
}
