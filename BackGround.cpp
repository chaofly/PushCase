#include "BackGround.h"

BackGround::BackGround()
{
	UpdateMap();
}

//���ݹؿ����µ�ͼ, ���µ�ͼʧ�ܱ�ʾͨ��
bool BackGround::UpdateMap()
{
	m_nSucess = 0;
	m_nLevel += 1;
	if (m_nLevel > m_nMapCount || m_nLevel < 1)
	{
		return false;  
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			m_pMap[i][j] = g_map[(m_nLevel - 1)*ROW + i][j];
			if (m_pMap[i][j] == PERSON)
			{
				m_pointPerson = CPoint(j, i);
			}
		}
	}
	return true;
}

//��ȡ��ͼ����
PMAPDATA BackGround::GetMap()
{
	return m_pMap;
}

//�����ƶ�
void BackGround::MoveUp()
{
	Move(m_pointPerson.m_nX, m_pointPerson.m_nY - 1, UP);
}

//�����ƶ�
void BackGround::MoveDown()
{
	Move(m_pointPerson.m_nX, m_pointPerson.m_nY + 1, DOWN);
}

//�����ƶ�
void BackGround::MoveLeft()
{
	Move(m_pointPerson.m_nX - 1, m_pointPerson.m_nY, LEFT);
}

//�����ƶ�
void BackGround::MoveRight()
{
	Move(m_pointPerson.m_nX + 1, m_pointPerson.m_nY, RIGHT);
}

//�ƶ�����
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
			m_nSucess -= 1;
		}
		else
		{
			m_pMap[preY][preX] = ROAD;
		}
		m_pMap[newY][newX] = POINT_CASE;
		m_nSucess += 1;
		break;
	case ROAD:
		if (m_pMap[preY][preX] == POINT_CASE)
		{
			m_pMap[preY][preX] = TPOINT;
			m_nSucess -= 1;
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

//�����Ϸ�Ƿ��Ѿ�ͨ��
bool BackGround::CheckResult()
{
	if (m_nSucess >= m_nLevel)
	{
		return true;
	}
	return false;
}

//�ƶ�
void BackGround::Move(int x, int y, DIRECT direct)
{
	switch (m_pMap[y][x])
	{
	 case ROAD: //ROAD
		//�����Ŀ����غ���һ��
		if (m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] == POINT_PERSON)
		{
			m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = TPOINT;
		}
		else
		{
			m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = ROAD;
		}
		m_pointPerson.m_nX = x;
		m_pointPerson.m_nY = y;
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
			m_pointPerson.m_nY = y;
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
			m_pointPerson.m_nY = y;
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
		m_pointPerson.m_nY = y;
		m_pMap[m_pointPerson.m_nY][m_pointPerson.m_nX] = POINT_PERSON;
		break;
	}
}
