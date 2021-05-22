#pragma once

#define ROW 5  //地图行数
#define COL 5  //地图列数
#define SCREEN_WIDTH 250 //地图宽度
#define SCREEN_HEIGHT 250 //地图高度
#define POINT_SIZE (SCREEN_WIDTH/COL) //每个点在地图中的大小

#define WALL 0  //墙体
#define RODA 1  //路
#define CASE 2  //箱子
#define TPOINT 3 //目标点 
#define PERSON 4 //人物
#define POINT_CASE 5 //箱子和目标点重合

typedef char(*PMAPDATA)[COL];



static char g_map[][COL] = {
#pragma region map 1
	WALL, WALL, WALL, WALL, WALL,
	WALL, TPOINT, RODA, RODA, WALL,
	WALL, RODA, CASE, RODA, WALL,
	WALL, WALL, PERSON, RODA, WALL,
	WALL, WALL, WALL, WALL, WALL,
#pragma endregion map 1
#pragma region map 2
	WALL, WALL, WALL, WALL, WALL,
	WALL, RODA, TPOINT, RODA, WALL,
	WALL, CASE, CASE, RODA, WALL,
	WALL, TPOINT, PERSON, RODA, WALL,
	WALL, WALL, WALL, WALL, WALL,
#pragma endregion map 2
#pragma region map 3
	WALL, WALL, WALL, WALL, WALL,
	WALL, RODA, RODA, TPOINT, WALL,
	WALL, TPOINT, CASE, CASE, WALL,
	WALL, TPOINT, CASE, PERSON, WALL,
	WALL, WALL, WALL, WALL, WALL,
#pragma endregion map 3
};


class BackGround
{
public:
	BackGround();
	bool UpdateMap(int level);
	PMAPDATA GetMap();

private:
	int m_nMapCount = sizeof(g_map)/(COL*ROW); //地图数
	int m_nLevel = 1; //关卡
	char m_pMap[ROW][COL]; //存放地图
};

