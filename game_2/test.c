#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("*************************************\n");
	printf("**********   * 1.play  *   **********\n");
	printf("**********   * 0.exit  *   **********\n");
	printf("*************************************\n");
}


void game()
{
	//创建棋盘对应的数组
	char mine[ROWS][COLS];		//存放雷的信息
	char show[ROWS][COLS];		//存放的是排查出的信息
		

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');


	//打印棋盘
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);


	//布置雷
	SetMine(mine, ROW, COL, EAZY_COUNT);
	//DisplayBoard(mine, ROW, COL);


	//排查雷
	FineMine(mine, show, ROW, COL);


}



int main()
{

	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入-->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}


	} while (input);
	return 0;
}


