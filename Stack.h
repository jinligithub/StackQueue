
#pragma once
#define MAX 100
#define DEFAULT_SZ 3

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>


//
//��̬ջ
//typedef int DataType;
//#define MAX 10
//typedef struct Stack
//{
//	DataType *data[MAX];
//	int top;//ջ��
//};

//typedef struct pos
//{
//	int _row;
//	int _col;
//}pos;

//typedef pos DataType;
typedef int DataType;

typedef struct Stack
{
	DataType*data;//ջ������
	int top;//ջ��
	int capacity;//����

}Stack;

void InitStack(Stack *ps);//��ʼ��ջ
void DistoryStack(Stack *ps);//����ջ

void StackPush(Stack*ps,DataType d);//��ջ
void StackPop(Stack *ps);//��ջ

DataType StackTop(Stack *ps);//����ջ����Ԫ��
int StackEmpty(Stack*ps);//ջ�Ƿ�Ϊ��
int StackSize(Stack *ps);//ջ�Ĵ�С
void PrintStack(Stack *ps);//��ӡջ

void test();
