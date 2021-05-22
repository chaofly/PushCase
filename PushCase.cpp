// PushCase.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <conio.h>
#include "Game.h"
using namespace std;

int main()
{
	Game g;
	g.StartGame();
	while (true)
	{
		char ch = _getch();
		switch(ch)
		{
			case 'W':
			case 'w':
				break;
			case 'S':
			case 's':
				break;
			case 'A':
			case 'a':
				break;
			case 'D':
			case 'd':
				break;
		}
	}
	return 0;
}

