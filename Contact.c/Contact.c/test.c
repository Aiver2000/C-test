#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	EMPTY,
	DESTORY,
	SAVE
};

void menu()
{
	printf("**********************************\n");
	printf("*****  1.add      2.del    *******\n");
	printf("*****  3.search   4.modify *******\n");
	printf("*****  5.show     6.sort   *******\n");
	printf("*****  0.exit     9.save   *******\n");
	printf("**********************************\n");

}



void test()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EMPTY:
			EmptyContact(&con);
			break;
		case SORT:
			SortNameContact(&con);
			break;
		case DESTORY:
			DestoryContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
			


		}
	} while (input);



		
}



int main()
{
	test();
	return 0;
}
//jingtai contact



