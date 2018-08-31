#include"Heap.h"
void Swap(HPDataType* x1, HPDataType* x2)
{
	HPDataType x = *x1;
	*x1 = *x2;
	*x2 = x;
}
void AdjustDown(HPDataType*data, int n, int root)//向下调整方法
{
	int parent = root;
	int child = parent * 2 + 1;


	while (child < n)
	{
		//选取左右孩子中较大的那个，默认为左孩子
		if ((data[child]<data[child + 1])
			&&(child+1<n))    //child+1<n防止出界
		{
			child++;
		}
		if (data[child] > data[parent])//比较孩子和父亲的大小，
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
void HeapInit(Heap* hp,HPDataType*data,int n)//堆的初始化
{
	assert(hp);
	int i = 0;
	hp->data = (HPDataType*)malloc(sizeof(HPDataType)*n);//开辟数组大小的字节
	hp->sz = n;
	hp->capacity = n;
	for ( i = 0; i < n; i++)//给堆的数组赋值
	{
		hp->data[i] = data[i];
	}
	for (i = (n - 2) / 2; i >= 0; i--)//找到非叶子的最后一个节点，把大的向上调，小的向下
	{
		AdjustDown(hp->data, hp->sz, i);//
	}

}
void HeapDestory(Heap* hp)//堆的销毁
{
	assert(hp);
	free(hp->data);
	hp->data = NULL; 
	hp->sz = hp->capacity = 0;
}
void AdjustUp(HPDataType*data, int n, int child)//向上调整法，在HeapPop()中让孩子和父亲比较大小,把小的向上调整
{
	assert(data);
	int parent = (child-1)/2;
	while (child > 0)
	{
		if (data[parent]<data[child])//当父亲小于孩子时，进行交换
		{
			Swap(&data[parent], &data[child]);
			child = parent;//改变孩子的大小
			parent = (child - 2) / 2;//改变父亲的大小

		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HPDataType x)//堆的插入
{
	assert(hp);
	if (hp->sz == hp->capacity)//当堆的大小等于容量的大小，就要扩容
	{
		hp->capacity *= 2;
		hp->data = (HPDataType*)realloc(hp->data,sizeof(HPDataType)*hp->capacity);//开辟空间
	}
	hp->data[hp->sz] = x;
	hp->sz++;//个数加1
	AdjustUp(hp->data, hp->sz,hp->sz-1);//向上调整法，把大的调上去，小的放下边
}
void HeapPop(Heap* hp)//堆的删除,把堆顶数据和最后一个数据交换，再把对顶数据向下调整
{
	assert(hp);
	Swap(&hp->data[0], &hp->data[hp->sz - 1]);
	HPDataType* cur = &hp->data[hp->sz - 1];
	hp->sz--;
	AdjustDown(hp->data, hp->sz, 0);
	return *cur;
}
HPDataType* HeapTop(Heap*hp)//获取堆顶的数据,
{
	assert(hp);
	return hp->data[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->sz;
}
int HeapEmpty(Heap* hp)//空为0，非空1
{
	return hp->sz == 0 ? 0 : 1;//三字符运算
}
void PrintHeap(Heap* hp)//打印函数
{
	assert(hp);
	for (int i = 0; i < hp->sz; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}
void HeapSort(Heap*hp)//冒泡泡排序
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hp->sz - 1; i++)
	{
		int flag = 0;//优化标记
		for (j = 0; j < hp->sz - i - 1; j++)//循环趟数
		{
			if (hp->data[j] < hp->data[j + 1])//比较次数
			{
				HPDataType tmp = hp->data[j];
				hp->data[j] = hp->data[j + 1];
				hp->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)//当里面没有交换时，说明交换完成
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