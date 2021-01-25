#include <stdio.h>
#include <stdlib.h>
#include <time.h>`


#define EAZY_COUNT 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

//初始化棋盘
void Initboard(char[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void Displayboard(char[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char[ROWS][COLS], int row, int col, int count);

//排查雷
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);