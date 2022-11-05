#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDatatype;


typedef struct QueueNode
{
	QDatatype data;
	struct QueueNode * next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue * pq);

void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, QDatatype x);

void QueuePop(Queue* pq);

QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);

int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);