#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define Capacity 2

typedef int StackDataType;

typedef struct Stack
{
	StackDataType *array;
	size_t size;
	size_t capacity;
}Stack;

void StackInit(Stack * pstack, size_t capacity);
void StackDestory(Stack* pstack);
void CheckCapacity(Stack* pstack);
void StackPush(Stack* pstack, StackDataType x);
void StackPop(Stack* pstack);
void StackPrint(Stack* pstack);
StackDataType StackTop(Stack* pstack);
int StackSize(Stack* pstack);
int StackEmpty(Stack* pstack);
