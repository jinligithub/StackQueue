#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* data;//������ݵ�����
	int sz;//�ѵ�����Ԫ�ظ���
	int capacity;//�ѵ�����
}Heap;


void HeapInit(Heap* hp);//�ѵĳ�ʼ��
void HeapDestory(Heap* hp);//�ѵ�����
void HeapPush(Heap* hp, HPDataType x);//�ѵĲ���
void HeapPop(Heap* hp);//�ѵ�ɾ��
HPDataType* HeapTop(Heap*hp);//��ȡ�Ѷ�������
int HeapSize(Heap* hp);//��ѵĴ�С
int HeapEmpty(Heap* hp);//�ж϶��Ƿ�Ϊ��
void HeapSort(Heap*hp);//�ѵ�ð������