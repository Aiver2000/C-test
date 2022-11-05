#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h" 




int main()
{
	BTNode* A = BinaryTreeCreate('A');
	BTNode* B = BinaryTreeCreate('B');
	BTNode* C = BinaryTreeCreate('C');
	BTNode* D = BinaryTreeCreate('D');
	BTNode* E = BinaryTreeCreate('E');
	BTNode* F = BinaryTreeCreate('F');

	A->_left = B;
	A->_right = C;
	B->_left = D;
	C->_left = E;
	C->_right = F;
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");



	printf("TreeSize:%d\n", BinaryTreeSize(A));
	printf("TreeSize:%d\n", BinaryTreeSize(A));
	printf("TreeLeafSize:%d\n", BinaryTreeLeafSize(A));
	return 0;

}




