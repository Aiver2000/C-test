#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3

//??ʼ??????
void InitBoard(char board[ROW][COL], int row, int col);

//??ӡ????
void DisplayBoard(char board[ROW][COL], int row, int col);

//????????
void PlayMove(int board[ROW][COL], int row, int col);

//????????
void ComputerMove(int board[ROW][COL], int row, int col);

//?ж???Ӯ
char CheckWin(char board[ROW][COL], int row, int col);
