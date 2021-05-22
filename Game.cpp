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
	loadimage(&m_pPersonPointImage, POINT_PERSON_IMAGE, SCREEN_WIDTH / COL, SCREEN_HEIGHT / ROW, true);
}

void Game::StartGame()
{
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);	// ������ͼ����
	putimage(0, 0, &m_pPersonImage);
	ShowGame();
}

void Game::EndGame()
{
	TCHAR s[] = _T("Game Over !!!");
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 24;						// ��������߶�Ϊ 48
	_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	outtextxy(SCREEN_WIDTH/3, SCREEN_HEIGHT/2, s);
	getchar();
	closegraph(); // �رջ�ͼ����
}

void Game::ShowGame()
{
	//Clear();
	auto pBKData = m_bk.GetMap();
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{	
			switch (pBKData[i][j])
			{
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
			case POINT_PERSON:
				putimage(j*POINT_SIZE, i*POINT_SIZE, &m_pPersonPointImage);
				break;
			default: //ROAD
				setfillcolor(BLACK);
				solidrectangle(j*POINT_SIZE, i*POINT_SIZE, (j+1)*POINT_SIZE, (i+1)*POINT_SIZE);
				break;
			}
		}
	}
	if (m_bk.CheckResult())
	{
		if (!m_bk.UpdateMap())
		{
			EndGame();
		}
		ShowGame();
	}

}

void Game::Clear()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			setfillcolor(BLACK);
			solidrectangle(j*POINT_SIZE, i*POINT_SIZE, (j + 1)*POINT_SIZE, (i + 1)*POINT_SIZE);
		}
	}
}

void Game::MoveUp()
{
	m_bk.MoveUp();
}

void Game::MoveDown()
{
	m_bk.MoveDown();
}

void Game::MoveLeft()
{
	m_bk.MoveLeft();
}

void Game::MoveRight()
{
	m_bk.MoveRight();
}
