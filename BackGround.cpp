#include "BackGround.h"

BackGround::BackGround()
{
	UpdateMap(m_nLevel);
}

//���ݹؿ����µ�ͼ
void BackGround::UpdateMap(int level)
{
	if (level > m_nMapCount || level < 1)
	{
		level = 1;
	}
	m_nLevel = level;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			m_pMap[i][j] = g_map[(level - 1)*ROW + i][j];
		}
	}
}

//��ȡ��ͼ����
PMAPDATA BackGround::GetMap()
{
	return m_pMap;
}
