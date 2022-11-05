#include "stack.h"



void StackInit(Stack * pstack, size_t capacity)
{
	assert(pstack);
	pstack->capacity = capacity;
	pstack->array = (StackDataType*)malloc(2*sizeof(StackDataType));
	assert(pstack->array);
	pstack->size = 0;
}




void StackDestory(Stack* pstack)
{
	assert(pstack);
	if (pstack->array)
	{
		free(pstack->array);
		pstack->array = NULL;
		pstack->size = 0;
		pstack->capacity = 0;

	}

}
void CheckCapacity(Stack* pstack)
{
	assert(pstack);
	if (pstack->size == pstack->capacity)
	{
		pstack->capacity *= Capacity;
		pstack->array = (StackDataType*)realloc(pstack->array, pstack->capacity*sizeof(StackDataType));
	}
}

void StackPush(Stack* pstack, StackDataType x)
{
	assert(pstack);
	CheckCapacity(pstack);
	pstack->array[pstack->size] = x;
	pstack->size++;
}
void StackPop(Stack* pstack)
{
	assert(pstack || pstack->size);
	pstack->size--;


}

void StackPrint(Stack* pstack)
{
	assert(pstack);
	while (pstack->size--)
	{
		printf("%d  ", pstack->array[pstack->size]);
	}
	printf("\n");

}


StackDataType StackTop(Stack* pstack)
{
	assert(pstack);
	if (pstack->array)
	{
		return pstack->array[pstack->size - 1];
	}
	return -1;
}


int StackSize(Stack* pstack)
{
	assert(pstack);
	if (pstack->array)
	{
		return pstack->size;
	}
	return -1;
}
int StackEmpty(Stack* pstack)
{
	assert(pstack);
	if (StackSize(pstack) == -1)
	{
		return 1;
	}
	return -1;
}
