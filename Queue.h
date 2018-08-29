#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int QUDataType;
typedef struct QueueNode
{
	QUDataType data;
	struct QueueNode *next;

}QueueNode;
typedef struct Queue
{
	QueueNode *front;//∂‘Õ∑
	QueueNode *rear;//∂”Œ≤
	
}Queue;




void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue *pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

