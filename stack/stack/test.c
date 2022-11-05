#include"stack.h"




void test1()
{
	Stack stack;
	StackInit(&stack, Capacity);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPop(&stack);
	StackPush(&stack, 4);
	StackPush(&stack, 5);
	StackPush(&stack, 6);


	StackPop(&stack);

	StackPrint(&stack);

	StackDestory(&stack);
}









void main()
{
	test1();
}