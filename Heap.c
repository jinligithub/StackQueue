#include"Heap.h"
void Swap(HPDataType* x1, HPDataType* x2)
{
	HPDataType x = *x1;
	*x1 = *x2;
	*x2 = x;
}
void AdjustDown(HPDataType*data, int n, int root)//���µ�������
{
	int parent = root;
	int child = parent * 2 + 1;


	while (child < n)
	{
		//ѡȡ���Һ����нϴ���Ǹ���Ĭ��Ϊ����
		if ((data[child]<data[child + 1])
			&&(child+1<n))    //child+1<n��ֹ����
		{
			child++;
		}
		if (data[child] > data[parent])//�ȽϺ��Ӻ͸��׵Ĵ�С��
		{
			Swap(&data[child], &data[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap* hp,HPDataType*data,int n)//�ѵĳ�ʼ��
{
	assert(hp);
	int i = 0;
	hp->data = (HPDataType*)malloc(sizeof(HPDataType)*n);//���������С���ֽ�
	hp->sz = n;
	hp->capacity = n;
	for ( i = 0; i < n; i++)//���ѵ����鸳ֵ
	{
		hp->data[i] = data[i];
	}
	for (i = (n - 2) / 2; i >= 0; i--)//�ҵ���Ҷ�ӵ����һ���ڵ㣬�Ѵ�����ϵ���С������
	{
		AdjustDown(hp->data, hp->sz, i);//
	}

}
void HeapDestory(Heap* hp)//�ѵ�����
{
	assert(hp);
	free(hp->data);
	hp->data = NULL; 
	hp->sz = hp->capacity = 0;
}
void AdjustUp(HPDataType*data, int n, int child)//���ϵ���������HeapPop()���ú��Ӻ͸��ױȽϴ�С,��С�����ϵ���
{
	assert(data);
	int parent = (child-1)/2;
	while (child > 0)
	{
		if (data[parent]<data[child])//������С�ں���ʱ�����н���
		{
			Swap(&data[parent], &data[child]);
			child = parent;//�ı亢�ӵĴ�С
			parent = (child - 2) / 2;//�ı丸�׵Ĵ�С

		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HPDataType x)//�ѵĲ���
{
	assert(hp);
	if (hp->sz == hp->capacity)//���ѵĴ�С���������Ĵ�С����Ҫ����
	{
		hp->capacity *= 2;
		hp->data = (HPDataType*)realloc(hp->data,sizeof(HPDataType)*hp->capacity);//���ٿռ�
	}
	hp->data[hp->sz] = x;
	hp->sz++;//������1
	AdjustUp(hp->data, hp->sz,hp->sz-1);//���ϵ��������Ѵ�ĵ���ȥ��С�ķ��±�
}
void HeapPop(Heap* hp)//�ѵ�ɾ��,�ѶѶ����ݺ����һ�����ݽ������ٰѶԶ��������µ���
{
	assert(hp);
	Swap(&hp->data[0], &hp->data[hp->sz - 1]);
	HPDataType* cur = &hp->data[hp->sz - 1];
	hp->sz--;
	AdjustDown(hp->data, hp->sz, 0);
	return *cur;
}
HPDataType* HeapTop(Heap*hp)//��ȡ�Ѷ�������,
{
	assert(hp);
	return hp->data[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->sz;
}
int HeapEmpty(Heap* hp)//��Ϊ0���ǿ�1
{
	return hp->sz == 0 ? 0 : 1;//���ַ�����
}
void PrintHeap(Heap* hp)//��ӡ����
{
	assert(hp);
	for (int i = 0; i < hp->sz; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}
void HeapSort(Heap*hp)//ð��������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hp->sz - 1; i++)
	{
		int flag = 0;//�Ż����
		for (j = 0; j < hp->sz - i - 1; j++)//ѭ������
		{
			if (hp->data[j] < hp->data[j + 1])//�Ƚϴ���
			{
				HPDataType tmp = hp->data[j];
				hp->data[j] = hp->data[j + 1];
				hp->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)//������û�н���ʱ��˵���������
			return;
	}
}
void TestHeap()
{
	int arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;
	int pos = 0;
	HeapInit(&hp,arr,9);
	PrintHeap(&hp);
	//HeapPush(&hp ,120);
	//PrintHeap(&hp);


	HeapPop( &hp);
	PrintHeap(&hp);

	pos=HeapTop(&hp);
	PrintHeap(&hp);
	printf("%d \n", pos);
	pos=HeapSize(& hp);
	printf("%d \n", pos);
	pos = HeapEmpty(&hp);
	printf("%d \n", pos);
	HeapSort(&hp);
	PrintHeap(&hp);

	//HeapPush(&hp);

}