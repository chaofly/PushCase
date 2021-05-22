#pragma once

#define ROW 5  //地图行数
#define COL 5  //地图列数
#define SCREEN_WIDTH 250 //地图宽度
#define SCREEN_HEIGHT 250 //地图高度
#define POINT_SIZE (SCREEN_WIDTH/COL) //每个点在地图中的大小

#define WALL 0  //墙体
#define ROAD 1  //路
#define CASE 2  //箱子
#define TPOINT 3 //目标点 
#define PERSON 4 //人物
#define POINT_CASE 5 //箱子和目标点重合
#define POINT_PERSON 6 //人物和目标点重合

#define DIRECT char //方向
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef char(*PMAPDATA)[COL];



static char g_map[][COL] = {
#pragma region map 1
	WALL, WALL, WALL, WALL, WALL,
	WALL, TPOINT, ROAD, ROAD, WALL,
	WALL, ROAD, CASE, ROAD, WALL,
	WALL, WALL, PERSON, ROAD, WALL,
	WALL, WALL, WALL, WALL, WALL,
#pragma endregion map 1
#pragma region map 2
	WALL, WALL, WALL, WALL, WALL,
	WALL, ROAD, TPOINT, ROAD, WALL,
	WALL, CASE, CASE, ROAD, WALL,
	WALL, TPOINT, PERSON, ROAD, WALL,
	WALL, WALL, WALL, WALL, WALL,
#pragma endregion map 2
#pragma region map 3
	WALL, WALL, WALL, WALL, WALL,
	WALL, ROAD, ROAD, TPOINT, WALL,
	WALL, TPOINT, CASE, CASE, WALL,
	WALL, TPOINT, CASE, PERSON, WALL,
	WALL, WALL, WALL, WALL, WALL,
#pragma endregion map 3
};

class CPoint
{
public:
	int m_nX; //x坐标
	int m_nY; //y坐标
	CPoint(int x=0, int y=0):m_nX(x), m_nY(y){}
};


class BackGround
{
public:
	BackGround();
	bool UpdateMap();
	PMAPDATA GetMap();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	bool MoveCase(int preX, int preY, DIRECT direct);
	bool CheckResult();
private:
	void Move(int x, int y, DIRECT direct);
private:
	int m_nMapCount = sizeof(g_map)/(COL*ROW); //地图数
	int m_nLevel = 0; //关卡
	char m_pMap[ROW][COL]; //存放地图
	CPoint m_pointPerson; //人物所在位置
	int m_nSucess = 0; //几个箱子已经到了目的点
};

