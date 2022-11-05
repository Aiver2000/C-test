#include <stdio.h>
#include <stdlib.h>
#include <time.h>`


#define EAZY_COUNT 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

//≥ı ºªØ∆Â≈Ã
void Initboard(char[ROWS][COLS], int rows, int cols, char set);

//¥Ú”°∆Â≈Ã
void Displayboard(char[ROWS][COLS], int row, int col);

//≤º÷√¿◊
void SetMine(char[ROWS][COLS], int row, int col, int count);

//≈≈≤È¿◊
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);