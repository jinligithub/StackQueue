#pragma once
#include"Queue.h"
void QueueInit(Queue* pq)//初始化队列，最开始队头和队尾实在一起的都为空
{
	assert(pq != NULL);
	pq->rear = NULL;
	pq->front = NULL;
}
void QueueDestory(Queue* pq)//销毁队列
{
	assert(pq!=NULL);
	QueueNode *cur = pq->front;//，先定义一个cur保存队头的位置
	while (cur!=NULL)
	{
		QueueNode* next = cur->next;//在定义一个next保存cur的下一个值
		free(cur);//释放cur
		cur =cur->next;
	}
	pq->front = pq->rear = NULL;//让队头和队尾都为空，防止野指针的生成
}

QueueNode* BuyQueueNode(QUDataType x)//创造一个新的结点
{
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	//断言新结点是否创建成功
	assert(NewNode);
	//方法二
	//if (NewNode == NULL)//结点创建失败
	//{
	//	perror("use malloc for NewNode");
	//	exit(EXIT_FAILURE);
	//}
	NewNode->data = x;//赋值
	NewNode->next = NULL;
	return NewNode;

}
//队尾进
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq != NULL);
	if (pq->front == NULL)//队列为空
	{

		pq->front = pq->rear = BuyQueueNode(x);
	}
	else//队列不为空
	{
		QueueNode *node = BuyQueueNode(x);//创建新结点
		pq->rear->next = node;//队尾进
		pq->rear = node;//队尾等于新的node
	}

}
//删除队头结点
void QueuePop(Queue* pq)
{
	QueueNode* next = NULL;
	assert(pq != NULL);
	next = pq->front->next;//先创建一个next保存下一个值
	free(pq->front);
	pq->front = next;
	if (next == NULL)
	{
		pq->rear = NULL;
	}
}
//返回队头数据
QUDataType QueueFront(Queue* pq)
{
	assert(pq != NULL);
	return pq->front->data;
}
QUDataType QueueBack(Queue *pq)
{
	return pq->rear->data;
}
//判断队列是否为空
int QueueEmpty(Queue* pq)
{
	assert(pq != NULL);
	return pq->front == NULL ? 0 : 1;//空为0，非空1
}

//返回队列的大小
int QueueSize(Queue* pq)
{
	assert(pq != NULL);
	QueueNode* cur = pq->front;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void testQueue()
{
	Queue q;
	int pos = 0;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}