#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("***********************************************\n");
	printf("****************   1.PLAY     *****************\n");
	printf("****************   2.EXIT     *****************\n");
	printf("***********************************************\n");
}


void game()
{
	char ret = 0;
	char board[ROW][COL]; //���ݵĴ洢---��ά����
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);


		//��������
		ComputerMove(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
		printf(" ��Ӯ�� \n");
	else if (ret == '#')
		printf(" ������ \n");
	else if (ret == 'Q')
		printf(" ƽ�� \n");
	DisplayBoard(board, ROW, COL);


}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("������->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
				break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��!\n");
			break;
		}

	} while (input);
	return 0;
}
