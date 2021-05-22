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
		}
	}
	return true;
}

//获取地图数据
PMAPDATA BackGround::GetMap()
{
	return m_pMap;
}
