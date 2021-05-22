#pragma once

#define ROW 5  //��ͼ����
#define COL 5  //��ͼ����
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

#define WALL 0  //ǽ��
#define RODA 1  //·
#define CASE 2  //����
#define POINT 3 //Ŀ��� 
#define PERSON 4 //����
#define POINT_CASE 5 //���Ӻ�Ŀ����غ�

typedef char(*PMAPDATA)[COL];



static char g_map[][COL] = {
#pragma region map 1
	WALL, WALL, WALL, WALL, WALL,
	WALL, POINT, RODA, RODA, WALL,
	WALL, RODA, CASE, RODA, WALL,
	WALL, WALL, PERSON, RODA, WALL,
	WALL, WALL, WALL, WALL, WALL,
#pragma endregion map 1
#pragma region map 2
	WALL, WALL, WALL, WALL, WALL,
	WALL, RODA, POINT, RODA, WALL,
	WALL, CASE, CASE, RODA, WALL,
	WALL, POINT, PERSON, RODA, WALL,
	WALL, WALL, WALL, WALL, WALL,
#pragma endregion map 2
#pragma region map 3
	WALL, WALL, WALL, WALL, WALL,
	WALL, RODA, RODA, POINT, WALL,
	WALL, POINT, CASE, CASE, WALL,
	WALL, POINT, CASE, PERSON, WALL,
	WALL, WALL, WALL, WALL, WALL,
#pragma endregion map 3
};


class BackGround
{
public:
	BackGround();
	void UpdateMap(int level);
	PMAPDATA GetMap();

private:
	int m_nMapCount = sizeof(g_map)/(COL*ROW); //��ͼ��
	int m_nLevel = 1; //�ؿ�
	char m_pMap[ROW][COL]; //��ŵ�ͼ
};

