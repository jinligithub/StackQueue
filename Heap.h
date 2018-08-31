#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* data;//存放数据的数组
	int sz;//堆的数组元素个数
	int capacity;//堆的容量
}Heap;


void HeapInit(Heap* hp);//堆的初始化
void HeapDestory(Heap* hp);//堆的销毁
void HeapPush(Heap* hp, HPDataType x);//堆的插入
void HeapPop(Heap* hp);//堆的删除
HPDataType* HeapTop(Heap*hp);//获取堆顶的数据
int HeapSize(Heap* hp);//求堆的大小
int HeapEmpty(Heap* hp);//判断堆是否为空
void HeapSort(Heap*hp);//堆的冒泡排序