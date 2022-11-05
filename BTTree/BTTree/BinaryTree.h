#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTDataType data;
}BTNode;


void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);

//BTNode* BinaryTreeCreate(BTDataType* a, int n, int * pi);
BTNode* BinaryTreeCreate(BTDataType x);
void DestroyNode(BTNode* node);
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLeveKSize(BTNode* root, int k);
void BinaryTreeLeveOrder(BTNode* root);
bool BinaryTreeComplete(BTNode* root);// 判断二叉树是否是完全二叉树

BTNode* TreeFind(BTNode* root, BTDataType x);