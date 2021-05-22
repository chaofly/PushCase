#pragma once

#define ROW 5  //��ͼ����
#define COL 5  //��ͼ����
#define SCREEN_WIDTH 250 //��ͼ���
#define SCREEN_HEIGHT 250 //��ͼ�߶�
#define POINT_SIZE (SCREEN_WIDTH/COL) //ÿ�����ڵ�ͼ�еĴ�С

#define WALL 0  //ǽ��
#define ROAD 1  //·
#define CASE 2  //����
#define TPOINT 3 //Ŀ��� 
#define PERSON 4 //����
#define POINT_CASE 5 //���Ӻ�Ŀ����غ�
#define POINT_PERSON 6 //�����Ŀ����غ�

#define DIRECT char //����
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
	int m_nX; //x����
	int m_nY; //y����
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
	int m_nMapCount = sizeof(g_map)/(COL*ROW); //��ͼ��
	int m_nLevel = 0; //�ؿ�
	char m_pMap[ROW][COL]; //��ŵ�ͼ
	CPoint m_pointPerson; //��������λ��
	int m_nSucess = 0; //���������Ѿ�����Ŀ�ĵ�
};

