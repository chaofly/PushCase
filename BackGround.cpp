#include "BackGround.h"

BackGround::BackGround()
{
	UpdateMap(m_nLevel);
}

//根据关卡更新地图, 更新地图失败表示通关
bool BackGround::UpdateMap(int level)
{
	if (level > m_nMapCount || level < 1)
	{
		return false;  
	}
	m_nLevel = level;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			m_pMap[i][j] = g_map[(level - 1)*ROW + i][j];
			if (m_pMap[i][j] == PERSON)
			{
				m_pointPerson = CPoint(j, i);
			}
		}
	}
	return true;
}

//获取地图数据
PMAPDATA BackGround::GetMap()
{
	return m_pMap;
}

//向上移动
void BackGround::MoveUp()
{
	Move(m_pointPerson.m_nX, m_pointPerson.m_nY - 1, UP);
}

//向下移动
void BackGround::MoveDown()
{
	Move(m_pointPerson.m_nX, m_pointPerson.m_nY + 1, DOWN);
}

//向左移动
void BackGround::MoveLeft()
{
	Move(m_pointPerson.m_nX - 1, m_pointPerson.m_nY, LEFT);
}

//向右移动
void BackGround::MoveRight()
{
	Move(m_pointPerson.m_nX + 1, m_pointPerson.m_nY, RIGHT);
}

//移动箱子
bool BackGround::MoveCase(int preX, int preY, DIRECT direct)
{
	int newX = preX;
	int newY = preY;
	switch (direct)
	{
	case UP:
		newY -= 1;
		break;
	case DOWN:
		newY += 1;
		break;
	case LEFT:
		newX -= 1;
		break;
	case RIGHT:
		newX += 1;
		break;
	}
	switch (m_pMap[newY][newX])
	{
	default: //WALL, CASE, POINT_CASE
		return false;
	case TPOINT:
		if (m_pMap[preY][preX]==POINT_CASE)
		{
			m_pMap[preY][preX] = TPOINT;
		}
		else
		{
			m_pMap[preY][preX] = ROAD;
		}
		m_pMap[newY][newX] = POINT_CASE;
		break;
	case ROAD:
		if (m_pMap[preY][preX] == POINT_CASE)
		{
			m_pMap[preY][preX] = TPOINT;
		}
		else
		{
			m_pMap[preY][preX] = ROAD;
		}
		m_pMap[newY][newX] = CASE;
		break;
	}
	return true;
}

//移动
void BackGround::Move(int x, int y, DIRECT direct)
{
	switch (m_pMap[y][x])
	{
	 case ROAD: //ROAD
		//人物和目标点重合在一起
		if (m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] == POINT_PERSON)
		{
			m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = TPOINT;
		}
		else
		{
			m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = ROAD;
		}
		m_pointPerson.m_nX = x;
		m_pointPerson.m_nX = y;
		m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = PERSON;
		break;
	case WALL:
		break;
	case CASE:
		if (MoveCase(x, y, direct))
		{
			if (m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] == POINT_PERSON)
			{
				m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = TPOINT;
			}
			else
			{
				m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = ROAD;
			}
			m_pointPerson.m_nX = x;
			m_pointPerson.m_nX = y;
			m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = PERSON;
		}
		break;
	case POINT_CASE:
		if (MoveCase(x, y, direct))
		{
			if (m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] == POINT_PERSON)
			{
				m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = TPOINT;
			}
			else
			{
				m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = ROAD;
			}
			m_pointPerson.m_nX = x;
			m_pointPerson.m_nX = y;
			m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = POINT_PERSON;
		}
		break;
	case TPOINT:
		if (m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] == POINT_PERSON)
		{
			m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = TPOINT;
		}
		else
		{
			m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = ROAD;
		}
		m_pointPerson.m_nX = x;
		m_pointPerson.m_nX = y;
		m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = POINT_PERSON;
		break;
	}
}
