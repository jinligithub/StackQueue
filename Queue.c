#pragma once
#include"Queue.h"
void QueueInit(Queue* pq)//��ʼ�����У��ʼ��ͷ�Ͷ�βʵ��һ��Ķ�Ϊ��
{
	assert(pq != NULL);
	pq->rear = NULL;
	pq->front = NULL;
}
void QueueDestory(Queue* pq)//���ٶ���
{
	assert(pq!=NULL);
	QueueNode *cur = pq->front;//���ȶ���һ��cur�����ͷ��λ��
	while (cur!=NULL)
	{
		QueueNode* next = cur->next;//�ڶ���һ��next����cur����һ��ֵ
		free(cur);//�ͷ�cur
		cur =cur->next;
	}
	pq->front = pq->rear = NULL;//�ö�ͷ�Ͷ�β��Ϊ�գ���ֹҰָ�������
}

QueueNode* BuyQueueNode(QUDataType x)//����һ���µĽ��
{
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	//�����½���Ƿ񴴽��ɹ�
	assert(NewNode);
	//������
	//if (NewNode == NULL)//��㴴��ʧ��
	//{
	//	perror("use malloc for NewNode");
	//	exit(EXIT_FAILURE);
	//}
	NewNode->data = x;//��ֵ
	NewNode->next = NULL;
	return NewNode;

}
//��β��
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq != NULL);
	if (pq->front == NULL)//����Ϊ��
	{

		pq->front = pq->rear = BuyQueueNode(x);
	}
	else//���в�Ϊ��
	{
		QueueNode *node = BuyQueueNode(x);//�����½��
		pq->rear->next = node;//��β��
		pq->rear = node;//��β�����µ�node
	}

}
//ɾ����ͷ���
void QueuePop(Queue* pq)
{
	QueueNode* next = NULL;
	assert(pq != NULL);
	next = pq->front->next;//�ȴ���һ��next������һ��ֵ
	free(pq->front);
	pq->front = next;
	if (next == NULL)
	{
		pq->rear = NULL;
	}
}
//���ض�ͷ����
QUDataType QueueFront(Queue* pq)
{
	assert(pq != NULL);
	return pq->front->data;
}
QUDataType QueueBack(Queue *pq)
{
	return pq->rear->data;
}
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* pq)
{
	assert(pq != NULL);
	return pq->front == NULL ? 0 : 1;//��Ϊ0���ǿ�1
}

//���ض��еĴ�С
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