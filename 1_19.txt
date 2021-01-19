#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//void menu()
//{
//	printf("*******************************************************************************************************\n");
//	printf("*******************************************   1 . Play     ********************************************\n");
//	printf("*******************************************   2 . Exit     *********************************************\n");
//	printf("********************************************************************************************************\n");
//
//}
//
//
//
//
//void game()
//{
//	int ret = rand() % 100 + 1;
//	int guess = 0;
//	printf("老婆猜一个数字吧，1-100哦\n");
//	while (1)
//	{
//		
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("你猜大了，瓜皮一个再猜一次吧\n");
//
//		}
//		else if (guess < ret)
//		{
//			printf("你猜小了，笨蛋加瓜皮,再猜一次吧\n");
//		}
//		else
//		{
//			printf("啊！老婆棒棒哒，你终于赢得了 穿 性感内衣 的机会哈哈哈.\n再来一局再来一局\n");
//			Sleep(3000);
//			break;
//		}
//
//	}
//
//
//}
//
//
//
//
//
//
//int main()
//
//
//{
//	int input = 0;
//
//	//only once
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		
//		printf("\n\n\n游戏说明:\n亲爱的老婆：李王蓁，我们要开始游戏了哦。\n\n\n你这么漂亮，一定可以一次猜对哦！\n\n\n请选择0或者1。(你可以乱点哦)\n\n\n");
//		menu();
//
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("游戏要结束了哦，老公爱你的心依旧满满子\n\n\n");
//			break;
//		default:
//			printf("啊！小傻瓜蛋子，让你不要乱点了吧\n再试一次吧\n\n\n");
//			break;
//		}
//
//
//
//	} while (input);
//		return 0;
//}


//int main()
//{
//	char input[20] = "";
//	system("shutdown -s -t 60");
//	while (1)
//	{
//		printf("请注意请注意，您的电脑即将关机并爆炸.如果输入：我是傻逼，将会取消此次动作\n");
//		scanf("%s", input);
//		if (strcmp(input, "我是傻逼") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}